#include "MainMenuState.h"

MainMenuState::MainMenuState(
	vector<Character*>* characterList,
	unsigned& activeCharacter,
	stack<State*>* states)
	: State(), activeCharacter(activeCharacter)
{
	this->characterList = characterList;
	this->states = states;

	//FOR DEVELOPMENT PURPOUSES
	this->characterList->push_back(new Character("TEST", "DEBUGGING CHARACTER"));
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::printMenu()
{
	system("CLS");
	cout << gui::msg_menutitle("Main Menu");

	if (!this->characterList->empty())
		cout << this->characterList->at(this->activeCharacter)->getMenuBar();
	else
		cout << gui::msg_error("No character selected.");

	cout 
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Quit to desktop. ")
		<< gui::msg_menuitem(1, "Start game. ")
		<< gui::msg_menuitem(2, "Create character. ")
		<< gui::msg_menuitem(3, "Select character. ")
		<< gui::msg_menudivider(40, '-');
}

void MainMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;
	case 1:
		if (!this->characterList->empty())
			this->states->push(new GameState(this->characterList->at(this->activeCharacter), this->states));
		else
		{
			system("CLS");
			cout << "  [[ (!) Error. Create a character first. ]]" << "\n";
			system("PAUSE");
		}
		break;
	case 2:
		this->states->push(new CharacterCreatorState(this->characterList, this->activeCharacter, this->states));
		break;
	case 3:
		this->states->push(new CharacterSelectorState(this->characterList, this->activeCharacter, this->states));
		break;
	default:
		system("CLS");
		cout << "  [[ (!) Not a valid option. ]]" << "\n";
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