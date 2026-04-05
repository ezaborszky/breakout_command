#include "EntityManager.h"
#include "Entity.h"
#include <algorithm>
#include <memory>

EntityManager::EntityManager() {};
EntityManager::~EntityManager() {};

std::shared_ptr<Entity> EntityManager::createEntity(std::string tag,
                                                    EntityType type) {
  auto entity = std::make_shared<Entity>(tag, type);
  entitiesToAdd_.push_back(entity);
  return entity;
}

void EntityManager::removeDeadEntities(EntityVec &entities) {
  auto del = std::remove_if(entities.begin(), entities.end(),
                            [](const std::shared_ptr<Entity> &Entity) {
                              return !Entity->isActive();
                            });
  entities.erase(del, entities.end());
}

void EntityManager::updateEntities() {

  for (auto a : entitiesToAdd_) {
    entityVector_.push_back(a);
    entityMap_[a->getTag()].push_back(a);
  }

  removeDeadEntities(entityVector_);
  for (auto &[tag, entities] : entityMap_)
    removeDeadEntities(entities);

  entitiesToAdd_.clear();

  std::sort(
      entityVector_.begin(), entityVector_.end(),
      [](const std::shared_ptr<Entity> &a, const std::shared_ptr<Entity> &b) {
        return a->getZIndex() < b->getZIndex();
      });
}

EntityVec &EntityManager::getEntities() { return entityVector_; }

EntityVec &EntityManager::getEntities(const std::string &tag) {
  return entityMap_[tag];
}

void EntityManager::printEntityCount() {
  int c = entityVector_.size();
  printf("Entity count: %i\n", c);
}
