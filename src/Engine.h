#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

class Engine {
public:
  Engine();
  ~Engine();
  void initGraphics();
  void loadTexture();
  SDL_Texture *texture_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;
  SDL_Window *window_ = nullptr;
  void renderBackground();

private:
  const int SCREEN_WIDTH_ = 1024;
  const int SCREEN_HEIGHT_ = 768;
};
