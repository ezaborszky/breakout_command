#pragma once

#include <utility>
#include <vector>
enum State { DIRT, WATER, ICE, FIRE };

struct CTransform {
  std::pair<float, float> position = {0, 0};
  std::pair<float, float> directionVector = {0, 0};
  float speed = 0;
  std::pair<float, float> size = {64, 64};
  int zIndex = 1;
};

struct CState {
  State state = DIRT;
  int maxHP = 3;
  int HP = 3;
};
