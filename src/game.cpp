#include "Game.h"
#include "Engine.h"
#include "Entity.h"
#include "EntityManager.h"
#include "Utility.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <string>

void Game::mainLoop() {
  bool windowOpen = true;
  while (windowOpen) {
    while (SDL_PollEvent(&e_) != 0) {
      if (e_.type == SDL_QUIT) {
        windowOpen = false;
      }
    }
    paralax();
    entityManager_.updateEntities();
    engine_.render(entityManager_.getEntities());
  }
}

void Game::run() {
  generateBackGround(200);
  mainLoop();
}

void Game::calculateMaxTileDimensions() {
  int screen_width = engine_.getScreenDimensions().first;
  int screen_height = engine_.getScreenDimensions().second;
  maxTileHeight_ = screen_height / 16;
  maxTileWidth_ = screen_width / 16;
}

void Game::generateBackGround(int frequency) {
  for (int i = 0; i < frequency; ++i) {
    // decide if star or other object;
    int seed = generateRandom(1, 10);
    std::string tag = "default";
    Sprites sprite = SMALL_STAR;
    // under ten it is a star
    if (seed < 10) {
      tag = "star";
      int starType = generateRandom(0, 2);

      switch (starType) {
      case 0:
        sprite = Sprites::SMALL_STAR;
        break;
      case 1:
        sprite = Sprites::WHITE_STAR;
        break;
      case 2:
        sprite = Sprites::YELLOW_STAR;
        break;
      default:

        break;
      }
    } else {
      int i = generateRandom(0, 3);
      switch (i) {
      case 0:
        sprite = Sprites::GALAXY_1;
        tag = "galaxy";
        break;
      case 1:
        sprite = Sprites::GALAXY_2;
        tag = "galaxy";
        break;
      case 2:
        sprite = Sprites::PLANET_1;
        tag = "planet";
        break;
      case 3:
        sprite = Sprites::PLANET_2;
        tag = "planet";
      default:

        break;
      }
    }

    // once the type is decided entity gets createEntity
    auto e = entityManager_.createEntity(tag, BACKGROUND);
    e->transform_ = std::make_shared<CTransform>();
    e->state_ = std::make_shared<CState>();
    e->graphics_ = std::make_shared<CGraphics>();
    e->graphics_->possibleSprites = {sprite};
    if (seed < 10)
      e->setSize(1.f / (float)seed);
    int x = generateRandom(0, engine_.getScreenDimensions().first);
    int y = generateRandom(0, engine_.getScreenDimensions().second);
    e->setPosition(x, y);
    e->setOriginalPosition(x, y);
    if (tag == "planet") {
      e->setZIndex(-1 * (generateRandom(1, 2)));
    } else if (tag == "star") {
      e->setZIndex(-1 * (generateRandom(3, 4)));
    } else {
      e->setZIndex(-1 * (generateRandom(6, 9)));
    }
  }
  entityManager_.updateEntities();
}

void Game::paralax() {
  int x, y;
  SDL_GetMouseState(&x, &y);
  int dx = x - engine_.getScreenDimensions().first / 2;
  float offsetX =
      (float)dx / (float)(engine_.getScreenDimensions().first / 2.f);
  int offset = 30 * offsetX;
  for (auto &e : entityManager_.getEntities()) {
    if (e->getType() == BACKGROUND) {
      int paralaxOffset = (offset / (e->getZIndex()));
      paralaxOffset = std::clamp(paralaxOffset, -500, 500);
      e->setPosition(e->getOriginalPosition().first + paralaxOffset,
                     e->getOriginalPosition().second);
    }
  }
}

void Game::spawnPlayer() {
  auto player = entityManager_.createEntity("player", EntityType::PLAYER);
  player->transform_ = std::make_shared<CTransform>();
  player->state_ = std::make_shared<CState>();
  player->graphics_ = std::make_shared<CGraphics>();
}
