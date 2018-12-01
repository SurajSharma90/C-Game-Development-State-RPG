#pragma once

#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stack>
#include "State.h"
#include "Character.h"

using namespace std;

class CharacterInventoryState :
	public State
{
private:
	Character * & character;
	stack<State*>*states;

public:
	CharacterInventoryState(Character*& character, stack<State*>*states);

	virtual ~CharacterInventoryState();

	//Functions
	void printMenu() const;
	void updateMenu();
	void update();
};

