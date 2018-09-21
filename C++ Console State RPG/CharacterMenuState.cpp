#include "CharacterMenuState.h"

CharacterMenuState::CharacterMenuState(Character*& character,
	stack<State*>* states)
	: character(character), State()
{
	this->states = states;
}

CharacterMenuState::~CharacterMenuState()
{

}

//Functions
void CharacterMenuState::printMenu()
{
	system("CLS");
	cout << " --- Character Menu ---" << "\n" << "\n"
		<< this->character->getMenuBar() << "\n" << "\n"
		<< " (0) Back to menu" << "\n"
		<< " (1) Name & Bio" << "\n"
		<< " (2) Stats" << "\n"
		<< " (3) Assign statpoints" << "\n"
		<< " (4) Level Up" << "\n" << "\n";
}

void CharacterMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case 0:
		this->setQuit(true);
		break;
	case 1:
		system("CLS");
		cout << this->character->toStringNameBio() << "\n";
		system("PAUSE");
		break;
	case 2:
		system("CLS");
		cout << this->character->toStringStats() << "\n";
		system("PAUSE");
		break;
	case 3:

		break;
	case 4:
		if (this->character->canLevelUp())
		{
			system("CLS");
			cout << " - LEVEL UP - !"  << "\n";
			system("PAUSE");
		}
		else
		{
			system("CLS");
			cout << " - Not enough EXP! - " << "\n";
			system("PAUSE");
		}
		break;
	default:
		system("CLS");
		cout << "Not a valid option! " << "\n";
		system("PAUSE");
		break;
	}
}

void CharacterMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}
