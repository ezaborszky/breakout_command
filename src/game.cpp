#include "Game.h"
#include "Engine.h"
#include <SDL2/SDL_events.h>

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
