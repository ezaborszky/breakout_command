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
