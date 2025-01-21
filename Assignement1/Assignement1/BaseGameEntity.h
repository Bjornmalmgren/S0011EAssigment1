#pragma once
#include <string>
using namespace std;
class BaseGameEntity
{
public:
	int ID;
	string name;
	static int nextvalidID;
	BaseGameEntity(int id, string newName);
	virtual ~BaseGameEntity();
	void setID(int id) { ID = id; }
	void setName(string Name) { name = Name; }
	int getID() { return ID; }
	string getName() { return name; }
	virtual void Update() = 0;
private:

};