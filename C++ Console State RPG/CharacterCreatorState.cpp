#include "CharacterCreatorState.h"

CharacterCreatorState::CharacterCreatorState(Character*& character,
	stack<State*>* states)
	: character(character)
{
	this->states = states;
}

CharacterCreatorState::~CharacterCreatorState()
{

}

//Functions
void CharacterCreatorState::createCharacter()
{
	string name = "";
	string bio = "";

	cout << "Name: ";
	getline(cin, name);

	cout << "Biography: ";
	getline(cin, bio);

	delete this->character;
	this->character = new Character(name, bio);

	cout << "Character " << name << " created." << "\n" << "\n";
}

void CharacterCreatorState::printMenu()
{
	system("PAUSE");
	system("CLS");

	cout << " --- Character Creator ---" << "\n" << "\n"
		<< " (0) Back to menu" << "\n"
		<< " (1) New Character" << "\n" << "\n";
}

const int CharacterCreatorState::getChoice() const
{
	int choice = 0;

	cout << "Enter choice: ";
	cin >> choice;

	cin.ignore();
	cin.clear();

	return choice;
}

void CharacterCreatorState::updateMenu()
{
	switch (this->getChoice() | system("CLS"))
	{
	case 0:
		this->setQuit(true);
		break;
	case 1:
		this->createCharacter();
		break;
	default:
		cout << "Not a valid option! " << "\n";
		break;
	}
}


void CharacterCreatorState::update()
{
	this->printMenu();
	this->updateMenu();
}
