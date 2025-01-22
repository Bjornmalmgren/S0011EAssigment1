#include "Person.h"

void Person::ChangeState(State* newstate) {
	/*State* newState = new State_Work();
	switch (newstate)
	{
	case Sleep:
		newState = new State_Sleep();
	case Drink:
		newState = new State_Drink();
	case Eat:
		newState = new State_Eat();
	case Work:
		newState = new State_Work();
	case Social:
		newState = new State_Social();
	default:
		break;
	}
	*/
	currentState->Exit(this);
	currentState = newstate;
	currentState->Enter(this);
}

void Person::Update() {
	
	//std::cout << "Thirst" << thirst << "Hunger" << hunger << std::endl;
	thirst += jobs.thirstSpeed;
	hunger += jobs.hungerSpeed;
	//socialization--;
	if (thirst >= 70) {
		isThirsty = true;
	}
	else if(thirst <= 10) {
		isThirsty = false;
	}
	if (hunger >= 80) {
		isHungry = true;
	}
	else if (hunger <= 20)
	{
		isHungry = false;
	}
	if (socialization <= 20) {
		needsSocialization = true;
	}
	if (fatigue >= 87) {
		isTired = true;
	}
	else if (fatigue <= 23){
		isTired = false;
	}

	if (hunger >= 100 || thirst >= 100) {
		std::cout << "Dead"<<std::endl;
	}
	currentState->Execute(this);
}

void Person::IncreaseFatigue() {
	fatigue += jobs.fatigueSpeed;
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
void Person::increaseMoney(int amount) {
	money += amount;
}

Person::Person(int id, string newName) {
	setID(id);
	name = newName;
	jobs.selectJobs();
}
Person::~Person() {

}

void Person::increaseFood() {

	food++;
}
void Person::increaseDrinks() {
	drinks++;
}

float Person::checkfatigue() {
	return fatigue;
}

void Person::increaseShovels() {
	shovels++;
}
int Person::checkShovels() {
	return shovels;
}

