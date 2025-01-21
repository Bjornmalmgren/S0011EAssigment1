#include "BaseGameEntity.h"

BaseGameEntity::BaseGameEntity(int id, string newName)
{
	setID(id);
	setName(newName);
}

void BaseGameEntity::setID(int id) 
{
	if (id >= nextvalidID) {
		ID = id;
		nextvalidID++;
	}
	else
	{
		ID = nextvalidID;
		nextvalidID++;
	}
	
}
int BaseGameEntity::getID() {
	return ID;
}