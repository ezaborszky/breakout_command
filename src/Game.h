#pragma once
#include "Engine.h"
#include <memory>

class Game {
public:
  Game() : engine_(std::make_unique<Engine>()) {
    calculateMaxTileDimensions();
  };
  ~Game() {};
  void mainLoop();
  void run();
  SDL_Event e_;
  void calculateMaxTileDimensions();

private:
  std::unique_ptr<Engine> engine_ = nullptr;
  int maxTileWidth_ = 0;
  int maxTileHeight_ = 0;
};
