#include "CharacterMenuState.h"

CharacterMenuState::CharacterMenuState(
	Character*& character,
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
	cout << gui::msg_menutitle("Character Menu");

	cout << this->character->getMenuBar();

	cout
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Back to menu.")
		<< gui::msg_menuitem(1, "Name & Bio.")
		<< gui::msg_menuitem(2, "Stats.")
		<< gui::msg_menuitem(3, "Assign statpoints.")
		<< gui::msg_menuitem(4, "Inventory.")
		<< gui::msg_menudivider(40, '-');
}

void CharacterMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
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
		this->states->push(new CharacterStatMenuState(this->character, this->states));
		break;
	case 4:
		system("CLS");
		cout << this->character->getInventory().toString() << "\n";
		system("PAUSE");
		break;
	default:
		system("CLS");
		cout << gui::msg_error("Not a valid option.");
		system("PAUSE");
		break;
	}
}

void CharacterMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}
