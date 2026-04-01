#pragma once

#include <utility>
#include <vector>
enum Sprites { DIRT, WATER, ICE, FIRE };

struct CTransform {
  std::pair<float, float> position = {0, 0};
  std::pair<float, float> directionVector = {0, 0};
  float speed = 0;
};

struct CState {
  Sprites state = DIRT;
};
