#pragma once
#include"MainMenuState.h"

using namespace std;

class Game
{
private:
	//Variables
	bool quit;
	
	Character* character;
	stack<State*> states;

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool& getQuit() const;

	//Modifiers

	//Functions
	void update();
};
