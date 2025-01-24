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
	std::cout << person->name << ": ZZZ..." << person->checkfatigue() << endl;
	person->decreaseFatigue(13);
	
	if (person->isHungry) {
		std::cout << person->name << " needs to eat" << endl;
		if (person->checkFood() <= 0) {
			person->ChangeLocation("Store");
			person->ChangeState(new State_Walking, "Eat");

		}
		else
		{
			person->ChangeState(new State_Eat, "Eat");
		}
	}
	else if (person->isThirsty) {
		std::cout << person->name << " needs to drink" << endl;
		if (person->checkDrink() <= 0) {
			person->ChangeLocation("Store");
			person->ChangeState(new State_Walking, "Drink");

		}
		else
		{
			person->ChangeState(new State_Drink, "Drink");
		}
	}
	else if(person->needsSocialization)
	{
			person->ChangeState(new State_Social, "Social");
	}
	else if(person->isTired != true)
	{
			person->ChangeState(new State_Idle, "Idle");
			
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
		std::cout << person->name << " is going to the store for food"  << endl;
		person->ChangeLocation("Store");
		person->decreaseMoney(foodCost);
		person->decreaseHunger(35);
		if (person->checkMoney() > foodCost && person->checkFood() < 2) {
			std::cout << person->name << " is stockpiling some food" << endl;
			person->decreaseMoney(foodCost);
			person->increaseFood();
		}
	}
	else if(person->isHungry && person->checkFood() > 0)
	{
		std::cout << person->name << " is eating" << endl;
		person->decreaseFood(1);
		person->decreaseHunger(30);
	}
	else if (person->isHungry && person->checkFood() == 0 && person->checkMoney() < foodCost)
	{
		std::cout << person->name << " is going to work at " << person->jobs.workPlace1 << endl;
		if (person->checkLocation() == person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");

			
			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	}
	else if (person->checkMoney() < 200)
	{
		
		std::cout << person->name << " is going to work at " << person->jobs.workPlace1 << endl;
		if (person->checkLocation() == person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");

			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	
	}
	else
	{
		if (person->checkLocation() != "Home") {
			person->ChangeState(new State_Walking, "Idle");
			person->ChangeLocation("Home");
		}
		else
		{
			person->ChangeState(new State_Idle, "Idle");
		}
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
		
		person->ChangeLocation("Home");
		person->ChangeState(new State_Walking, "Sleep");
		
		std::cout << person->name << " is tired" << endl;
		//say something
	}
	else if (person->isHungry&& person->checkMoney() > foodCost) {
		if (person->checkFood() <= 0) {
			person->ChangeState(new State_Walking, "Eat");
			person->ChangeLocation("Store");
		}
		else
		{
			person->ChangeState(new State_Eat, "Eat");
		}
		std::cout << person->name << " needs to eat" << endl;
		//say something
	}
	else if (person->isThirsty && person->checkMoney() > drinkCost) {
		if (person->checkDrink() <= 0) {
			person->ChangeState(new State_Walking, "Drink");

			person->ChangeLocation("Store");
		}
		else
		{
			person->ChangeState(new State_Drink, "Drink");
		}
		std::cout << person->name << " needs to drink" << endl;
		//say something
	}
	else
	{
		//work
		
		person->increaseMoney(person->jobs.Payment());
		person->IncreaseFatigue();
		std::cout << person->name << " made: " << person->jobs.Payment()<< " working at " << person->jobs.workPlace1 << endl;
	}
}
void State_Work::Exit(Person* person) {
	std::cout << person->name << " is done with work" << endl;

}

void State_Drink::Enter(Person* person) {

	std::cout << person->name << " is thirsty" << endl;
}
void State_Drink::Execute(Person* person) {
	

	if (person->isThirsty && person->checkDrink() == 0 && person->checkMoney() > drinkCost) {
		std::cout << person->name << " is buying and drinking water" << endl;
		person->ChangeLocation("Store");
		person->decreaseMoney(drinkCost);
		person->decreaseThirst(40);
		if (person->checkMoney() > foodCost && person->isHungry) {
			person->ChangeState(new State_Eat, "Eat");
		}
		else if (person->checkMoney() > drinkCost && person->checkDrink() < 2) {
			std::cout << person->name << " is stockpiling some drinks" << endl;
			person->decreaseMoney(drinkCost);
			person->increaseDrinks();
		}
	}
	else if (person->isThirsty && person->checkDrink() > 0)
	{
		std::cout << person->name << " is drinking water" << endl;
		person->decreaseDrinks(1);
		person->decreaseThirst(40);
	}
	else if (person->isThirsty && person->checkDrink() == 0 && person->checkMoney() < drinkCost)
	{
		//poor
		std::cout << person->name<<" have no money" << endl;
		if (person->checkLocation() != person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");
			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	}
	else if (person->checkMoney() < 200)
	{
		std::cout << person->name << " is going to work at " << person->jobs.workPlace1 << endl;
		if (person->checkLocation() != person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");
			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	}
	else
	{
		std::cout << person->name << " is going to chill" << endl;
		if (person->checkLocation() != "Home") {
			person->ChangeState(new State_Walking, "Idle");
			person->ChangeLocation("Home");
		}
		else
		{
			person->ChangeState(new State_Idle, "Idle");
		}
	}
}
void State_Drink::Exit(Person* person) {
	std::cout << person->name << " is done drinking" << endl;

}

void State_Social::Enter(Person* person) {


}
void State_Social::Execute(Person* person) {

}
void State_Social::Exit(Person* person) {


}

void State_Idle::Enter(Person* person) {
	std::cout << person->name << " is going to chill " << person->checkMoney() << endl;
 }
void State_Idle::Execute(Person* person) {
	if (person->isHungry) {

		std::cout << person->name << " is hungry time to eat " << endl;
		if (person->checkFood() <= 0) {
			person->ChangeState(new State_Walking, "Eat");
			person->ChangeLocation("Store");
		}
		else
		{
			person->ChangeState(new State_Eat, "Eat");
		}
	}
	else if(person->isThirsty)
	{
		std::cout << person->name << " is thirsty time to drink " << endl;
		if (person->checkDrink() <= 0) {
			person->ChangeState(new State_Walking, "Drink");
			person->ChangeLocation("Store");
		}
		else
		{
			person->ChangeState(new State_Drink, "Drink");
		}
		
	}
	else if(person->checkMoney() > 130)
	{
		person->ChangeLocation("Store");
		person->ChangeState(new State_Walking, "EM");

	}
	else if (person->isTired) {
		std::cout << person->name << " is tired time to sleep" << endl;
		person->ChangeState(new State_Sleep, "Sleep");
	}
	else
	{
		std::cout << person->name << " is chilling" << endl;
	}
 }
void State_Idle::Exit(Person* person) {
	std::cout << person->name << " is going to " << person->checkLocation() << endl;
 }

void State_ExtraMoney::Enter(Person* person) {
	std::cout << person->name << " haves some extra money time to buy some stuff " << endl;
	person->ChangeLocation("Store");
 }
void State_ExtraMoney::Execute(Person* person) {
	if (person->isHungry) {

		std::cout << person->name << " is hungry time to eat " << endl;
		person->ChangeState(new State_Eat, "Eat");
	}
	else if (person->isThirsty)
	{
		std::cout << person->name << " is thirsty time to drink " << endl;
		
		person->ChangeState(new State_Drink, "Drink");
		
	}
	else if (person->checkMoney() > 130)
	{
		if (person->checkFood() <= person->checkDrink() && person->checkDrink() < 4) {
			person->decreaseMoney(foodCost);
			person->increaseFood();
			std::cout << person->name << " bought some food, now have "<< person->checkFood() << endl;
		}
		else if (person->checkFood() >= person->checkDrink() && person->checkFood() < 4) {
			person->decreaseMoney(drinkCost);
			person->increaseDrinks();
			std::cout << person->name << " bought some drinks, now have " << person->checkDrink() << endl;
		}
		else
		{
			person->decreaseMoney(shovelCost);
			person->increaseShovels();
			std::cout << person->name << " bought some shovels, now have " << person->checkShovels() << endl;
		}


	}
	else
	{
		if (person->checkMoney() > 130) {
			person->ChangeState(new State_Walking, "Idle");
			person->ChangeLocation("Home");
		}
		else
		{
			person->ChangeState(new State_Walking, "Work");
			person->ChangeLocation(person->jobs.workPlace1);
		}
		
	}
 }
void State_ExtraMoney::Exit(Person* person) {
	std::cout << person->name << " is going to " << person->checkLocation() << endl;
 }

 void State_Walking::Enter(Person* person) {
	 std::cout << person->name << " is going to " << person->checkLocation() << endl;
}
 void State_Walking::Execute(Person* person) {
	 distance--;
	 std::cout << person->name << " is walking to " << person->checkLocation() << endl;
	 if (distance <= 0) {
		 distance = 5;
		 if (person->nextState == "Drink") {

			 person->ChangeState(new State_Drink, "Drink");

		 }
		 else if(person->nextState == "Eat")
		 {
			 person->ChangeState(new State_Eat, "Eat");
		 }
		 else if (person->nextState == "EM")
		 {
			 person->ChangeState(new State_ExtraMoney, "EM");
		 }
		 else if (person->nextState == "Idle")
		 {
			 person->ChangeState(new State_Idle, "Idle");
		 }
		 else if (person->nextState == "Sleep")
		 {
			 person->ChangeState(new State_Sleep, "Sleep");
		 }
		 else if (person->nextState == "Work")
		 {
			 person->ChangeState(new State_Work, "Work");
		 }
		 else if (person->nextState == "Social")
		 {
			 person->ChangeState(new State_Social, "Social");
		 }
		 
	 }
}
void State_Walking::Exit(Person* person) {

}