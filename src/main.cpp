#include "Game.h"
#include <iostream>
#include <libgen.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  chdir(dirname(argv[0]));
  std::cout << "Hello, világ!\n";
  Game g;
  g.run();
  return 0;
}
