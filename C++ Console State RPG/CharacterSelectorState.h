#pragma once

#include<iostream>
#include<iomanip>
#include<stack>
#include<vector>

#include"Character.h"
#include "State.h"

class CharacterSelectorState :
	public State
{
private:
	vector<Character*>* characterList;
	unsigned& activeCharacter;
	stack<State*>* states;

public:
	CharacterSelectorState(
		vector<Character*>* characterList,
		unsigned& activeCharacter,
		stack<State*>* states);

	virtual ~CharacterSelectorState();

	//Functions

	void printMenu();
	void updateMenu();
	void update();
};

