#include "Character.h"

//Private functions
void Character::updateStats()
{
	this->hpMax = this->vitality * 10 + this->vitality;
	this->hp = this->hpMax;
	this->staminaMax = this->vitality * 2;
	this->stamina = this->staminaMax;
	this->manaMax = this->vitality * 10 + this->vitality;
	this->mana = this->manaMax;

	this->damageMin = this->strenght * 2;
	this->damageMax = this->strenght + this->strenght * 2;
	this->defence = this->agility * 2;
	this->hitRating = this->dexterity * 2 + this->dexterity;
	this->critChance = static_cast<float>(this->dexterity) / 60;
	this->magicFind = static_cast<float>(this->intelligence) / 70;
}

//Constructors and Destructors
Character::Character(std::string name, std::string bio)
{
	this->x = 0;
	this->y = 0;

	this->name = name;
	this->bio = bio;
	this->level = 1;
	this->exp = 1000;
	this->expNext = 46;
	this->statpoints = 0;

	this->strenght = 1;
	this->vitality = 1;
	this->agility = 1;
	this->dexterity = 1;
	this->intelligence = 1;

	this->gold = 0;

	this->updateStats();

	this->inventory.add(Item("test", 0, 1, 200));

	//Initialize attributes and core stats
}

Character::~Character()
{

}

void Character::setPosition(const unsigned x, const unsigned y)
{
	this->x = x;
	this->y = y;
}

void Character::move(const int x, const int y)
{
	if (static_cast<int>(this->x) + x < 0)
		this->x = 0;
	else
		this->x += x;

	if (static_cast<int>(this->y) + y < 0)
		this->y = 0;
	else
		this->y += y;
}

//Functions
const std::string Character::flee()
{
	std::stringstream ss;
	int lostExp = rand() % (this->level * 5) + 1;
	int lostGold = rand() % (this->level * 5) + 1;
	ss << " Exp lost: " << lostExp << " | " << " Gold lost: " << lostGold;

	this->exp -= lostExp;;

	if (this->exp < 0)
		this->exp = 0;

	this->gold -= lostGold;

	if (this->gold < 0)
		this->gold = 0;

	return ss.str();
}

void Character::reset()
{
	this->hp = this->hpMax;
	this->stamina = this->staminaMax;
	this->mana = this->manaMax;
}

void Character::takeDamage(const int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
		this->setDead();
}

void Character::setDead()
{
	this->hp = 0;

	//Do some other stuff
	this->exp -= rand()% (this->level * 10) + 1;

	if (this->exp < 0)
		this->exp = 0;

	this->gold -= rand() % (this->level * 10) + 1;

	if (this->gold < 0)
		this->gold = 0;
}

void Character::addExp(const unsigned exp)
{
	this->exp += exp;
}

bool Character::canLevelUp()
{
	if (this->exp >= this->expNext)
	{
		this->level++;
		this->exp -= this->expNext;
		this->expNext = (50 / 3) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12);
		this->statpoints++;

		return true;
	}

	return false;
}

const std::string Character::getMenuBar()
{
	std::stringstream ss;

	ss << " Name: " << this->name << " | "
		<< "Level: " << this->level << " | "
		<< "Exp: " << this->exp << " / " << this->expNext << " | "
		<< "HP: " << this->hp << " / " << this->hpMax << " | "
		<< "Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
		<< " Stat points available: " << this->statpoints;

	return ss.str();
}

const std::string Character::toString()
{
	/* Function will format all member variables and
	send them out as a string to be printed.
	*/

	std::stringstream ss;

	ss << " Name: " << this->name << "\n" << "\n"
		<< " Bio: " << this->bio << "\n" << "\n"
		<< " Level: " << this->level << "\n"
		<< " Exp: " << this->exp << " / " << this->expNext << "\n"
		<< "\n"

		<< " Strenght: " << this->strenght << "\n"
		<< " Vitality: " << this->vitality << "\n"
		<< " Agility: " << this->agility << "\n"
		<< " Dexterity: " << this->dexterity << "\n"
		<< " Intelligence: " << this->intelligence << "\n"
		<< "\n"

		<< " HP: " << this->hp << " / " << this->hpMax << "\n"
		<< " Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
		<< " Mana: " << this->mana << " / " << this->manaMax << "\n"
		<< "\n"

		<< " Damage: " << this->damageMin << " - " << this->damageMax << "\n"
		<< " Defence: " << this->defence << "\n"
		<< " Hit rating: " << this->hitRating << "\n"
		<< " Crit chance: " << this->critChance << "\n"
		<< " Magic find: " << this->magicFind << "\n"
		<< "\n"

		<< " Gold: " << this->gold << "\n"
		<< "\n";

	return ss.str();
}

const std::string Character::toStringPosition()
{
	std::stringstream ss;

	ss << " x: " << this->x << " y: " << this->y << "\n";

	return ss.str();
}

const std::string Character::toStringNameBio()
{
	std::stringstream ss;

	ss << " Name: " << this->name << "\n" << "\n"
		<< " Bio: " << this->bio << "\n" << "\n";

	return ss.str();
}

const std::string Character::toStringStats()
{
	std::stringstream ss;

	ss << " Level: " << this->level << "\n"
		<< " Exp: " << this->exp << " / " << this->expNext << "\n" 
		<< "\n"

		<< " Strenght: " << this->strenght << "\n"
		<< " Vitality: " << this->vitality << "\n"
		<< " Agility: " << this->agility << "\n"
		<< " Dexterity: " << this->dexterity << "\n"
		<< " Intelligence: " << this->intelligence << "\n"
		<< "\n"

		<< " HP: " << this->hp << " / " << this->hpMax << "\n"
		<< " Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
		<< " Mana: " << this->mana << " / " << this->manaMax << "\n"
		<< "\n"

		<< " Damage: " << this->damageMin << " - " << this->damageMax << "\n"
		<< " Defence: " << this->defence << "\n"
		<< " Hit rating: " << this->hitRating << "\n"
		<< " Crit chance: " << this->critChance << "\n"
		<< " Magic find: " << this->magicFind << "\n"
		<< "\n"

		<< " Gold: " << this->gold << "\n"
		<< "\n";

	return ss.str();
}
