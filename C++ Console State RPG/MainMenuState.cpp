#include "MainMenuState.h"

MainMenuState::MainMenuState(Character*& character,
	stack<State*>* states)
	: character(character)
{
	this->states = states;
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::printMenu()
{
	system("PAUSE");
	system("CLS");
	cout << " --- Main Menu ---" << "\n" << "\n"
		<< " (0) Quit to desktop" << "\n"
		<< " (1) Start Game" << "\n"
		<< " (2) Create Character" << "\n" << "\n";
}

const int MainMenuState::getChoice() const
{
	int choice = 0;

	cout << "Enter choice: ";
	cin >> choice;

	cin.ignore();
	cin.clear();

	return choice;
}

void MainMenuState::updateMenu()
{
	switch (this->getChoice() | system("CLS"))
	{
	case 0:
		this->setQuit(true);
		break;
	case 1:
		if (this->character != nullptr)
			this->states->push(new GameState(this->character, this->states));
		else
			cout << "Error! Create a character first!" << "\n";
		break;
	case 2:
		this->states->push(new CharacterCreatorState(this->character, this->states));
		break;
	default:
		cout << "Not a valid option! " << "\n";
		break;
	}
}

//Functions
void MainMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}