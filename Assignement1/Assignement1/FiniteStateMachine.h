#pragma once
class Person;

//#include "Person.h"
enum States
{
	Sleep,Work,Eat,Drink,Social
};

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

class State_Sleep : public State
{ 
private:

public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person) ;
	virtual void Exit(Person* person) ;

};

class State_Eat : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};

class State_Work : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};

class State_Drink : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};

class State_Social : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};

class State_Idle : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};

class State_ExtraMoney : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);

};

class State_Walking : public State
{
private:
public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);
	int distance = 5;
};


