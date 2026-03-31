#pragma once
#include "Engine.h"
#include <memory>

class Game {
public:
  Game() : engine_(std::make_unique<Engine>()) {};
  ~Game() {};
  void mainLoop();
  void run();
  SDL_Event e_;

private:
  std::unique_ptr<Engine> engine_ = nullptr;
};
