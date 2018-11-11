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
	cout << gui::msg_menutitle("Game Menu");

	cout << this->character->getMenuBar();

	cout
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Quit to main menu.")
		<< gui::msg_menuitem(1, "Character Menu.")
		<< gui::msg_menuitem(2, "Shop Menu.")
		<< gui::msg_menuitem(3, "Travel Menu.")
		<< gui::msg_menuitem(4, "Rest Menu.")
		<< gui::msg_menudivider(40, '-');
}

void GameState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;

	case 1:
		this->states->push(new CharacterMenuState(this->character, this->states));
		break;

	case 2:
		
		break;

	case 3:
		this->states->push(new TravelMenuState(this->character, this->states));
		break;

	case 4:
		system("cls");
		this->character->reset();
		cout << "You have rested..." << "\n";
		system("pause");
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
