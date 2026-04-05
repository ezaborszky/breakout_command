#include "Game.h"
#include <libgen.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  chdir(dirname(argv[0]));
  Game g;
  g.run();
  return 0;
}
