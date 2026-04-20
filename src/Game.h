#pragma once
#include "Engine.h"
#include "EntityManager.h"
#include <SDL2/SDL_stdinc.h>
#include <cstdint>
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
  void playerMovement();
  std::pair<int, int> measureSpeed(std::shared_ptr<Entity> entity, Uint32 time);
  void spawnBall();

private:
  Engine engine_;
  EntityManager entityManager_;
  int maxTileWidth_ = 0;
  int maxTileHeight_ = 0;
  std::vector<std::vector<State>> tilesMap_;
  Uint32 velocityLastTick = 0;
};
