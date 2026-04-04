#include "Utility.h"
#include <cmath>
#include <random>

int generateRandom(int min, int max) {
  static std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(min, max);
  return dist(rng);
}

SDL_Rect calcTilePos(int tile) {
  int x = tile % 5;
  int y = tile / 5;
  x *= 32;
  y *= 32;

  SDL_Rect crop = {x, y, 32, 32};
  return crop;
}

float angleFromVector(float dx, float dy) {
  float angle = std::atan2(dy, dx);
  float angleDegree = angle * (180.0f / M_PI);
  return angleDegree + 90;
}

double calculateDistance(std::pair<int, int> pointA,
                         std::pair<int, int> pointB) {
  int a = (pointA.first - pointB.first);
  int b = (pointA.second - pointB.second);
  return std::sqrt(a * a + b * b);
}
