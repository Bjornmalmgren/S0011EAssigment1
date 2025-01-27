#pragma once
#include <map>
#include "BaseGameEntity.h"
class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EntityMap;
private:

	EntityMap entityMap;
	EntityManager();
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);
public:
	static EntityManager* Instance();

	void registerEntity(BaseGameEntity* newEntity);

	BaseGameEntity* GetEntityFromId(int id);
	void removeeEntity(BaseGameEntity* entity);
};
#define EnityMgr EntityManager::Instance();
