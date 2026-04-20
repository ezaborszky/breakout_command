#include "Entity.h"
#include "Component.h"
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_rect.h>
#include <utility>

void Entity::setPosition(float x, float y) {
  if (transform_) {
    transform_->position = {x, y};

  } else {
    printf("%s transform is null!\n", tag_.c_str());
    return;
  }
}

void Entity::setOriginalPosition(float x, float y) {
  if (transform_) {
    transform_->originalPosition = {x, y};

  } else {
    printf("%s transform is null!\n", tag_.c_str());
    return;
  }
}

void Entity::setDirection(float x, float y) {
  if (transform_) {
    transform_->directionVector = {x, y};
  } else {
    printf("%s transform_ is null\n", tag_.c_str());
    return;
  }
}

void Entity::setSpeed(float speed) {
  if (transform_ == nullptr) {
    printf("%s transform_ is null\n", tag_.c_str());
    return;
  }
  transform_->speed = speed;
}

void Entity::setState(State state) {
  if (state_) {
    state_->state = state;
  } else {
    printf("%s state is null\n", tag_.c_str());
    return;
  }
}

std::pair<float, float> Entity::getPosition() const {
  if (transform_) {
    return transform_->position;
  } else {
    printf("%s transform_ is null\n", tag_.c_str());
    return {-1, -1};
  }
}

std::pair<float, float> Entity::getOriginalPosition() const {
  if (transform_) {
    return transform_->originalPosition;
  } else {
    printf("%s transform_ is null\n", tag_.c_str());
    return {-1, -1};
  }
}

std::pair<float, float> Entity::getDirection() const {
  if (transform_) {
    return transform_->directionVector;
  } else {
    printf("%s transform_ is null\n", tag_.c_str());
    return {-1, -1};
  }
}

float Entity::getSpeed() const {
  if (transform_) {
    return transform_->speed;
  } else {

    printf("%s transform_ is null\n", tag_.c_str());
    return -1;
  }
}

State Entity::getState() const {
  if (state_) {
    return state_->state;
  } else {

    printf("%s transform_ is null\n", tag_.c_str());
    return DIRT;
  }
}

void Entity::destroy() { active_ = false; }

void Entity::setMaxHp(int hp) {
  if (state_) {
    state_->maxHP = hp;
    state_->HP = hp;
  } else {
    printf("%s state_ is null\n", tag_.c_str());
    return;
  }
}

int Entity::getMaxHp() {
  if (state_)
    return state_->maxHP;
  printf("%s state is null\n", tag_.c_str());
  return -1;
}

int Entity::getHp() {
  if (state_)
    return state_->HP;
  printf("%s state is null\n", tag_.c_str());
  return -1;
}

void Entity::setSize(float size) {
  if (transform_) {
    transform_->size.first *= size;
    transform_->size.second *= size;
  } else {
    printf("%s transform is null\n", tag_.c_str());
  }
}

SDL_Rect Entity::getDimensions() {
  SDL_Rect dimensions;
  if (transform_) {
    dimensions.x = transform_->position.first;
    dimensions.y = transform_->position.second;
    dimensions.w = transform_->size.first;
    dimensions.h = transform_->size.second;
  }

  return dimensions;
}

int Entity::getZIndex() {
  if (transform_)
    return transform_->zIndex;
  printf("%s transform_ is null\n", tag_.c_str());
  return -1;
}

void Entity::setZIndex(int z) {
  if (transform_) {
    transform_->zIndex = z;
  } else {
    printf("%s transform_ is null\n\n", tag_.c_str());
  }
}

bool Entity::isActive() { return active_; }

int Entity::getHorizontalMiddle() {
  if (transform_) {
    int width = transform_->size.first * state_->width;
    return (transform_->position.first + (width / 2.f));
  } else {
    return -1;
  }
}

void Entity::setHorizontalMiddle(int x) {
  int halfWidth = (transform_->size.first * state_->width) / 2;
  int y = getPosition().second;
  setPosition(x, y);
}

void Entity::updateDimensions() {
  float width = transform_->size.first * state_->width;
  float height = transform_->size.second;
  float x = transform_->position.first;
  float y = transform_->position.second;

  transform_->boundingbox = {x, y, width, height};
}
