#pragma once
#include<iostream>
#include<iomanip>
#include<stack>
#include "Character.h"
#include "State.h"

using namespace std;

class CharacterStatMenuState :
	public State
{
private:
	Character *&character;
	stack<State*> *states;

public:
	CharacterStatMenuState(
		Character*& character,
		stack<State*>* states);
	virtual ~CharacterStatMenuState();

	//Functions
	void printMenu();
	void updateMenu();
	void update();
};

