#include "Utility.h"
#include <cmath>
#include <random>
#include <unistd.h>

int generateRandom(int min, int max) {
  static std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(min, max);
  return dist(rng);
}

SDL_Rect calcTilePos(int tile) {
  int x = tile % 5;
  int y = tile / 5;
  x *= 64;
  y *= 64;

  SDL_Rect crop = {x, y, 64, 64};
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

bool circleRectangleCollision(boundingBox box, int cx, int cy, int r) {
  bool collision = false;
  int closeX, closeY;
  closeX = cx;
  closeY = cy;
  if (cx > box.x + box.w) {
    closeX = box.x + box.w;
  } else if (cx < box.x) {
    closeX = box.x;
  }

  if (cy > box.y + box.h) {
    closeY = box.y + box.h;
  } else if (cy < box.y) {
    closeY = box.y;
  }

  double distance = calculateDistance({box.x, box.y}, {cx, cy});
  collision = (distance <= r);
  return collision;
}
