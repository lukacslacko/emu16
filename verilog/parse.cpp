#include "sim.h"

int main(int argc, char** argv) {
  FileSim fs;
  if (!fs.init(argv[1])) {
    printf("Init :(\n");
    exit(1);
  }
  printf("Success\n%s\n", fs.debug().c_str());
}
