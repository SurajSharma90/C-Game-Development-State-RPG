#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stack>
#include "State.h"
#include "Character.h"
#include "CharacterMenuState.h"
#include "TravelMenuState.h"

using namespace std;

class GameState :
	public State
{
private:
	Character *& character;
	stack<State*>*states;

public:
	GameState(Character*& character, stack<State*>*states);
	virtual ~GameState();

	//Functions
	void printMenu() const;
	void updateMenu();
	void update();
};

