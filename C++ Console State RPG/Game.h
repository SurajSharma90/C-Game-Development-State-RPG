#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include"State.h"
#include"Character.h"

using namespace std;

class Game
{
private:
	//Variables
	bool quit;
	vector<State> states;
	State* currentState;

	Character* character;

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool& getQuit() const;

	//Modifiers

	//Functions
	void printMenu() const;
	const int getChoice() const;
	void updateMenu();
	void update();
};
