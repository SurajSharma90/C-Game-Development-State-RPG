#include "CharacterCreatorState.h"

CharacterCreatorState::CharacterCreatorState(
	vector<Character*>* characterList,
	unsigned& activeCharacter,
	stack<State*>* states)
	: State(), activeCharacter(activeCharacter), maxCharacters(5)
{
	this->characterList = characterList;
	this->states = states;
}

CharacterCreatorState::~CharacterCreatorState()
{

}

//Functions
void CharacterCreatorState::createCharacter()
{
	if (this->characterList->size() < this->maxCharacters)
	{
		string name = "";
		string bio = "";

		cout << " Name: ";
		getline(cin, name);

		cout << " Biography: ";
		getline(cin, bio);

		this->characterList->push_back(new Character(name, bio));

		cout << " Character " << name << " created." << "\n" << "\n";
	}
	else
	{
		cout << " Max number of characters reached!" << "\n";
	}
}

void CharacterCreatorState::printMenu()
{
	system("CLS");
	cout << " --- Character Creator ---" << "\n" << "\n"
		<< " Characters: " << to_string(this->characterList->size()) << " / " << to_string(this->maxCharacters) << "\n" << "\n"
		<< " (-1) Back to menu" << "\n"
		<< " (1) New Character" << "\n" << "\n";
}

void CharacterCreatorState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;
	case 1:
		system("CLS");
		this->createCharacter();
		system("PAUSE");
		break;
	default:
		system("CLS");
		cout << "Not a valid option! " << "\n";
		system("PAUSE");
		break;
	}
}

void CharacterCreatorState::update()
{
	this->printMenu();
	this->updateMenu();
}
