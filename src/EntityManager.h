#pragma once
#include "Entity.h"
#include <map>
#include <memory>
#include <string>
#include <vector>
class EntityManager {
public:
  std::unique_ptr<Entity> createEntity();
  std::vector<Entity> getEntitites();
  std::vector<Entity> getEntitites(std::string &tag);
  void createEntity(std::string &tag);
  void updateEntities();

private:
  std::vector<Entity> entityVector;
  std::map<std::string, std::vector<Entity>> entityMap;
};
