#include "CombatState.h"

CombatState::CombatState(
	Character*& character,
	stack<State*>* states)
	: character(character), State()

{
	this->states = states;
}

CombatState::~CombatState()
{

}

//functions
void CombatState::beginCombat()
{
	Enemy enemy(this->character->getLevel());
	bool endCombat = false;

	int turn = rand() % 2;
	int round = 0;

	srand(time(NULL));

	while (!endCombat)
	{
		//Test for player attacking and enemy defending
		string atkStr = "Player";
		string defStr = "Enemy";
		float hitRating = static_cast<float>(this->character->getHitRating());
		float defence = static_cast<float>(enemy.getDefence());

		if (!turn)
		{
			atkStr = "Enemy";
			defStr = "Player";
			hitRating = static_cast<float>(enemy.getHitRating());
			defence = static_cast<float>(this->character->getDefence());
		}

		float totalHitDef = hitRating + defence;
		float hitPercent = 100.f * (hitRating / totalHitDef);
		float defPercent = 100.f * (defence / totalHitDef);

		int random = rand() % 100 + 1;

		system("cls");
		cout << "-------------------------------------------------" << "\n";
		cout << " Attacker: " << atkStr << "\n";
		cout << " Defender: " << defStr << "\n";
		cout << " Round: " << ++round << "\n";
		cout << "-------------------------------------------------" << "\n";

		//Hit
		if (random > 0 && random <= hitPercent)
		{
			int damage = 0;

			if (turn)
			{
				damage = character->getTotalDamage();
				enemy.takeDamage(damage);
			}
			else
			{
				damage = rand() % (enemy.getDamageMax() - enemy.getDamageMin()) + enemy.getDamageMin();
				this->character->takeDamage(damage);
			}

			cout << atkStr << " HIT " << defStr << " FOR " << damage << "!" << "\n";
		}
		//Defend
		else
		{
			cout << atkStr << " MISSED " << defStr << "\n";
		}

		//Data
		cout << "-------------------------------------------------" << "\n";
		cout << " Hit rating: " << hitRating << " Percent: " << hitPercent << "\n";
		cout << " Defence: " << defence << " Percent: " << defPercent << "\n";
		cout << " Player Damage: " << this->character->getDamageMin() << " - " << this->character->getDamageMax() << "\n";
		cout << " Enemy Damage: " << enemy.getDamageMin() << " - " << enemy.getDamageMax() << "\n";
		cout << " Player HP: " << this->character->getHP() << " / " << this->character->getHPMax() << "\n";
		cout << " Enemy HP: " << enemy.getHP() << " / " << enemy.getHPMax() << "\n";
		cout << "-------------------------------------------------" << "\n";

		//Loss
		if (this->character->isDead())
		{
			endCombat = true;
			cout << "YOU ARE DEAD AND YOU LOST SOME EXP AND GOLD!" << "\n";
			this->setQuit(true);
		}
		//Win
		else if (enemy.isDead())
		{
			endCombat = true;
			int gainedExp = rand() % (enemy.getLevel() * 20) + (enemy.getLevel() * 10);
			this->character->addExp(gainedExp);
			cout << "YOU DEFEATED THE ENEMY AND GAINED " << gainedExp << " EXP!" << "\n";
			this->setQuit(true);
		}

		//Switch turn
		turn = turn ? false : true;

		system("pause");
	}
}

void CombatState::printMenu()
{
	system("CLS");
	cout << " --- Combat Menu ---" << "\n" << "\n";
	cout << this->character->getMenuBar() << "\n" << "\n";
	cout << " (1) Begin Combat" << "\n"
		<< " (2) Flee" << "\n"
		<< " (3) Heal" << "\n"
		<< "\n";
}

void CombatState::updateMenu()
{
	switch (this->getChoice())
	{
	case 1:
		this->beginCombat();
		cout << "END OF COMBAT." << "\n";
		system("pause");
		//this->setQuit(true);
		break;

	case 2:
		system("cls");
		cout << "You fled and lost some valuables..." << "\n";
		cout << this->character->flee() << "\n";
		system("pause");
		this->setQuit(true);
		break;

	case 3:
		system("cls");
		this->character->reset();
		cout << "(TESTING) You have rested..." << "\n";
		system("pause");
		break;

	default:
		system("CLS");
		cout << "Not a valid option! " << "\n";
		system("PAUSE");
		break;
	}
}

//Functions


void CombatState::update()
{
	this->printMenu();
	this->updateMenu();
}
