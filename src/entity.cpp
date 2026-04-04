#include "Entity.h"
#include <SDL2/SDL_rect.h>
#include <utility>

void Entity::setPosition(float x, float y) { transform_->position = {x, y}; }

void Entity::setDirection(float x, float y) {
  transform_->directionVector = {x, y};
}

void Entity::setSpeed(float speed) { transform_->speed = speed; }

void Entity::setState(State state) { state_->state = state; }

std::pair<float, float> Entity::getPosition() const {
  return transform_->position;
}

std::pair<float, float> Entity::getDirection() const {
  return transform_->directionVector;
}

float Entity::getSpeed() const { return transform_->speed; }

State Entity::getState() const { return state_->state; }

void Entity::destroy() { active_ = false; }

void Entity::setMaxHp(int hp) {
  state_->maxHP = hp;
  state_->HP = hp;
}

int Entity::getMaxHp() { return state_->maxHP; }

int Entity::getHp() { return state_->HP; }

void Entity::setSize(float size) {
  transform_->size.first *= size;
  transform_->size.second *= size;
}

SDL_Rect Entity::getDimensions() {
  SDL_Rect dimensions;
  dimensions.x = transform_->position.first;
  dimensions.y = transform_->position.second;
  dimensions.w = transform_->size.first;
  dimensions.h = transform_->size.second;

  return dimensions;
}

int Entity::getZIndex() { return transform_->zIndex; }

void Entity::setZIndex(int z) { transform_->zIndex = z; }
