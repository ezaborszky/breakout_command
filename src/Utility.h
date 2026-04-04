#pragma once
#include <SDL2/SDL.h>

int generateRandom(int min, int max);
SDL_Rect calcTilePos(int tile);
float angleFromVector(float dx, float dy);
double calculateDistance(std::pair<int, int> pointA,
                         std::pair<int, int> pointB);
