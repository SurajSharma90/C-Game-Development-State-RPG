#include "Game.h"

//Constructors and Destructors
Game::Game()
{
	quit = false;
	
	this->character = nullptr;

	this->states.push(new MainMenuState(this->character, &this->states));
}

Game::~Game()
{
	delete this->character;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//Accessor
const bool& Game::getQuit() const
{
	return this->quit;
}

//Modifier

//Functions
void Game::update()
{
	this->states.top()->update();
	if (this->states.top()->getQuit())
	{
		delete this->states.top();
		this->states.pop();
	}

	if (this->states.empty())
		this->quit = true;
}