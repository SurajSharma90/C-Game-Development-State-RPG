#include "GameState.h"

GameState::GameState(Character*& character, 
	stack<State*>*states)
	: character(character)
{
	this->states = states;
}

GameState::~GameState()
{
}

//Functions
void GameState::printMenu() const
{
	system("PAUSE");
	system("CLS");
	cout << " --- GAME MENU ---" << "\n" << "\n"
		<< this->character->getMenuBar() << "\n" << "\n"
		<< " (0) Quit to main menu" << "\n"
		<< " (1) Character Stats" << "\n"
		<< " (2) Inventory" << "\n"
		<< " (3) Shop" << "\n"
		<< " (4) Travel" << "\n"
		<< " (5) Rest" << "\n" << "\n";
}

const int GameState::getChoice() const
{
	int choice = 0;

	cout << "Enter choice: ";
	cin >> choice;
	
	cin.ignore();
	cin.clear();

	return choice;
}

void GameState::updateMenu()
{
	switch (this->getChoice() | system("CLS"))
	{
	case 0:
		cout << setw(7) << " --- QUITTING GAME ---" << "\n";
		this->setQuit(true);
		break;

	case 1:
		cout << setw(7) << " --- Character Stats ---" << "\n" << "\n";
		std::cout << this->character->toString() << "\n";
		break;

	case 2:
		cout << setw(7) << " --- Inventory ---" << "\n";

		if (this->character->canLevelUp())
		{
			std::cout << "LEVEL UP!" << "\n";
		}
		break;

	default:
		cout << setw(7) << " --- No such option in menu! ---" << "\n";
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
