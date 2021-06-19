#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include <vector>

#include "ir.h"

using namespace std;

class CodeGenerator {
 public:
  virtual ~CodeGenerator() {}
  
  const vector<string>& code() const { return code_; }
  
  virtual CodeGenerator* function(Node* fundef) = 0;
  
 protected:
  vector<string> code_;
};

#endif
