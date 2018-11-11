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

	cout << std::string(4, ' ') << " | - [[ Enter choice: ";
	cin >> setw(1) >> choice;

	while (!cin.good())
	{
		cout << " ERROR: Faulty Input!" << "\n";

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << std::string(4, ' ') << " | - [[ Enter choice: ";
		cin >> setw(1) >> choice;
	}

	std::cout << "\n";

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	
	return choice;
}
