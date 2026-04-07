#pragma once
#include "Component.h"
#include <SDL2/SDL.h>

int generateRandom(int min, int max);
SDL_Rect calcTilePos(int tile);
float angleFromVector(float dx, float dy);
double calculateDistance(std::pair<int, int> pointA,
                         std::pair<int, int> pointB);
bool circleRectangleCollision(boundingBox box, int cx, int cy, int r);
