#pragma once
#include "Component.h"
#include <memory>
#include <utility>
class Entity {
public:
  Entity();
  ~Entity();

  void setPosition(float x, float y);
  void setDirection(float x, float y);
  void setSpeed(float speed);
  void setState(State state);
  std::pair<float, float> getPosition() const;
  std::pair<float, float> getDirection() const;
  float getSpeed() const;
  State getState() const;

private:
  std::unique_ptr<CTransform> transform_ = nullptr;
  std::unique_ptr<CState> state_ = nullptr;
};
