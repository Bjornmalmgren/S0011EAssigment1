#include "EntityManager.h"   

EntityManager::EntityManager() {

}

EntityManager* EntityManager::Instance() {
	//instance
	static EntityManager instance;
	return &instance;
}

void EntityManager::registerEntity(BaseGameEntity* newEntity) {
	//new entity inserted
	entityMap.insert({ newEntity->getID(),newEntity });
	
}

void EntityManager::removeeEntity(BaseGameEntity* newEntity) {
	//entity erase from map
	entityMap.erase(newEntity->getID());
}

BaseGameEntity* EntityManager::GetEntityFromId(int id) {
	//returning entity
	return entityMap[id];
}

int EntityManager::mapsSize() {
	//size of map
	return entityMap.size();
	
}

int EntityManager::getIdFromEntity(int i) {
	//return id of specific entity
	if (i <= entityMap.size() - 1) {
		return entityMap[i]->getID();
	}
	else
	{
		return 0;
	}
	
}

