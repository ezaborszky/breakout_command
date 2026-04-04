#include "Entity.h"
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
