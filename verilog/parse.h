#include <vector>
#include <string>
#include <map>

// Usage:
//
// Parse* p = parse(tokenize("..."));
// if (!p->ok()) { handle error }

enum Kind {
  PROGRAM, STATEMENT, INCLUDE, STRING, UNIT, VERILOG, SIM, DECL, USE, CONN, WIRE, D, F, INPUT, OUTPUT,
};

std::string kind_name(Kind kind) {
   std::map<Kind, std::string> kind_name;
    kind_name[PROGRAM] = "PROGRAM";
    kind_name[STATEMENT] = "STATEMENT";
    kind_name[INCLUDE] = "INCLUDE";
    kind_name[STRING] = "STRING";
    kind_name[UNIT] = "UNIT";
    kind_name[VERILOG] = "VERILOG";
    kind_name[SIM] = "SIM";
    kind_name[DECL] = "DECL";
    kind_name[USE] = "USE";
    kind_name[CONN] = "CONN";
    kind_name[D] = "D";
    kind_name[F] = "F";
    kind_name[INPUT] = "INPUT";
    kind_name[OUTPUT] = "OUTPUT";
  return kind_name[kind];
}

class Parse {
 public:
  Parse(Kind kind) : kind_(kind), error_(false) {}
  Parse(std::string s) : kind_(STRING), payload_(s) {}
  Kind kind() const { return kind_; }
  ~Parse() {
    for ( Parse* child : children_ ) {
      delete child;
    }
  }

  void add(Parse* parse) { children_.push_back(parse); }
  std::vector<Parse*>& children() { return children_; }

  void set_end(int end) { end_ = end; }
  int end() const { return end_; }
  
  void set_payload(std::string payload) { payload_ = payload; }
  std::string payload() const { return payload_; }
  
  void error(std::string message, int offset) {
    error_ = true;
    error_message_ = message;
    error_offset_ = offset;
  }
  
  Parse* bad(Parse* p) {
    error_ = true;
    add(p);
    return this;
  }
  
  bool ok() const { return !error_; }
  std::string error_message() const { return error_message_; }
  int error_offset() const { return error_offset_; }
  
  std::string debug(int indent = 0) {
    if (error_message_.size() > 0) {
      return error_message_ + " @ " + std::to_string(error_offset_);
    }
    std::string result = std::string(2*indent, ' ') + kind_name(kind_);
    if (kind_ == STRING) { result += " "; result += payload_ + "\n"; return result; }
    result += "\n";
    for (int i = 0; i < children_.size(); ++i) {
      result += children_[i]->debug(indent + 2);
    }
    return result;
  }

 private:
  Kind kind_;
  std::vector<Parse*> children_;
  int end_;
  std::string payload_;
  bool error_;
  std::string error_message_;
  int error_offset_;
};

std::vector<std::string> tokenize(std::string s) {
  std::vector<std::string> v;
  std::string curr;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
      if (curr.size() > 0) v.push_back(curr);
      curr = "";
      continue;
    }
    if (s[i] == ',' || s[i] == ';' || s[i] == '(' || s[i] == '{' || s[i] == ')' || s[i] == '}' || s[i] == ':') {
      if (curr.size() > 0) v.push_back(curr);
      v.push_back(std::string(1, s[i]));
      curr = "";
      continue;
    }
    curr += s[i];
  }
  if (curr.size() > 0) v.push_back(curr);
  return v;
}

Parse* parse(std::vector<std::string> tokens, int offset = 0, Kind kind = PROGRAM) {
  Parse* result = new Parse(kind);
  if (kind == PROGRAM) {
    while (offset < tokens.size()) {
      if (tokens[offset] == "include") {
        Parse* p = parse(tokens, offset+1, INCLUDE);
        if (!p->ok()) return result->bad(p);
        result->add(p);
        offset = p->end();
        continue;
      }
      if (tokens[offset] == "unit") {
        Parse* p = parse(tokens, offset+1, UNIT);
        if (!p->ok()) return result->bad(p);
        result->add(p);
        offset = p->end();
        continue;
      }
      if (tokens[offset] == "verilog") {
        Parse* p = parse(tokens, offset+1, VERILOG);
        if (!p->ok()) return result->bad(p);
        result->add(p);
        offset = p->end();
        continue;
      }
      result->error("Bad token in PROGRAM", offset);
      return result;
    }
    result->set_end(offset);
    return result;
  }
  if (kind == INCLUDE) {
    if (tokens[offset+1] != ";") {
      result->error("Missing semicolon in INCLUDE", offset+1);
      return result;
    }
    result->add(new Parse(tokens[offset]));
    result->set_end(offset+2);
    return result;
  }
  if (kind == VERILOG) {
    Parse* decl = parse(tokens, offset, DECL);
    if (!decl->ok()) return result->bad(decl);
    result->add(decl);
    offset = decl->end();
    if (tokens[offset] != "{") {
      result->error("Missing { in VERILOG after DECL", offset);
      return result;
    }
    ++offset;
    int depth = 1;
    while (offset < tokens.size()) {
      if (tokens[offset] == "{") ++depth;
      if (tokens[offset] == "}") --depth;
      if (depth == 0) break;
      result->add(new Parse(tokens[offset]));
      ++offset;
    }
    if (depth > 0) {
      result->error("Unexpected EOF in VERILOG", offset);
      return result;
    }
    ++offset;
    result->set_end(offset);
    return result;
  }
  if (kind == UNIT) {
    Parse* decl = parse(tokens, offset, DECL);
    if (!decl->ok()) return result->bad(decl);
    result->add(decl);
    offset = decl->end();
    if (tokens[offset] != "{") {
      result->error("Missing { in UNIT after DECL", offset);
      return result;
    }
    ++offset;
    while (offset < tokens.size() && tokens[offset] != "}") {
      if (tokens[offset] == "use") {
        Parse* use = parse(tokens, offset+1, USE);
        if (!use->ok()) return result->bad(use);
        result->add(use);
        offset = use->end();
        continue;
      }
      Parse* conn = parse(tokens, offset, CONN);
      if (!conn->ok()) return result->bad(conn);
      result->add(conn);
      offset = conn->end();
    }
    result->set_end(offset+1);
    return result;
  }
  if (kind == DECL) {
    result->add(new Parse(tokens[offset]));
    if (tokens[offset+1] != "(") {
      result->error("Missing ( in DECL", offset+1);
      return result;
    }
    if (tokens[offset+2] != "in") {
      result->error("Missing 'in' in DECL", offset+2);
      return result;
    }
    int arg = 3;
    Parse* input = new Parse(INPUT);
    result->add(input);
    while (tokens[offset+arg] != ",") {
      if (tokens[offset+arg] == ")") {
        result->error("Missing ',' in DECL", offset+arg);
        return result;
      }
      input->add(new Parse(tokens[offset+arg]));
      ++arg;
    }
    ++arg;
    if (tokens[offset+arg] != "out") {
      result->error("Missing out in DECL", offset+arg);
      return result;
    }
    ++arg;
    Parse* output = new Parse(OUTPUT);
    result->add(output);
    while (tokens[offset+arg] != ")") {
      output->add(new Parse(tokens[offset+arg]));
      ++arg;
    }
    result->set_end(offset+arg+1);
    return result;
  }
  if (kind == USE) {
    if (tokens[offset+2] != ";") {
      result->error("Missing ; in USE", offset+2);
      return result;
    }
    result->add(new Parse(tokens[offset]));
    result->add(new Parse(tokens[offset+1]));
    result->set_end(offset+3);
    return result;
  }
  if (kind == CONN) {
    Parse* left = parse(tokens, offset, WIRE);
    if (!left->ok()) return result->bad(left);
    result->add(left);
    offset = left->end();
    if (offset >= tokens.size()) {
      result->error("Unexpected EOF in CONN", offset);
      return result;
    }
    if (tokens[offset] != "->") {
      result->error("Missing -> in CONN", offset);
      return result;
    }
    Parse* right = parse(tokens, offset+1, WIRE);
    if (!right->ok()) return result->bad(right);
    result->add(right);
    if (right->end() < tokens.size() && tokens[right->end()] != ";") {
      result->error("Missing ; in CONN", right->end());
      return result;
    }
    result->set_end(right->end()+1);
    return result;
  }
  if (kind == WIRE) {
    if (offset >= tokens.size() - 1) {
      result->error("Unexpected EOF in WIRE", offset);
      return result;
    }
    result->add(new Parse(tokens[offset]));
    if (tokens[offset+1] != ".") {
      result->set_end(offset+1);
      return result;
    }
    result->add(new Parse(tokens[offset+2]));
    result->set_end(offset+3);
    return result;
  }
  result->error(std::string("Could not parse requested kind ") + kind_name(kind), offset);
  return result;
}
