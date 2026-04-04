#pragma once
#include "Engine.h"
#include "EntityManager.h"
#include <memory>

class Game {
public:
  Game() { calculateMaxTileDimensions(); };
  ~Game() {};
  void mainLoop();
  void run();
  SDL_Event e_;
  void calculateMaxTileDimensions();
  void generateBackGround(int frequency);

private:
  Engine engine_;
  EntityManager entityManager_;
  int maxTileWidth_ = 0;
  int maxTileHeight_ = 0;
};
