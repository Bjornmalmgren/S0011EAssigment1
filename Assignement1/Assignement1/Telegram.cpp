#include "Telegram.h"

Telegram::Telegram(int Sender, int Reciver, enum message Message, double DT, void* ExtraInfo) {
	sender = Sender;
	reciver = Reciver;
	message = Message;
	dispatchTime = DT;
	extraInfo = ExtraInfo;
}

enum message Telegram::getMessge() {
	return message;
}