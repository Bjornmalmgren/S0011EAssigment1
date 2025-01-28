#pragma once
enum message
{
	inviteToSocialize,
	canMakeIt,
	cantMakeIt
};

class Telegram
{
	int sender;
	int reciver;
	
	double dispatchTime;
	void* extraInfo;
	
public:
	message message;
	enum message getMessge();
	Telegram();
	Telegram(int Sender, int Reciver, enum message Message, double DT, void* ExtraInfo);
	//~Telegram();
	

};

