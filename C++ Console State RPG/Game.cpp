#include "Game.h"

//Constructors and Destructors
Game::Game()
{
	quit = false;
	this->currentState = nullptr;
	
	this->character = new Character("Suraj");
}

Game::~Game()
{
	delete this->character;
}

//Accessor
const bool& Game::getQuit() const
{
	return this->quit;
}

//Modifier

//Functions
void Game::printMenu() const
{
	system("PAUSE");
	system("CLS");
	cout << "--- MAIN MENU ---" << "\n" << "\n"
		<< "= | " << this->character->getMenuBar() << " | =" << "\n" << "\n"
		<< "(0) Quit" << "\n"
		<< "(1) Character Stats" << "\n"
		<< "(2) Inventory" << "\n"
		<< "(3) Shop" << "\n"
		<< "(4) Travel" << "\n"
		<< "(5) Rest" << "\n" << "\n";
}

const int Game::getChoice() const
{
	int choice = 0;

	cout << "Enter choice: ";
	cin >> choice;

	return choice;
}

void Game::updateMenu()
{
	switch (this->getChoice() | system("CLS"))
	{
	case 0:
		cout << "--- QUITTING GAME ---" << "\n";
		this->quit = true;
		break;

	case 1:
		cout << "--- Character Stats ---" << "\n" << "\n";
		std::cout << this->character->toString() << "\n";
		break;

	case 2:
		cout << "--- Inventory ---" << "\n";
		break;

	default:
		cout << "--- No such option in menu! ---" << "\n";
		break;
	}
}

void Game::update()
{
	//Print the menu
	this->printMenu();

	//Get a choice and choose valid option
	this->updateMenu();
}