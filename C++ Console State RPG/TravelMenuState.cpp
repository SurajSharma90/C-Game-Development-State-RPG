#include "TravelMenuState.h"

TravelMenuState::TravelMenuState(
	Character*& character,
	stack<State*>* states)
	: character(character), State()
{
	this->states = states;
	this->locationString = "NONE";
	this->nrOfLocations = 5;
}

TravelMenuState::~TravelMenuState()
{

}

//Functions
void TravelMenuState::travel()
{
	//Move character

	//Get randomly generated location

	//Change player variables
}

void TravelMenuState::printMenu()
{
	system("CLS");
	cout << gui::msg_menutitle("Travel Menu");

	cout
		<< this->character->getMenuBar();

	cout
		<< "\n"
		<< std::string(4, ' ') << this->character->toStringPosition()
		<< "\n"
		<< std::string(4, ' ') << "Location: " << this->locationString << "\n"
		<< "\n"
		<< std::string(4, ' ') << "Minimap: " << "\n" << this->minimapString << "\n";

	cout
		<< gui::msg_menudivider(40, '-')
		<< gui::msg_menuitem(-1, "Back to menu")
		<< gui::msg_menuitem(1, "UP")
		<< gui::msg_menuitem(2, "DOWN")
		<< gui::msg_menuitem(3, "LEFT")
		<< gui::msg_menuitem(4, "RIGHT");
}

void TravelMenuState::updateEncounterMenu()
{
	if (!this->getQuit())
	{
		srand(this->character->getSeed());
		int location = rand() % this->nrOfLocations;

		switch (location)
		{
		case EMPTY:
		{
			this->locationString = "You are in an empty plane.";

			int randomnr = rand() % 2;
			if (randomnr)
			{
				system("cls");
				std::cout << "ENEMY ENCOUTERED!" << "\n";
				system("pause");

				this->states->push(new CombatState(this->character, this->states));
			}
			break;
		}
		case FARM:
			this->locationString = "You are on a farm.";
			break;
		case CITY:
			this->locationString = "You are in a city.";
			break;
		case SHOP:
			this->locationString = "You find a shop.";
			break;
		case CHEST:
			this->locationString = "You found a chest!.";
			break;
		default:
			cout << "ERROR NO SUCH LOCATION!" << "\n";
			system("pause");
			break;
		}
	}
}

void TravelMenuState::updateMinimap()
{
	int startX = this->character->getX() - 2;
	if (startX < 0)
		startX = 0;

	int startY = this->character->getY() - 2;
	if (startY < 0)
		startY = 0;

	int endX = this->character->getX() + 2;
	int endY = this->character->getY() + 2;

	stringstream ss;

	for (size_t y = startY; y <= endY; y++)
	{
		for (size_t x = startX; x <= endX; x++)
		{
			srand(x + y);
			int location = rand() % this->nrOfLocations;

			if (x == this->character->getX() && y == this->character->getY())
				ss << "(P) ";
			else
			{
				switch (location)
				{
				case EMPTY:
					ss << "Em ";
					break;
				case FARM:
					ss << "Fa ";
					break;
				case CITY:
					ss << "Ci ";
					break;
				case SHOP:
					ss << "Sh ";
					break;
				case CHEST:
					ss << "Ch ";
					break;
				}
			}
		}

		ss << "\n";
	}

	this->minimapString = ss.str();
}

void TravelMenuState::updateMenu()
{
	switch (this->getChoice())
	{
	case -1:
		this->setQuit(true);
		break;
	case 1:
		this->character->move(0, -1);
		break;
	case 2:
		this->character->move(0, 1);
		break;
	case 3:
		this->character->move(-1, 0);
		break;
	case 4:
		this->character->move(1, 0);
		break;
	default:
		system("CLS");
		cout << "Not a valid option! " << "\n";
		system("PAUSE");
		break;
	}
}

void TravelMenuState::update()
{	
	this->updateMinimap();
	this->printMenu();
	this->updateMenu();
	this->updateEncounterMenu();
}