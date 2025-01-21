#pragma once
#include "BaseGameEntity.h"
#include "FiniteStatemachine.h"
#include "Job.h"
class Person : public  BaseGameEntity
{
public:
	std::string name;
	Person(int id, std::string newName);
	~Person();
	void Update();
	void ChangeState(State* newState);
	void ChangeLocation(std::string location);
	std::string checkLocation() { return currentLocation; }
	void IncreaseFatigue();
	int checkMoney();
	void decreaseMoney(int amount);
	int checkFood();
	void decreaseFood(int amount);
	int checkDrink();
	void decreaseDrinks(int amount);

	void decreaseHunger(float amount);
	void decreaseThirst(float amount);
	void decreaseFatigue(float amount);

	void choseJob();

	bool isTired = false;
	bool isHungry = false;
	bool isThirsty = false;
	bool needsSocialization = false;
	Jobs jobs;
	int currentWork = 1;
private:
	
	State* currentState;
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
