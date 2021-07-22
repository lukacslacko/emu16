#include "filesim.h"

int main(int argc, char** argv) {
  FileSim fs;
  if (!fs.init(argv[1])) {
    printf("Init :(\n");
  }
  printf("\n%s\n", fs.debug().c_str());
  auto tokens = fs.gettokens();
  for (int i = 0; i < tokens.size(); ++i) {
    printf("%04d '%s'\n", i, tokens[i].c_str());
  }
}
