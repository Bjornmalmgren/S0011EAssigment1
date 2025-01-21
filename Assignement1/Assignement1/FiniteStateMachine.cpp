#include "FiniteStateMachine.h"
void State_Sleep::Enter(Person* person) {
	
	cout << "Ahh time to sleep" << endl;
	person->ChangeLocation("Home");
}
void State_Sleep::Execute(Person* person) {
	cout << "ZZZ..." << endl;
	person->decreaseFatigue(1);
	if (person->isTired = !true) {
		if (person->isHungry) {
			person->ChangeState(new State_Eat());
		}
		else if (person->isThirsty) {
			person->ChangeState(new State_Drink());
		}
		else if(person->needsSocialization)
		{
			person->ChangeState(new State_Social());
		}
		else
		{
			person->ChangeState(new State_Work());
			person->choseJob();
			
		}
	}

}
void State_Sleep::Exit(Person* person) {

	cout << "Ahh I'm well rested" << endl;
}


void State_Eat::Enter(Person* person) {

	cout << "I need food" << endl;
}
void State_Eat::Execute(Person* person) {
	if(person->isHungry && person->checkFood() == 0) {
		person->ChangeLocation("Store");
		person->decreaseMoney(6);
		person->decreaseHunger(30);
	}
	else if(person->isHungry && person->checkFood() > 0)
	{
		person->decreaseFood(1);
		person->decreaseFood(1);
	}
	else
	{
		person->ChangeState(new State_Work());
		person->choseJob();
	}
}
void State_Eat::Exit(Person* person) {

	cout << "Ahh I'm full" << endl;
}

void State_Work::Enter(Person* person) {


}
void State_Work::Execute(Person* person) {
	//say something

	if (person->isTired) {
		person->ChangeState(new State_Sleep());
	
		//say something
	}
	else
	{
		//work

	}
}
void State_Work::Exit(Person* person) {


}

void State_Drink::Enter(Person* person) {


}
void State_Drink::Execute(Person* person) {

}
void State_Drink::Exit(Person* person) {


}

void State_Social::Enter(Person* person) {


}
void State_Social::Execute(Person* person) {

}
void State_Social::Exit(Person* person) {


}