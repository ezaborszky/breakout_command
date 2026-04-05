#pragma once
#include "Engine.h"
#include "EntityManager.h"
#include <memory>
#include <vector>

class Game {
public:
  Game() { calculateMaxTileDimensions(); };
  ~Game() {};
  void mainLoop();
  void run();
  SDL_Event e_;
  void calculateMaxTileDimensions();
  void generateBackGround(int frequency);
  void paralax();
  void spawnPlayer();

private:
  Engine engine_;
  EntityManager entityManager_;
  int maxTileWidth_ = 0;
  int maxTileHeight_ = 0;
  std::vector<std::vector<State>> tilesMap_;
};
