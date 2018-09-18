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
	Character *& character;
	stack<State*>*states;

public:
	MainMenuState(Character*& character,
		stack<State*>* states);
	virtual ~MainMenuState();

	void printMenu();
	const int getChoice() const;
	void updateMenu();
	void update();
};

