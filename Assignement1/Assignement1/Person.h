#pragma once
#include "BaseGameEntity.h"
#include "FiniteStatemachine.h"
#include <iostream>
#include "Job.h"
class MessageDispatcher;
class Person : public  BaseGameEntity
{
public:
	std::string name;
	Person(int id, std::string newName, int i);
	~Person();
	void Update();
	void ChangeState(State* newState, std::string nextstate);
	void ChangeLocation(std::string location);
	std::string checkLocation() { return currentLocation; }
	void IncreaseFatigue();
	int checkMoney();
	void decreaseMoney(int amount);
	int checkFood();
	void decreaseFood(int amount);
	int checkDrink();
	void decreaseDrinks(int amount);
	void increaseDrinks();
	void increaseFood();
	void increaseShovels();
	int checkShovels();
	float checkHunger();
	float checkThirst();
	void decreaseHunger(float amount);
	void decreaseThirst(float amount);
	void decreaseFatigue(float amount);
	bool dead = false;
	std::string nextState; // only for walking
	void increaseMoney(int amount);
	void increaseSocial(float amount);
	float checkfatigue();
	bool isTired = false;
	bool isHungry = false;
	bool isThirsty = false;
	bool needsSocialization = false;
	bool invitedToSocial = false;
	float checkSocial();
	enum message latestMessage;
	Jobs jobs;
	bool OnMessage(const Telegram& msg);
	std::vector<int> people;
	int peopleToSocializeWith = 0;
private:
	
	State* currentState = new State_Work();
	State* previousState = new State_Work();
	float fatigue = 0;
	float money = 50;
	float hunger = 30;
	float thirst = 20;
	float socialization = 80;
	std::string currentLocation;

	//stuff to buy for money
	int food = 0;
	int drinks = 0;
	int shovels = 0;
};
