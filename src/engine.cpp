#include "Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

void Engine::initGraphics() {
  window_ = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH_,
                             SCREEN_HEIGHT_, SDL_WINDOW_SHOWN);
  if (window_ == nullptr) {
    printf("Window creation failed. %s\n", SDL_GetError());
  } else {
    renderer_ = SDL_CreateRenderer(
        window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer_ == nullptr) {
      printf("Renderer creation failed. %s\n", SDL_GetError());
    } else {
      SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
      int imgFlags = IMG_INIT_PNG;
      if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("Failed to start SDL Image %s\n", IMG_GetError());
      }
    }
  }
}

void Engine::loadTexture() {
  SDL_Surface *loadedSurface = IMG_Load("./media/sprites.png");
  if (loadedSurface == nullptr) {
    printf("Could not load media %s\n", IMG_GetError());

  } else {
    SDL_SetColorKey(loadedSurface, SDL_TRUE,
                    SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
    texture_ = SDL_CreateTextureFromSurface(renderer_, loadedSurface);
  }
  SDL_FreeSurface(loadedSurface);
}

void Engine::renderBackground() {
  SDL_RenderClear(renderer_);
  SDL_Rect fillRect = {0, 0, SCREEN_WIDTH_, SCREEN_HEIGHT_};
  SDL_SetRenderDrawColor(renderer_, 0xFF, 0x00, 0x00, 0xFF);
  SDL_RenderFillRect(renderer_, &fillRect);
}

Engine::Engine() {
  initGraphics();
  loadTexture();
};

Engine::~Engine() {
  SDL_DestroyTexture(texture_);
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  texture_ = nullptr;
  window_ = nullptr;
  renderer_ = nullptr;
  IMG_Quit();
  SDL_Quit();
}

std::pair<int, int> Engine::getScreenDimensions() {
  return {SCREEN_WIDTH_, SCREEN_HEIGHT_};
}
