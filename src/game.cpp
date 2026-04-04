#include "Game.h"
#include "Engine.h"
#include "EntityManager.h"
#include "Utility.h"
#include <SDL2/SDL_events.h>
#include <string>

void Game::mainLoop() {
  bool windowOpen = true;
  while (windowOpen) {
    while (SDL_PollEvent(&e_) != 0) {
      if (e_.type == SDL_QUIT) {
        windowOpen = false;
      }
    }
  }

  engine_.render(entityManager_.getEntities());
}

void Game::run() { mainLoop(); }

void Game::calculateMaxTileDimensions() {
  int screen_width = engine_.getScreenDimensions().first;
  int screen_height = engine_.getScreenDimensions().second;
  maxTileHeight_ = screen_height / 16;
  maxTileWidth_ = screen_width / 16;
}

void Game::generateBackGround(int frequency) {
  for (int i = 0; i < frequency; ++i) {
    // decide if star or other object;
    int seed = generateRandom(1, 10);
    std::string tag = "";
    // under ten it is a star
    if (seed < 10) {
      int starType = generateRandom(0, 2);

      switch (starType) {
      case 0:
        tag = "star1";
        break;
      case 1:
        tag = "star2";
        break;
      case 2:
        tag = "star3";
        break;
      default:

        break;
      }
    }

    // once the type is decided entity gets createEntity
    auto e = entityManager_.createEntity(tag, BACKGROUND);
    float size = (float)seed;
    e->setSize(1 / size);
    int x = generateRandom(0, engine_.getScreenDimensions().first);
    int y = generateRandom(0, engine_.getScreenDimensions().second);
    e->setPosition(x, y);
    e->setZIndex(-1);
  }
}
