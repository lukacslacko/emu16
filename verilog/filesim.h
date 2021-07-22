#include "sim.h"
#include <stdio.h>

class FileSim : public sim {
  public:
  std::string load(std::string filename) override {
    FILE* f = fopen(filename.c_str(), "r");
	  if (!f) {
		  printf("Cannot open '%s'\n", filename.c_str());
		  return "";
	  }
    std::string result;
  	int len = 0;
	  char* line = NULL;
	  while (getline(&line, &len, f) != -1) {
		  result += line;
      result += " ";
	  }
	  fclose(f);
	  if (line) free(line);
    return result;
  }
};
