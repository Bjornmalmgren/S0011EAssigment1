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
	message message;
	double dispatchTime;
	void* extraInfo;
	
public:
	
	enum message getMessge();
	Telegram();
	Telegram(int Sender, int Reciver, enum message Message, double DT, void* ExtraInfo);
	//~Telegram();
	

};

