#pragma once
#include "EntityManager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <memory>

enum Sprites {
  PADDLE_LEFT = 5,
  PADDLE_MIDDLE = 6,
  PADDLE_RIGHT = 7,
  BLOCK_FULL = 0,
  BLOCK_DAMAGED = 1,
  BLOCK_BADLY_DAMAGED = 2,
  YELLOW_STAR = 10,
  WHITE_STAR = 11,
  SMALL_STAR = 12,
  GALAXY_1 = 13,
  GALAXY_2 = 14,
  PLANET_1 = 15,
  PLANET_2 = 16,
  BALL_1 = 17
};

class Engine {
public:
  Engine();
  ~Engine();
  void initGraphics();
  void loadTexture();
  SDL_Texture *texture_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;
  SDL_Window *window_ = nullptr;
  std::pair<int, int> getScreenDimensions();

  // rendering
  void clear();
  void renderEntities(EntityVec &entities);
  void renderPlayer(std::shared_ptr<Entity> player);
  void render(EntityVec &entities, std::shared_ptr<Entity> player);

private:
  const int SCREEN_WIDTH_ = 1024;
  const int SCREEN_HEIGHT_ = 768;
};
