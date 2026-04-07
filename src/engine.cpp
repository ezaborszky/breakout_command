#include "Engine.h"
#include "Entity.h"
#include "EntityManager.h"
#include "Utility.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <memory>

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

void Engine::clear() {
  SDL_RenderClear(renderer_);
  SDL_Rect fillRect = {0, 0, SCREEN_WIDTH_, SCREEN_HEIGHT_};
  SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0xFF);
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

void Engine::renderEntities(EntityVec &entities) {
  for (auto a : entities) {
    if (a->getTag() == "player")
      continue;
    SDL_Rect crop =
        calcTilePos(a->graphics_->possibleSprites[a->graphics_->currentSprite]);
    SDL_Rect pos = a->getDimensions();
    SDL_RenderCopy(renderer_, texture_, &crop, &pos);
  }
}

void Engine::renderPlayer(std::shared_ptr<Entity> player) {
  for (int i = 0; i < player->state_->width; ++i) {
    int last = player->state_->width - 1;
    // set sprite to corresponding part of paddle
    if (i == 0) {
      player->graphics_->currentSprite = 0;
    } else if (i == player->state_->width - 1) {
      player->graphics_->currentSprite = 2;
    } else {
      player->graphics_->currentSprite = 1;
    }
    int spriteWidth = player->transform_->size.first;
    SDL_Rect pos = player->getDimensions();
    pos.x += spriteWidth * i;
    SDL_Rect crop = calcTilePos(
        player->graphics_->possibleSprites[player->graphics_->currentSprite]);
    SDL_RenderCopy(renderer_, texture_, &crop, &pos);
  }
}

void Engine::render(EntityVec &entities, std::shared_ptr<Entity> player) {
  clear();
  renderEntities(entities);
  renderPlayer(player);
  SDL_RenderPresent(renderer_);
}
