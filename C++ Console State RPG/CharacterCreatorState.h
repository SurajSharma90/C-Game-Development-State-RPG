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
	const unsigned maxCharacters;
	vector<Character*>* characterList;
	unsigned& activeCharacter;
	stack<State*>*states;

public:
	CharacterCreatorState(
		vector<Character*>* characterList,
		unsigned& activeCharacter,
		stack<State*>* states);
	virtual ~CharacterCreatorState();

	//Functions
	void createCharacter();
	void printMenu();
	void updateMenu();
	void update();
};

