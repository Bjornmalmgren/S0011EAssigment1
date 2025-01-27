//#pragma once
//#include "Telegram.h"
#include <set>
#include <chrono>
#include "EntityManager.h"
class MessageDispatcher
{
private:
	std::set<Telegram> PriorityQue;
	void discharge(BaseGameEntity* pReciver, const Telegram& msg);
	
	
public:
	MessageDispatcher();
	static MessageDispatcher* Instance();
	void dispatchMessage(double delay, int sender, int reciver, enum message message, void* extraInfo);
};
#define MsgD MessageDispatcher::Instance()

