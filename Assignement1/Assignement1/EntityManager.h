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
	int mapsSize();
	BaseGameEntity* GetEntityFromId(int id);
	void removeeEntity(BaseGameEntity* entity);
	int getIdFromEntity(int i);
};
#define EntityMgr EntityManager::Instance()
