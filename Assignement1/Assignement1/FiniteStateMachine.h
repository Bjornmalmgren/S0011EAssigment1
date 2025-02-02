#pragma once
//forward declaration
class Person;

//Base state which all other states are derived from
class State
{

public:
	virtual void Enter(Person* person) = 0;
	virtual void Execute(Person* person) = 0;
	virtual void Exit(Person* person) = 0;
	int foodCost = 80;
	int drinkCost = 60;
	int shovelCost = 130;
	
};
//sleep state when the character is tired
class State_Sleep : public State
{ 
private:

public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person) ;
	virtual void Exit(Person* person) ;

};
//eat state when the characters need to eat
class State_Eat : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};
//work state when the chracter needs money for food, water or other things
class State_Work : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};
//drink state when the chracter needs to drink
class State_Drink : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};
//social state when they need to be social
class State_Social : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};
//idle state when the chracter have nothing to do
class State_Idle : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};
//extramoney state which triggers when the character have extra money to spend
class State_ExtraMoney : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};
//walking state between diffrent states
class State_Walking : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);
	int distance = 3;
};


