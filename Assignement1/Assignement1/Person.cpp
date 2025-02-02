#include "Person.h"
#include "MessageDispatcher.h"

void Person::ChangeState(State* newstate, std::string nextstate) {
	 
	//changing the states
	nextState = nextstate;
	currentState->Exit(this);
	delete currentState;
	currentState = newstate;
	currentState->Enter(this);
}

void Person::Update() {
	
	//changes bools values to simulate thirst, hunger, fatigue, socialization
	if (thirst >= 51) {
		isThirsty = true;
	}
	else if(thirst <= 10) {
		isThirsty = false;
	}
	if (hunger >= 61) {
		isHungry = true;
	}
	else if (hunger <= 20)
	{
		isHungry = false;
	}
	if (socialization <= 40) {
		needsSocialization = true;
	}
	else if(socialization >= 80)
	{
		needsSocialization = false;
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
	else
	{
		//every update if person isn't dead
		currentState->Execute(this);
		thirst += jobs.thirstSpeed;
		hunger += jobs.hungerSpeed;
		socialization--;
	}
	
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
	if (food <= 0) { food = 0; }
}

int Person::checkDrink() {
	return drinks;
}
void Person::decreaseDrinks(int amount) {
	drinks -= amount;
	if (drinks <= 0) { drinks = 0; }
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

Person::Person(int id, string newName, int i) {
	setID(id);
	name = newName;
	jobs.selectJobs(i);
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
	switch (msg.message)
	{
	case inviteToSocialize:
		//checking to make sure that the person can make it to the social event
		if (isHungry == true || isThirsty == true || money < 100) {
			for (int i = 0; i < EntityMgr->mapsSize(); i++)
			{
				if (people[i] != ID) {
					MsgD->dispatchMessage(0, getID(), people[i], cantMakeIt, 0);
				}
				
			}
		}
		//if they can make send such a message
		else
		{
			for (int i = 0; i < EntityMgr->mapsSize(); i++)
			{
				if (people[i] != ID) {
					MsgD->dispatchMessage(0, getID(), people[i], canMakeIt, 0);
				}

			}
			if ((currentState != new State_Social) && nextState != "Social") {
				ChangeLocation("Resturant");
				ChangeState(new State_Walking, "Social");
			}
			
			peopleToSocializeWith = 0;
		}
		break;
	case canMakeIt:
		peopleToSocializeWith += 1;
		break;
	case cantMakeIt:
		break;
	default:
		break;
	}
	return true;
}

void Person::increaseSocial(float amount) {
	socialization += amount;
}
float Person::checkSocial() {
	return socialization;
}




