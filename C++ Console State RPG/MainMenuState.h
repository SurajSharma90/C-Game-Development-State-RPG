#pragma once
#include<iostream>
#include<iomanip>
#include<stack>
#include"CharacterCreatorState.h"
#include"GameState.h"

using namespace std;

class MainMenuState
	: public State
{
private:
	vector<Character*>* characterList;
	unsigned& activeCharacter;
	stack<State*>* states;

public:
	MainMenuState(
		vector<Character*>* characterList,
		unsigned& activeCharacter,
		stack<State*>* states);
	virtual ~MainMenuState();

	void printMenu();
	void updateMenu();
	void update();
};

