#pragma once
#include "Telegram.h"
#include "EntityManager.h"
#include <set>
#include <chrono>
class MessageDispatcher
{
private:
	std::set<Telegram> PriorityQue;
	void discharge(BaseGameEntity* pReciver, const Telegram& msg);
	
	
public:
	EntityManager entityMG;
	MessageDispatcher();
	static MessageDispatcher* Instance();
	void dispatchMessage(double delay, int sender, int reciver, enum Telegram::message message, void* extraInfo);
};
#define Dispatch MessageDispatcher::Instance();

