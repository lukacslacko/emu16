#include "parse.h"
#include "filesim.h"
#include <map>

struct Module {
  std::vector<std::string> inputs, outputs;
};

std::map<std::string, Module> modules;

std::string verilog(Parse* p);

std::string decl_header(Parse* p) {
  std::string name = p->children()[0]->payload();
  Module m;
  std::string result = "module m_";
  result += name;
  result += "(";
  auto inputs = p->children()[1]->children();
  auto outputs = p->children()[2]->children();
  for (int i = 0; i < inputs.size(); ++i) {
    auto input = inputs[i]->payload();
    m.inputs.push_back(input);
    result += input;
    if (i < inputs.size() + outputs.size() - 1) {
      result += ", ";
    }
  }
  for (int i = 0; i < outputs.size(); ++i) {
    auto output = outputs[i]->payload();
    m.outputs.push_back(output);
    result += output;
    if (i < outputs.size() - 1) {
      result += ", ";
    }
  }
  result += ");\n";
  for (int i = 0; i < inputs.size(); ++i) {
    result += "input ";
    result += inputs[i]->payload();
    result += ";\n";
  }
  for (int i = 0; i < outputs.size(); ++i) {
    result += "output ";
    result += outputs[i]->payload();
    result += ";\n";
    result += "reg ";
    result += outputs[i]->payload();
    result += ";\n";
  } 
  modules[name] = m;
  return result;
}

std::string verilog_module(Parse* p) {
  std::string result = decl_header(p->children()[0]);
  result += "  ";
  for (int i = 1; i < p->children().size(); ++i) {
    result += p->children()[i];
    if (p->children()[i] == ";") {
      result += "\n  ";
    } else {
      result += " ";
    }
  }
  result += "endmodule\n";
  return result;
}

std::string wire(Parse* w) {
  if (w->children().size() == 1) return w->children()[0]->payload();
  std::string result = w->children()[0]->payload();
  result += "_";
  result += w->children()[1]->payload();
  return result;
}

std::string unit_module(Parse* p) {
  std::string result = decl_header(p->children()[0]);
  for (int i = 1; i < p->children().size(); ++i) {
    Parse* c = p->children()[i];
    if (c->kind() == CONN) {
      auto from = wire(c->children()[0]);
      auto to = wire(c->children()[1]);
      result += "always @(";
      result += from;
      result += ") ";
      result += to;
      result += " <= ";
      result += from;
      result += ";\n";
    }
    if (c->kind() == USE) {
      auto name = c->children()[0]->payload();
      auto type = c->children()[1]->payload();
      result += "m_";
      result += type;
      result += " ";
      result += name;
      result += "(";
      Module m = modules[type];
      for (int i = 0; i < m.inputs.size(); ++i) {
        auto w = m.inputs[i];
        result += ".";
        result += w;
        result += "(";
        result += name;
        result += "_";
        result += w;
        result += ")";
        if (i < m.inputs.size() + m.outputs.size() - 1) {
          result += ", ";
        }
      }
      for (int i = 0; i < m.outputs.size(); ++i) {
        auto w = m.outputs[i];
        result += ".";
        result += w;
        result += "(";
        result += name;
        result += "_";
        result += w;
        result += ")";
        if (i < m.outputs.size() - 1) {
          result += ", ";
        }
      }
      result += ");\n";
      for (auto i : m.inputs.size()) {
        result += "reg ";
        result += name;
        result += "_";
        result += i;
        result += ";\n";
      }
      for (auto i : m.outputs.size()) {
        result += "wire ";
        result += name;
        result += "_";
        result += i;
        result += ";\n";
      }
    }
  }
  return result;
}

std::string verilog(Parse* p) {
  std::string result;
  for (Parse* c : p->children()) {
    if (c->kind() == VERILOG) {
      result += verilog_module(c);
    }
    if (c->kind() == UNIT) {
      result += unit_module(c);
    }
  }
  return result;
}

int main(int argc, char** argv) {
  FileSim fs;
  if (!fs.init(argv[1])) {
    printf("Init :(\n");
  }
  printf("%s\n", verilog(parse(fs.tokens())).c_str());
}
