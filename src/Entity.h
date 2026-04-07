#pragma once
#include "Component.h"
#include <SDL2/SDL_rect.h>
#include <memory>
#include <string>
#include <utility>
#include <vector>

enum EntityType { PLAYER, BLOCK, BACKGROUND };

class Entity {

public:
  Entity(std::string tag, EntityType type) : tag_(tag), type_(type) {};
  ~Entity() {};

  void setPosition(float x, float y);
  void setOriginalPosition(float x, float y);
  void setDirection(float x, float y);
  void setSpeed(float speed);
  void setState(State state);
  std::pair<float, float> getPosition() const;
  std::pair<float, float> getOriginalPosition() const;
  std::pair<float, float> getDirection() const;
  float getSpeed() const;
  State getState() const;
  void destroy();
  bool isActive();
  void setMaxHp(int hp);
  int getMaxHp();
  int getHp();
  void setSize(float size);
  SDL_Rect getDimensions();
  int getZIndex();
  void setZIndex(int z);
  std::string getTag() { return tag_; }
  int getHorizontalMiddle();
  void setHorizontalMiddle(int x);
  int getWidth();

  EntityType getType() { return type_; }
  std::shared_ptr<CTransform> transform_ = nullptr;
  std::shared_ptr<CState> state_ = nullptr;
  std::shared_ptr<CGraphics> graphics_ = nullptr;

private:
  std::string tag_ = "";
  bool active_ = true;
  EntityType type_ = BACKGROUND;
};
