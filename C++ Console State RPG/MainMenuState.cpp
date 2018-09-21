#include "MainMenuState.h"

MainMenuState::MainMenuState(
	vector<Character*>* characterList,
	unsigned& activeCharacter,
	stack<State*>* states)
	: State(), activeCharacter(activeCharacter)
{
	this->characterList = characterList;
	this->states = states;
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::printMenu()
{
	system("CLS");
	cout << " --- Main Menu ---" << "\n" << "\n";

	if (!this->characterList->empty())
		cout << this->characterList->at(this->activeCharacter)->getMenuBar() << "\n" << "\n";
	else
		cout << " No character selected!" << "\n" << "\n";

	cout << " (0) Quit to desktop" << "\n"
		<< " (1) Start Game" << "\n"
		<< " (2) Create Character" << "\n" << "\n";
}

void MainMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case 0:
		this->setQuit(true);
		break;
	case 1:
		if (!this->characterList->empty())
			this->states->push(new GameState(this->characterList->at(this->activeCharacter), this->states));
		else
		{
			system("CLS");
			cout << "Error! Create a character first!" << "\n";
			system("PAUSE");
		}
		break;
	case 2:
		this->states->push(new CharacterCreatorState(this->characterList, this->activeCharacter, this->states));
		break;
	default:
		system("CLS");
		cout << "Not a valid option! " << "\n";
		system("PAUSE");
		break;
	}
}

//Functions
void MainMenuState::update()
{
	this->printMenu();
	this->updateMenu();
}