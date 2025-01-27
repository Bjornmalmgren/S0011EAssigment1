#pragma once
#include <map>
#include "Person.h"   
class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EntityMap;
private:

	EntityMap entityMap;
	
	
public:
	EntityManager();
	static EntityManager* Instance();
	void registerEntity(BaseGameEntity* newEntity);

	BaseGameEntity* GetEntityFromId(int id);
	void removeeEntity(BaseGameEntity* entity);
};
#define EntityMgr EntityManager::Instance()
