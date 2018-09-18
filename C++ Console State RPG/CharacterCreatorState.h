#pragma once

#include<iostream>
#include<iomanip>
#include<stack>
#include "Character.h"
#include "State.h"

using namespace std;

class CharacterCreatorState :
	public State
{
private:
	Character *& character;
	stack<State*>*states;

public:
	CharacterCreatorState(Character*& character,
		stack<State*>* states);
	virtual ~CharacterCreatorState();

	//Functions
	void createCharacter();
	void printMenu();
	const int getChoice() const;
	void updateMenu();
	void update();
};

