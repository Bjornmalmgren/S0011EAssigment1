#include "EntityManager.h"   

EntityManager::EntityManager() {

}

EntityManager* EntityManager::Instance() {
	static EntityManager instance;
	return &instance;
}

void EntityManager::registerEntity(BaseGameEntity* newEntity) {
	entityMap.insert({ newEntity->getID(),newEntity });
	
}

void EntityManager::removeeEntity(BaseGameEntity* newEntity) {
	entityMap.erase(newEntity->getID());
}

BaseGameEntity* EntityManager::GetEntityFromId(int id) {
	return entityMap[id];
}

int EntityManager::mapsSize() {
	return entityMap.size();
	
}

int EntityManager::getIdFromEntity(int i) {
	if (i <= entityMap.size() - 1) {
		return entityMap[i]->getID();
	}
	else
	{
		return 0;
	}
	
}

