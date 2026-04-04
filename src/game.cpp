#include "Game.h"
#include "Engine.h"
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

  engine_->renderBackground();
}

void Game::run() { mainLoop(); }

void Game::calculateMaxTileDimensions() {
  int screen_width = engine_->getScreenDimensions().first;
  int screen_height = engine_->getScreenDimensions().second;
  maxTileHeight_ = screen_height / 16;
  maxTileWidth_ = screen_width / 16;
}

void Game::generateBackGround(int frequency) {
  for (int i = 0; i < frequency; ++i) {
    // decide if star or other object;
    int seed = generateRandom(1, 10);
    if (seed < 10) {
      int starType = generateRandom(0, 2);
      std::string tag = "";
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
  }
}
