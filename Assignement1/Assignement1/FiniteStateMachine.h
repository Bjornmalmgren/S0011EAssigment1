#pragma once
#include "Person.h"
#include <iostream>
using namespace std;
class State
{

public:
	virtual void Enter(Person*) = 0;
	virtual void Execute(Person*) = 0;
	virtual void Exit(Person*) = 0;


};

class State_Sleep : public State
{ 
private:

public:
	virtual void Enter(Person* person);
	virtual void Execute(Person* person);
	virtual void Exit(Person* person);
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



