#pragma once

#include <SDL2/SDL_pixels.h>
#include <utility>
#include <vector>

enum State { DIRT, WATER, ICE, FIRE };

struct boundingBox {
  float x = 0;
  float y = 0;
  float w = 0;
  float h = 0;
};

struct CTransform {
  std::pair<float, float> position = {0, 0};
  std::pair<float, float> originalPosition = {0, 0};
  std::pair<float, float> directionVector = {0, 0};
  float speed = 0;
  std::pair<float, float> size = {64, 64};
  int zIndex = 1;
  boundingBox boundingbox;
};

struct CState {
  State state = DIRT;
  int maxHP = 3;
  int HP = 3;
  int width = 1;
};

struct CGraphics {
  std::vector<int> possibleSprites = {};
  int currentSprite = 0;
  SDL_Colour tint = {0xFF, 0xFF, 0xFF, 0xFF};
};
