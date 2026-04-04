#pragma once
#include "Entity.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;
class EntityManager {
public:
  EntityManager();
  ~EntityManager();
  std::shared_ptr<Entity> createEntity(std::string tag, EntityType type);
  EntityVec &getEntities();
  EntityVec &getEntities(const std::string &tag);
  void updateEntities();
  void removeDeadEntities(EntityVec &entities);

private:
  EntityVec entityVector_;
  EntityVec entitiesToAdd_;
  EntityMap entityMap_;
};
