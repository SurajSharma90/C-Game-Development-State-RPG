#include "State.h"

State::State()
{
	this->quit = false;
}

State::~State()
{

}

const bool & State::getQuit() const
{
	return this->quit;
}

void State::setQuit(const bool quit)
{
	this->quit = quit;
}

int State::getChoice() const
{
	int choice = 0;

	cout << " - Enter choice: ";
	cin >> setw(1) >> choice;

	while (!cin.good())
	{
		cout << " ERROR: Faulty Input!" << "\n";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << " - Enter choice: ";
		cin >> setw(1) >> choice;
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	return choice;
}
