#include "MessageDispatcher.h"


MessageDispatcher* MessageDispatcher::Instance() {
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::dispatchMessage(double delay, int sender, int reciver, enum Telegram::message message, void* extraInfo) {
	BaseGameEntity* pReciver = entityMG.GetEntityFromId(reciver);
	Telegram telegram(sender, reciver, message, 0, extraInfo);
	if (delay <= 0.0) {
		discharge(pReciver, telegram);
	}
	
}

void MessageDispatcher::discharge(BaseGameEntity* pReciver, const Telegram& msg) {

}