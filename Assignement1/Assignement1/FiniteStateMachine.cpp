#include "FiniteStateMachine.h"
#include <iostream>
#include "Person.h"
using namespace std;
void State_Sleep::Enter(Person* BGE) {
	Person* person = (Person*)BGE;
	cout << person->name << " time to sleep" << endl;
	person->ChangeLocation("Home");
}
void State_Sleep::Execute(Person* BGE) {
	Person* person = (Person*)BGE;
	cout << person->name << ": ZZZ..." << person->checkfatigue() << endl;
	person->decreaseFatigue(13);
	
	if (person->isHungry) {
		cout << person->name << " needs to eat" << endl;
			person->ChangeState(new State_Eat);
	}
	else if (person->isThirsty) {
		cout << person->name << " needs to drink" << endl;
			person->ChangeState(new State_Drink);
	}
	else if(person->needsSocialization)
	{
			person->ChangeState(new State_Social);
	}
	else if(person->isTired != true)
	{
			person->ChangeState(new State_Idle);
			
	}
	

}
void State_Sleep::Exit(Person* person) {

	cout << person->name << " is well rested" << endl;
}


void State_Eat::Enter(Person* person) {

	cout << person->name << " needs food" << endl;
}
void State_Eat::Execute(Person* person) {
	if(person->isHungry && person->checkFood() == 0 && person->checkMoney() > foodCost) {
		cout << person->name << " is going to the store for food"  << endl;
		person->ChangeLocation("Store");
		person->decreaseMoney(foodCost);
		person->decreaseHunger(30);
		if (person->checkMoney() > foodCost && person->checkFood() < 2) {
			cout << person->name << " is stockpiling some food" << endl;
			person->decreaseMoney(foodCost);
			person->increaseFood();
		}
	}
	else if(person->isHungry && person->checkFood() > 0)
	{
		cout << person->name << " is eating" << endl;
		person->decreaseFood(1);
		person->decreaseHunger(30);
	}
	else if (person->isHungry && person->checkFood() == 0 && person->checkMoney() < foodCost)
	{
		cout << person->name << " is going to work at " << person->jobs.workPlace1 << endl;
		person->ChangeState(new State_Work);
	}
	else if (person->checkMoney() < 200)
	{
		
		cout << person->name << " is going to work at " << person->jobs.workPlace1 << endl;
		person->ChangeState(new State_Work);
	}
	else
	{
		person->ChangeState(new State_Idle);
	}
}
void State_Eat::Exit(Person* person) {

	cout << person->name << " is full" << endl;
}

void State_Work::Enter(Person* person) {

	cout << person->name << " is going to work at "<< person->jobs.workPlace1 << endl;
}
void State_Work::Execute(Person* person) {
	//say something
	
	if (person->isTired) {
		person->ChangeState(new State_Sleep);
		cout << person->name << " is tired" << endl;
		//say something
	}
	else if (person->isHungry&& person->checkMoney() > 200) {
		person->ChangeState(new State_Eat);
		cout << person->name << " needs to eat" << endl;
		//say something
	}
	else if (person->isThirsty && person->checkMoney() > 140) {
		person->ChangeState(new State_Drink);
		cout << person->name << " needs to drink" << endl;
		//say something
	}
	else
	{
		//work
		
		person->increaseMoney(person->jobs.Payment());
		person->IncreaseFatigue();
		cout << person->name << " made: " << person->jobs.Payment()<< " working at " << person->jobs.workPlace1 << endl;
	}
}
void State_Work::Exit(Person* person) {
	cout << person->name << " is done with work" << endl;

}

void State_Drink::Enter(Person* person) {

	cout << person->name << " is thirsty" << endl;
}
void State_Drink::Execute(Person* person) {
	

	if (person->isThirsty && person->checkDrink() == 0 && person->checkMoney() > drinkCost) {
		cout << person->name << " is buying and drinking water" << endl;
		person->ChangeLocation("Store");
		person->decreaseMoney(drinkCost);
		person->decreaseThirst(40);
		if (person->checkMoney() > drinkCost && person->checkDrink() < 2) {
			cout << person->name << " is stockpiling some drinks" << endl;
			person->decreaseMoney(drinkCost);
			person->increaseDrinks();
		}
	}
	else if (person->isThirsty && person->checkDrink() > 0)
	{
		cout << person->name << " is drinking water" << endl;
		person->decreaseDrinks(1);
		person->decreaseThirst(40);
	}
	else if (person->isThirsty && person->checkDrink() == 0 && person->checkMoney() < drinkCost)
	{
		//poor
		cout << person->name<<" have no money" << endl;
		person->ChangeState(new State_Work);
	}
	else if (person->checkMoney() < 200)
	{
		cout << person->name << " is going to work at " << person->jobs.workPlace1 << endl;
		person->ChangeState(new State_Work);
	}
	else
	{
		cout << person->name << " is going to chill" << endl;
		person->ChangeState(new State_Idle);
	}
}
void State_Drink::Exit(Person* person) {
	cout << person->name << " is done drinking" << endl;

}

void State_Social::Enter(Person* person) {


}
void State_Social::Execute(Person* person) {

}
void State_Social::Exit(Person* person) {


}

void State_Idle::Enter(Person* person) {
	cout << person->name << " is going to chill " << person->checkMoney() << endl;
 }
void State_Idle::Execute(Person* person) {
	if (person->isHungry) {

		cout << person->name << " is hungry time to eat " << endl;
		person->ChangeState(new State_Eat);
	}
	else if(person->isThirsty)
	{
		cout << person->name << " is thirsty time to drink " << endl;
		person->ChangeState(new State_Drink);
	}
	else if(person->checkMoney() > 130)
	{
		person->ChangeLocation("Store");
		person->ChangeState(new State_ExtraMoney);
	}
	else if (person->isTired) {
		cout << person->name << " is tired time to sleep" << endl;
		person->ChangeState(new State_Sleep);
	}
	else
	{
		cout << person->name << " is chilling" << endl;
	}
 }
void State_Idle::Exit(Person* person) {
	cout << person->name << " is going to " << person->checkLocation() << endl;
 }

void State_ExtraMoney::Enter(Person* person) {
	cout << person->name << " haves some extra money time to buy some stuff " << endl;
	person->ChangeLocation("store");
 }
void State_ExtraMoney::Execute(Person* person) {
	if (person->isHungry) {

		cout << person->name << " is hungry time to eat " << endl;
		person->ChangeState(new State_Eat);
	}
	else if (person->isThirsty)
	{
		cout << person->name << " is thirsty time to drink " << endl;
		person->ChangeState(new State_Drink);
	}
	else if (person->checkMoney() > 130)
	{
		if (person->checkFood() <= person->checkDrink() && person->checkDrink() < 4) {
			person->decreaseMoney(foodCost);
			person->increaseFood();
			cout << person->name << " bought some food, now have "<< person->checkFood() << endl;
		}
		else if (person->checkFood() >= person->checkDrink() && person->checkFood() < 4) {
			person->decreaseMoney(drinkCost);
			person->increaseDrinks();
			cout << person->name << " bought some drinks, now have " << person->checkDrink() << endl;
		}
		else
		{
			person->decreaseMoney(shovelCost);
			person->increaseShovels();
			cout << person->name << " bought some shovels, now have " << person->checkShovels() << endl;
		}


	}
	else
	{

		person->ChangeState(new State_Idle);
		person->ChangeLocation("Home");
	}
 }
void State_ExtraMoney::Exit(Person* person) {
	cout << person->name << " is going to " << person->checkLocation() << endl;
 }