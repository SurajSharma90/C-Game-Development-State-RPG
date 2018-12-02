#include "CharacterInventoryState.h"

CharacterInventoryState::CharacterInventoryState(
Character*& character,
stack<State*>*states)
	: State(), character(character)
{
	this->states = states;
}

CharacterInventoryState::~CharacterInventoryState()
{

}

void CharacterInventoryState::printMenu() const
{
	system("CLS");
	cout << gui::msg_menutitle("Inventory Menu");

	cout
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Quit to menu.")
		<< gui::msg_menuitem(1, "Show inventory.")
		<< gui::msg_menuitem(2, "Equip item.")
		<< gui::msg_menuitem(3, "Destroy item.")
		<< gui::msg_menudivider(40, '-');
}

void CharacterInventoryState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;

	case 1:
		system("CLS");
		//cout << this->character->toStringEquipped() << "\n";
		cout << this->character->getInventory().toString() << "\n";
		system("PAUSE");
		break;

	case 2:
	{
		system("CLS");
		//cout << this->character->toStringEquipped() << "\n";
		cout << this->character->getInventory().toString() << "\n";

		int choice = this->getChoice();

		if (choice < 0 || choice >= this->character->getInventory().size())
			std::cout << gui::msg_error("No such item in inventory.");
		else
		{
			Weapon* wep = dynamic_cast<Weapon*>(this->character->getInventory().replace(choice, this->character->getWeapon()));
			
			if (wep)
			{
				this->character->setWeapon(wep);
			}
		}

		break;
	}
	default:
		system("CLS");
		cout << "Not a valid option!" << "\n";
		system("PAUSE");
		break;
	}
}

void CharacterInventoryState::update()
{
	//Print the menu
	this->printMenu();

	//Get a choice and choose valid option
	this->updateMenu();
}
