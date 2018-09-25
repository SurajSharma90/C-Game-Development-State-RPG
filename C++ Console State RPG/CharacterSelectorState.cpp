#include "CharacterSelectorState.h"

CharacterSelectorState::CharacterSelectorState(
	vector<Character*>* characterList,
	unsigned& activeCharacter,
	stack<State*>* states)
	: State(), 
	characterList(characterList), 
	activeCharacter(activeCharacter), 
	states(states)
{

}

CharacterSelectorState::~CharacterSelectorState()
{

}

//Functions
void CharacterSelectorState::printMenu()
{
	system("CLS");
	cout << " --- Character Selector ---" << "\n" << "\n";
	
	cout << " (-1) Back to menu" << "\n";

	if (!this->characterList->empty())
	{
		for (size_t i = 0; i < this->characterList->size(); i++)
		{
			cout << " (" << i << ") " << this->characterList->at(i)->getMenuBar() << "\n";
		}
		cout << "\n";
	}
}

void CharacterSelectorState::updateMenu()
{
	if (!this->characterList->empty())
	{
		int choice = this->getChoice();

		if (choice < 0)
		{
			this->setQuit(true);
		}
		else if (choice >= 0 && choice < this->characterList->size())
		{
			this->activeCharacter = choice;
			this->setQuit(true);
			cout << " Character " << choice << " selected." << "\n" << "\n";
			system("pause");
		}
		else
		{
			cout << " Error: Choice out of bounds! " << "\n" << "\n";
			system("pause");
		}
	}
	else
	{
		this->setQuit(true);
		cout << " No characters created!" << "\n" << "\n";
		system("pause");
	}
}

void CharacterSelectorState::update()
{
	this->printMenu();
	this->updateMenu();
}
