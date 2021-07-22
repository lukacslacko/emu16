#include "filesim.h"

int main(int argc, char** argv) {
  FileSim fs;
  if (!fs.init(argv[1])) {
    printf("Init :(\n");
  }
  printf("\n%s\n", fs.debug().c_str());
}
