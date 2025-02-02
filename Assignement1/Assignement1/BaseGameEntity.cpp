#include "BaseGameEntity.h"

BaseGameEntity::BaseGameEntity(int id, string newName)
{
	setID(id);
	setName(newName);
	
}

void BaseGameEntity::setID(int id) 
{
	//making sure the id is valid
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

void BaseGameEntity::setName(string Name)
{
	name = Name;
}
BaseGameEntity::~BaseGameEntity(){

}
int BaseGameEntity::getID(){
	return ID;
}

string BaseGameEntity::getName() {
	return name;
}
int BaseGameEntity::nextvalidID = 0;

BaseGameEntity::BaseGameEntity() {

}