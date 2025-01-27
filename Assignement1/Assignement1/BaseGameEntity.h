#pragma once
#include <string>
#include "MessageDispatcher.h"
using namespace std;
class BaseGameEntity
{
public:
	int ID;
	string name;
	static int nextvalidID;
	BaseGameEntity(int id, string newName);
	BaseGameEntity();
	virtual ~BaseGameEntity();
	void setID(int id);
	void setName(string Name);
	int getID();
	string getName();
	virtual void Update() = 0;
	virtual bool OnMessage(const Telegram& msg) = 0;
private:

};