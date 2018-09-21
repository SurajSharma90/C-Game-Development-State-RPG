#pragma once
#include"MainMenuState.h"

using namespace std;

class Game
{
private:
	//Variables
	bool quit;
	
	unsigned activeCharacter;
	vector<Character*> characterList;
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
