#pragma once
#include "Component.h"
#include <memory>
class Entity {
public:
  Entity() {}
  ~Entity() {}
  std::unique_ptr<CTransform> transform_ = nullptr;
  std::unique_ptr<CState> state_ = nullptr;
};
