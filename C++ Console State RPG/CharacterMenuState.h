#pragma once

#include<iostream>
#include<iomanip>
#include<stack>
#include "Character.h"
#include "CharacterStatMenuState.h"
#include "CharacterInventoryState.h"

using namespace std;

class CharacterMenuState :
	public State
{
private:
	Character *& character;
	stack<State*>*states;

public:
	CharacterMenuState(Character*& character,
		stack<State*>* states);
	virtual ~CharacterMenuState();

	//Functions
	void printMenu();
	void updateMenu();
	void update();
};
