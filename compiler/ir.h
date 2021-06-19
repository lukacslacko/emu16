#ifndef IR_H
#define IR_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

class Node {
 public:
  Node() : kind("undefined") {}
  explicit Node(string k) : kind(k) {}
  Node(string k, vector<Node*> a) : kind(k), args(a) {}
  string kind;
  vector<Node*> args;
  
  string pre(int level) const { return string(level*2, ' '); }
  
  bool simple() const {
    if (args.size() == 0) return true;
    if (args.size() > 1) return false;
    return args[0]->simple();
  }
    
  string debug(int level=0) const {
    if (args.size() == 0) return pre(level) + kind;
    if (args.size() == 1 && args[0]->simple()) return pre(level) + kind + "(" + args[0]->debug() + ")";
    string s = pre(level) + kind + "(\n";
    for (const auto& arg : args) {
      s += arg->debug(level+1) + "\n";
    }
    s += pre(level) + ")";
    return s;
  }
};

vector<Node*> catnode(vector<Node*> vec, Node* n);
#endif
