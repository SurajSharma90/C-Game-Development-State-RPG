#include "TravelMenuState.h"

TravelMenuState::TravelMenuState(
	Character*& character,
	stack<State*>* states)
	: character(character), State()
{
	this->states = states;
}

TravelMenuState::~TravelMenuState()
{

}

//Functions
void TravelMenuState::travel()
{
	//Move character

	//Get randomly generated location

	//Change player variables
}

void TravelMenuState::printMenu()
{
	system("CLS");
	cout << " --- Travel Menu ---" << "\n" << "\n"
		<< this->character->getMenuBar() << "\n" << "\n"
		<< " (-1) Back to menu" << "\n" 
		<< " (0) Travel" << "\n" << "\n";
}

void TravelMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;
	default:
		system("CLS");
		cout << "Not a valid option! " << "\n";
		system("PAUSE");
		break;
	}
}

void TravelMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}