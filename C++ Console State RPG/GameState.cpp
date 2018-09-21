#include "GameState.h"

GameState::GameState(
	Character*& character, 
	stack<State*>*states)
	: State(), character(character)
{
	this->states = states;
}

GameState::~GameState()
{
}

//Functions
void GameState::printMenu() const
{
	system("CLS");
	cout << " --- GAME MENU ---" << "\n" << "\n"
		<< this->character->getMenuBar() << "\n" << "\n"
		<< " (0) Quit to Main Menu" << "\n"
		<< " (1) Character Menu" << "\n"
		<< " (2) Shop Menu" << "\n"
		<< " (3) Travel Menu" << "\n"
		<< " (4) Rest Menu" << "\n" << "\n";
}

void GameState::updateMenu()
{
	switch (this->getChoice())
	{
	case 0:
		this->setQuit(true);
		break;

	case 1:
		this->states->push(new CharacterMenuState(this->character, this->states));
		break;

	case 2:
		
		break;

	default:
		system("CLS");
		cout << "Not a valid option!" << "\n";
		system("PAUSE");
		break;
	}
}

void GameState::update()
{
	//Print the menu
	this->printMenu();

	//Get a choice and choose valid option
	this->updateMenu();
}
