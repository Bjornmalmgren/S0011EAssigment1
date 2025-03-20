#include "FiniteStateMachine.h"
#include <iostream>
#include "Person.h" 
#include "MessageDispatcher.h"
using namespace std;
void State_Sleep::Enter(Person* person) {

	//cout << person->name << " time to sleep ";
	person->ChangeLocation("Home");
}
void State_Sleep::Execute(Person* person) {
	
	//sleeping
	std::cout << person->name << ": ZZZ..." << person->checkfatigue();
	person->decreaseFatigue(13);
	
	//checking if the current state needs to change
	if (person->isHungry) {
		//changes to eat state after walking if needed
		std::cout << person->name << " needs to eat ";
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
		//changes to drink state after walking if needed
		std::cout << person->name << " needs to drink ";
		if (person->checkDrink() <= 0) {
			person->ChangeLocation("Store");
			person->ChangeState(new State_Walking, "Drink");

		}
		else
		{
			person->ChangeState(new State_Drink, "Drink");
		}
	}
	else if(person->needsSocialization && person->checkMoney() > 100 && person->people.size() < 1)
	{
		//sends a message to all the other chracters to check if they can socialize
		for (int i = 0; i < EntityMgr->mapsSize(); i++)
		{
			person->ChangeLocation("Resturant");
			MsgD->dispatchMessage(0, person->getID(), person->people[i], inviteToSocialize, 0);
		}
			
	}
	else if ( person->checkMoney() < 100)
	{
		//Goes to work if they have to litlle money
		person->ChangeState(new State_Walking, "Work");

	}
	else if(person->isTired != true)
	{
		//changes to idle state if nothing else can be done
			person->ChangeState(new State_Idle, "Idle");
			
	}
	

}
void State_Sleep::Exit(Person* person) {

	//cout << person->name << " is well rested ";
}


void State_Eat::Enter(Person* person) {

	//cout << person->name << " needs food ";
}
void State_Eat::Execute(Person* person) {
	//checks if they don't have food and have enough money to buy food
	if(person->isHungry && person->checkFood() == 0 && person->checkMoney() > foodCost) {
		std::cout << person->name << " is going to the store for food " ;
		//buys and eats food
		person->ChangeLocation("Store");
		person->decreaseMoney(foodCost);
		person->decreaseHunger(35);
		//checks if they can buy more food and they don't have to much food already
		if (person->checkMoney() > foodCost && person->checkFood() < 2) {
			std::cout << person->name << " is stockpiling some food " ;
			person->decreaseMoney(foodCost);
			person->increaseFood();
		}
	}
	//checks if they already have food
	else if(person->isHungry && person->checkFood() > 0)
	{
		std::cout << person->name << " is eating ";
		person->decreaseFood(1);
		person->decreaseHunger(30);
	}
	//checks if they don't have food and have enough and dont have enough money
	else if (person->isHungry && person->checkFood() == 0 && person->checkMoney() < foodCost)
	{
		std::cout << person->name << " is going to work at " << person->jobs.workPlace1 << " ";
		//they change to the work state
		if (person->checkLocation() == person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");

			
			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	}
	//checks if they have more money 
	else if (person->checkMoney() < 200)
	{
		//changes to the extra money state
		std::cout << person->name << " is going to work at " << person->jobs.workPlace1 << " ";
		if (person->checkLocation() == person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");

			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	
	}
	else if (person->isThirsty) {
		//changes to the drink states
		std::cout << person->name << "is going to buy some drinks " ;
		person->ChangeState(new State_Drink, "Drink");
	}
	else if (person->needsSocialization && person->checkMoney() > 100 && person->people.size() < 1) {
		//sends a message to all the other chracters to check if they can socialize
		std::cout << person->name << "is going to Socialize ";
		for (int i = 0; i < EntityMgr->mapsSize(); i++)
		{
			person->ChangeLocation("Resturant");
			MsgD->dispatchMessage(0, person->getID(), person->people[i], inviteToSocialize, 0);
		}
	}
	else
	{
		//changes to idle state
		std::cout << person->name << "is going Home ";
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

	//cout << person->name << " is full" ;
}

void State_Work::Enter(Person* person) {

	//cout << person->name << " is going to work at "<< person->jobs.workPlace1 << " ";
}
void State_Work::Execute(Person* person) {
	//continues to work if hungry and don't have enough money
	if (person->isHungry && person->checkMoney() < foodCost || person->isThirsty && person->checkMoney() < drinkCost) {
		person->increaseMoney(person->jobs.Payment());
		person->IncreaseFatigue();
		std::cout << person->name << " made: " << person->jobs.Payment() << " working at " << person->jobs.workPlace1 << " ";
	}
	//has become exhausted and goes home to sleep
	else if (person->isTired) {
		std::cout << person->name << " is tired ";
		person->ChangeLocation("Home");
		person->ChangeState(new State_Walking, "Sleep");
		
		
		
	}
	//buys food if they are more hungry than thirsty and have enough money
	else if (person->isHungry&& person->checkMoney() > foodCost && person->checkHunger() > person->checkThirst()) {
		std::cout << person->name << " needs to eat ";
		if (person->checkFood() <= 0) {
			person->ChangeState(new State_Walking, "Eat");
			person->ChangeLocation("Store");
		}
		else
		{
			person->ChangeState(new State_Eat, "Eat");
		}
		
		//
	}
	//buys drinks if they have enough money
	else if (person->isThirsty && person->checkMoney() > drinkCost) {
		std::cout << person->name << " needs to drink ";
		if (person->checkDrink() <= 0) {
			person->ChangeState(new State_Walking, "Drink");

			person->ChangeLocation("Store");
		}
		else
		{
			person->ChangeState(new State_Drink, "Drink");
		}
		
		//say something
	}
	else if (person->needsSocialization && person->checkMoney() > 100 && person->people.size() < 1) {
		//sends a message to all the other chracters to check if they can socialize
		std::cout << person->name << " is going to socialize ";
		for(int i = 0; i < EntityMgr->mapsSize(); i++)
		{
			person->ChangeLocation("Resturant");
			MsgD->dispatchMessage(0, person->getID(), person->people[i], inviteToSocialize, 0);
		}
	}
	else
	{
		//works and gets payed and gets more tired
		
		person->increaseMoney(person->jobs.Payment());
		person->IncreaseFatigue();
		std::cout << person->name << " made: " << person->jobs.Payment()<< " working at " << person->jobs.workPlace1 ;
	}
}
void State_Work::Exit(Person* person) {
	//std::cout << person->name << " is done with work " ;

}

void State_Drink::Enter(Person* person) {

	//std::cout << person->name << " is thirsty " ;
}
void State_Drink::Execute(Person* person) {
	
	//checks if the character does not have a drink on them and enough money to buy it
	if (person->isThirsty && person->checkDrink() == 0 && person->checkMoney() > drinkCost) {
		std::cout << person->name << " is buying and drinking water ";
		//buying drink
		person->ChangeLocation("Store");
		person->decreaseMoney(drinkCost);
		person->decreaseThirst(40);
		//checks if the character has more money and is hungry, changes then to eat state
		if (person->checkMoney() > foodCost && person->isHungry) {
			person->ChangeState(new State_Eat, "Eat");
		}
		//checks if the character can buy more drinks
		else if (person->checkMoney() > drinkCost && person->checkDrink() < 2) {
			std::cout << person->name << " is stockpiling some drinks ";
			person->decreaseMoney(drinkCost);
			person->increaseDrinks();
		}
	}
	//checks if the character already has drinks
	else if (person->isThirsty && person->checkDrink() > 0)
	{
		std::cout << person->name << " is drinking water " ;
		person->decreaseDrinks(1);
		person->decreaseThirst(40);
	}
	else if (person->isThirsty && person->checkDrink() == 0 && person->checkMoney() < drinkCost)
	{
		//cant aford drinks and and needs to work to buy drinks
		std::cout << person->name<<" have no money " ;
		if (person->checkLocation() != person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");
			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	}
	//checks if person is hungry
	else if (person->isHungry) {
		std::cout << person->name << " needs to eat ";
		person->ChangeState(new State_Eat, "Eat");
	}
	//checks if the character has enough money to buy more drinks if not they go to work
	else if (person->checkMoney() < drinkCost)
	{
		std::cout << person->name << " is going to work at " << person->jobs.workPlace1 << " ";
		if (person->checkLocation() != person->jobs.workPlace1) {
			person->ChangeState(new State_Walking, "Work");
			person->ChangeLocation(person->jobs.workPlace1);
		}
		else
		{
			person->ChangeState(new State_Work, "Work");
		}
	}
	else if (person->needsSocialization && person->checkMoney() > 100 && person->people.size() < 1) {
		//sends a message to all the other chracters to check if they can socialize
		std::cout << person->name << " is going to socialize " ;
		for (int i = 0; i < EntityMgr->mapsSize(); i++)
		{
			
			person->ChangeLocation("Resturant");
			MsgD->dispatchMessage(0, person->getID(), person->people[i], inviteToSocialize, 0);
		}
	}
	else
	{
		//if nothing else go home to chill
		std::cout << person->name << " is going to chill " ;
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
	//std::cout << person->name << " is done drinking " ;

}

void State_Social::Enter(Person* person) {
	//std::cout << person->name << " is going to socialize ";

}
void State_Social::Execute(Person* person) {
	if (person->peopleToSocializeWith > 0) {
		//increases socialization based on how many came to meeting
		person->increaseSocial(3 * person->peopleToSocializeWith);
	}
	else
	{
		//if nobody came increase slower
		person->increaseSocial(2.5);
	}
	
	std::cout << person->name << ", is hanging out with friends ";

	if (person->isHungry) {
		//checks if character has food
		if (person->checkFood() > 0) {
			person->decreaseFood(1);
			person->decreaseHunger(35);
		}
		//checks if the character has no food and enough money
		else if(person->checkFood() <= 0 && person->checkMoney() >= foodCost)
		{
			person->decreaseMoney(foodCost);
			person->decreaseHunger(35);
		}
		//going too work otherwise
		else
		{
			std::cout <<  ", is going to " << person->jobs.workPlace1 << " ";
			person->ChangeLocation(person->jobs.workPlace1);
			person->ChangeState(new State_Walking, "Work");
		}

	}
	else if (person->isThirsty) {
		//checks if character has drinks
		if (person->checkDrink() > 0) {
			person->decreaseDrinks(1);
			person->decreaseThirst(40);
		}
		//checks if the character has no drinks and enough money
		else if (person->checkDrink() <= 0 && person->checkMoney() >= drinkCost)
		{
			person->decreaseMoney(drinkCost);
			person->decreaseThirst(40);
		}
		//going to work otherwise
		else
		{
			std::cout <<  ", is going to " << person->jobs.workPlace1 << " ";
			person->ChangeLocation(person->jobs.workPlace1);
			person->ChangeState(new State_Walking, "Work");
		}
	}
	//checks if character is tired
	else if (person->isTired) {
		std::cout <<  ", is going Home ";
		person->ChangeState(new State_Walking, "Sleep");
		person->ChangeLocation("Home");
	}
	//if theres no need for socialization any more go to work
	else if (person->needsSocialization != true) {
		
		std::cout <<  ", is going to "<< person->jobs.workPlace1 << " ";
		person->ChangeState(new State_Walking, "Work");
		person->ChangeLocation(person->jobs.workPlace1);
	}
}
void State_Social::Exit(Person* person) {
	//std::cout << person->name << " is done socializing ";

}

void State_Idle::Enter(Person* person) {
	//std::cout << person->name << " is going to chill " << person->checkMoney();
 }
void State_Idle::Execute(Person* person) {
	if (person->isHungry) {
		//changes to eat state
		std::cout << person->name << " is hungry time to eat ";
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
		//changes to drink state
		std::cout << person->name << " is thirsty time to drink " ;
		if (person->checkDrink() <= 0) {
			person->ChangeState(new State_Walking, "Drink");
			person->ChangeLocation("Store");
		}
		else
		{
			person->ChangeState(new State_Drink, "Drink");
		}
		
	}
	//if tired go to sleep
	else if (person->isTired) {
		std::cout << person->name << " is tired time to sleep ";
		person->ChangeState(new State_Sleep, "Sleep");
	}
	else if (person->needsSocialization && person->checkMoney() > 100 && person->people.size() < 1) {
		//sends a message to all the other chracters to check if they can socialize
		std::cout << person->name << "is going to socialize ";
		for (int i = 0; i < EntityMgr->mapsSize(); i++)
		{
			person->ChangeLocation("Resturant");
			MsgD->dispatchMessage(0, person->getID(), person->people[i], inviteToSocialize, 0);
		}
	}
	//checks if character has extra money if so go to the store and 
	else if(person->checkMoney() > 130)
	{
		std::cout << person->name << " is going to the store ";
		person->ChangeLocation("Store");
		person->ChangeState(new State_Walking, "EM");

	}
	else
	{
		//chilling
		std::cout << person->name << " is chilling " ;
	}
 }
void State_Idle::Exit(Person* person) {
	//std::cout << person->name << " is going to " << person->checkLocation() << " ";
 }

void State_ExtraMoney::Enter(Person* person) {
	//std::cout << person->name << " haves some extra money time to buy some stuff ";
	person->ChangeLocation("Store");
 }
void State_ExtraMoney::Execute(Person* person) {
	if (person->isHungry) {
		//changes state to eat state
		std::cout << person->name << " is hungry time to eat ";
		person->ChangeState(new State_Eat, "Eat");
	}
	else if (person->isThirsty)
	{
		//changes state to drink state
		std::cout << person->name << " is thirsty time to drink ";
		
		person->ChangeState(new State_Drink, "Drink");
		
	}
	else if (person->checkMoney() > 130)
	{
		//buys either food, drinks or shovels with prioritazation on drinks and food
		if (person->checkFood() <= person->checkDrink() && person->checkDrink() < 4) {
			person->decreaseMoney(foodCost);
			person->increaseFood();
			std::cout << person->name << " bought some food, now have "<< person->checkFood() << " ";
		}
		else if (person->checkFood() >= person->checkDrink() && person->checkFood() < 4) {
			person->decreaseMoney(drinkCost);
			person->increaseDrinks();
			std::cout << person->name << " bought some drinks, now have " << person->checkDrink() << " ";
		}
		else
		{
			person->decreaseMoney(shovelCost);
			person->increaseShovels();
			std::cout << person->name << " bought some shovels, now have " << person->checkShovels() << " ";
		}


	}
	else if (person->needsSocialization && person->checkMoney() > 100 && person->people.size() < 1) {
		//sends a message to all the other chracters to check if they can socialize
		std::cout << person->name << "is going to socialize ";
		for (int i = 0; i < EntityMgr->mapsSize(); i++)
		{
			person->ChangeLocation("Resturant");
			MsgD->dispatchMessage(0, person->getID(), person->people[i], inviteToSocialize, 0);
		}
	}
	else
	{
		//if character has enough money they go home and chills
		if (person->checkMoney() > 130) {
			std::cout << person->name << "is going Home ";
			person->ChangeState(new State_Walking, "Idle");
			person->ChangeLocation("Home");
		}
		//else they go to work
		else
		{
			std::cout << person->name << "is going to " << person->jobs.workPlace1 << " ";
			person->ChangeState(new State_Walking, "Work");
			person->ChangeLocation(person->jobs.workPlace1);
		}
		
	}
 }
void State_ExtraMoney::Exit(Person* person) {
	//std::cout << person->name << " is going to " << person->checkLocation() << " ";
 }

 void State_Walking::Enter(Person* person) {
	 //std::cout << person->name << " is going to " << person->checkLocation() << " ";
}
 void State_Walking::Execute(Person* person) {
	 //decreases distance to walk
	 distance--;
	 std::cout << person->name << " is walking to " << person->checkLocation() << " ";
	 //interupts the walk to resturant if the character is hungry
	 if (person->nextState == "Social" && person->isHungry) {
		 if (person->checkFood() > 0) {
			 person->ChangeState(new State_Eat, "Eat");
		 }
		 else
		 {
			 person->ChangeState(new State_Walking, "Eat");
			 person->ChangeLocation("Store");
		 }
		 
	 }
	 //interupts the walk to resturant if the character is thirsty
	 else if (person->nextState == "Social" && person->isThirsty) {
		 if (person->checkDrink() > 0) {
			 person->ChangeState(new State_Drink, "Drink");
		 }
		 else
		 {
			 person->ChangeState(new State_Walking, "Drink");
			 person->ChangeLocation("Store");
		 }
		 
		 
	 }
	 //character gets to destination
	 else if (distance <= 0) {
		 distance = 3;
		 //changes state based on what the next state should be
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