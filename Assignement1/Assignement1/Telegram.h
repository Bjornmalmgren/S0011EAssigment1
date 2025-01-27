#pragma once


class Telegram
{
	int sender;
	int reciver;
	
	double dispatchTime;
	void* extraInfo;
	enum message
	{
		inviteToSocialize,
		canMakeIt,
		cantMakeIt
	};
public:
	message message;
	Telegram();
	Telegram(int Sender, int Reciver, enum Telegram::message Message, double DT, void* ExtraInfo);
	~Telegram();
	
	
};

