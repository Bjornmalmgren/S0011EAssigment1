#include "Person.h"

void Person::ChangeState(State* newstate, std::string nextstate) {
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
	//delete previousState;
	//previousState = currentState;

	nextState = nextstate;
	currentState->Exit(this);
	delete currentState;
	currentState = newstate;
	currentState->Enter(this);
}

void Person::Update() {
	
	//std::cout << "Thirst" << thirst << "Hunger" << hunger << std::endl;
	thirst += jobs.thirstSpeed;
	hunger += jobs.hungerSpeed;
	socialization--;
	if (thirst >= 55) {
		isThirsty = true;
	}
	else if(thirst <= 10) {
		isThirsty = false;
	}
	if (hunger >= 65) {
		isHungry = true;
	}
	else if (hunger <= 20)
	{
		isHungry = false;
	}
	if (socialization <= 40) {
		needsSocialization = true;
	}
	else if(socialization >= 90)
	{

	}
	if (fatigue >= 87) {
		isTired = true;
	}
	else if (fatigue <= 23){
		isTired = false;
	}

	if (hunger >= 100 || thirst >= 100) {
		std::cout << "Dead"<<std::endl;
		dead = true;
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
	if (food >= 0) { food = 0; }
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
	if (hunger >= 0) {
		hunger = 0;
	}
}
void Person::decreaseThirst(float amount) {
	thirst -= amount;
	if (thirst >= 0) {
		thirst = 0;
	}
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

float Person::checkHunger() {
	return hunger;
}
float Person::checkThirst() {
	return thirst;
}

bool Person::OnMessage(const Telegram& msg) {
	latestMessage = msg.message;
}

