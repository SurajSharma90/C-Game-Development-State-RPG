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

	this->defence = this->agility;
	this->dodgeChance = static_cast<float>(this->agility)/60;
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

//Functions
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

		<< " Defence: " << this->defence << "\n"
		<< " Dodge chance: " << this->dodgeChance << "\n"
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

		<< " Defence: " << this->defence << "\n"
		<< " Dodge chance: " << this->dodgeChance << "\n"
		<< " Hit rating: " << this->hitRating << "\n"
		<< " Crit chance: " << this->critChance << "\n"
		<< " Magic find: " << this->magicFind << "\n"
		<< "\n"

		<< " Gold: " << this->gold << "\n"
		<< "\n";

	return ss.str();
}
