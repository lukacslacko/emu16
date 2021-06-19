#ifndef COMPILER_H
#define COMPILER_H
#include "ir.h"
#include "codegen.h"

class Compiler {
 private:
  struct Variable {
    Compiler* c;
    int d_offset;
  };
  
  struct Function {
    Compiler* c;
    vector<string> code;
  };
  
 public:
  Compiler(Node* node, Compiler* parent, CodeGenerator* codegen) 
      : node_(node), parent_(parent), codegen_(codegen) {}

  bool compile() {
    if (node_->kind == "program") return program();
    if (node_->kind == "unit") return unit();
    if (node_->kind == "fundef") return fundef();
    if (node_->kind == "vardecl") return vardecl();
    if (node_->kind == "statements") return statements();
    if (node_->kind == "vardecl_init") return vardecl_init();
    if (node_->kind == "varset") return varset();
    if (node_->kind == "number") return true;
    if (node_->kind == "return") return ret();
//    if (node_->kind == "funcall") return funcall();
    if (node_->kind == "varref") return varref();
    cerr << "Cannot compile " << node_->kind << endl;
    return false;
  }
  
  ~Compiler() {
    for (Compiler* c : subcomps_) {
      delete c;
    }
  }
  
 private:
 
  Compiler* n(Node* arg, Compiler* parent = nullptr, CodeGenerator* codegen = nullptr) {
    if (parent == nullptr) parent = this;
    if (codegen == nullptr) codegen = codegen_;
    Compiler* c = new Compiler(arg, parent, codegen);
    subcomps_.push_back(c);
    return c;
  }
 
  Compiler* block() {
    if (node_->kind == "statements") return this;
    if (!parent_) {
      cerr << "No block parent found" << endl;
      return nullptr;
    }
    return parent_->block();
  }
  
  void add_fun(string name, Compiler* comp) {
    if (parent_) parent_->add_fun(name, comp);
    else funs_[name] = {comp, {}};
  }
  
  bool statements() {
    for (auto arg : node_->args) {
      Compiler* c = n(arg);
      if (!c->compile()) {
        return false;
      }
    }
    return true;
  }
  
  bool ret() {
    Compiler* c = n(node_->args[0]);
    return c->compile();
  }
 
  bool fundef() {
    string name = node_->args[1]->args[0]->kind;
    if (find_fun(name)) {
      cerr << "Function already defined: " << name << endl;
      return false;
    }
    add_fun(name, this);
    CodeGenerator* fngen = codegen_->function(node_);
    Compiler* c = n(node_->args[3], this, fngen);
    if (!c->compile()) return false;
    
    return true;
  }
  
  bool varset() {
    Compiler* c = n(node_->args[1]);
    return c->compile();
  }
  
  bool vardecl() {
    if (!parent_) {
      cerr << "Cannot declare a variable here" << endl;
      return false;
    }
    string name = node_->args[1]->args[0]->kind;
    if (block()->vars_[name].c) {
      cerr << "Variable already declared: " << name << endl;
      return false;
    }
    block()->vars_[name] = {this, -1};
    // codegen_->vardecl(name, node_->args[0]);
    return true;
  }
  
  bool varref() {
    if (!parent_) {
      cerr << "Cannot reference a variable here" << endl;
      return false;
    }
    string name = node_->args[0]->args[0]->kind;
    if (!find_var(name)) {
      cerr << "Unknown variable " << name << endl;
      return false;
    }
    return true;
  }
  
  bool vardecl_init() {
    Compiler* decl = n(node_->args[0], parent_);
    Compiler* expr = n(node_->args[1], parent_);
    return decl->compile() && expr->compile();
  }
  
  bool program() {
    for (auto p : node_->args) {
      Compiler* c = n(p);
      if (!c->compile()) return false;
    }
    return true;
  }
  
  bool unit() {
    Compiler* c = n(node_->args[0]);
    return c->compile();
  }
 
  Variable* find_var(string name) {
    if (vars_[name].c) return &vars_[name];
    if (parent_) return parent_->find_var(name);
    return nullptr;
  }

  Function* find_fun(string name) {
    if (funs_[name].c) return &funs_[name];
    if (parent_) return parent_->find_fun(name);
    return nullptr;
  }
 
  Node* node_;
  Compiler* parent_;
  map<string, Function> funs_;
  map<string, Variable> vars_;
  CodeGenerator* codegen_;
  vector<Compiler*> subcomps_;
};
#endif
