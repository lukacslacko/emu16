#ifndef EMU16_H
#define EMU16_H

#include "codegen.h"

class EMU16 : public CodeGenerator {
 public:
  CodeGenerator* function(Node* fundef) override { 
    return new EMU16;
  } 
};

#endif
