#include "Person.h"
void Person::ChangeState(State* state){
	currentState->Exit(this);
	currentState = state;
	currentState->Enter(this);
}

void Person::Update() {
	
	thirst++;
	hunger++;
	socialization--;
	if (thirst >= 70) {
		isThirsty = true;
	}
	if (hunger >= 80) {
		isHungry = true;
	}
	if (socialization <= 20) {
		needsSocialization = true;
	}
	if (fatigue >= 87) {
		isTired = true;
	}
}

void Person::IncreaseFatigue() {
	fatigue += 2;
}

int Person::checkMoney() {
	return money;
}
void Person::decreaseMoney(int amount) {
	money -= amount;
}

int Person::checkFood() {
	return food;
}
void Person::decreaseFood(int amount) {
	food -= amount;
}

int Person::checkDrink() {
	return drinks;
}
void Person::decreaseDrinks(int amount) {
	drinks -= amount;
}

void Person::ChangeLocation(std::string location) {
	currentLocation = location;
}

void Person::decreaseHunger(float amount) {
	hunger -= amount;
}
void Person::decreaseThirst(float amount) {
	thirst -= amount;
}
void Person::decreaseFatigue(float amount) {
	fatigue -= amount;
}

void Person::choseJob() {
	srand(time(0));
	int work = rand() % 2;
	if (work == 0) {
		ChangeLocation(jobs.workPlace1);
		currentWork = 1;
	}
	else
	{
		ChangeLocation(jobs.workPlace2);
		currentWork = 2;
	}
}

