#pragma once
#include<iostream>
#include<iomanip>
#include<stack>
#include<ctime>
#include "Character.h"
#include "State.h"

using namespace std;

class TravelMenuState :
	public State
{
private:
	Character *& character;
	stack<State*>*states;

public:
	TravelMenuState(
		Character*& character,
		stack<State*>* states);
	virtual ~TravelMenuState();

	//Functions
	void travel();

	void printMenu();
	void updateMenu();
	void update();
};

