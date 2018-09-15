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
Character::Character(std::string name)
{
	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = 100;
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

//Functions
const std::string Character::getMenuBar()
{
	std::stringstream ss;

	ss << "Name: " << this->name << " | "
		<< "Level: " << this->level << " | "
		<< "Exp: " << this->exp << " / " << this->expNext << " | "
		<< "HP: " << this->hp << " / " << this->hpMax << " | "
		<< "Stamina: " << this->stamina << " / " << this->staminaMax;

	return ss.str();
}

const std::string Character::toString()
{
	/* Function will format all member variables and
	send them out as a string to be printed.
	*/

	std::stringstream ss;

	ss << "Name: " << this->name << "\n"
		<< "Level: " << this->level << "\n"
		<< "Exp: " << this->exp << " / " << this->expNext << "\n"
		<< "\n"

		<< "Strenght: " << this->strenght << "\n"
		<< "Vitality: " << this->vitality << "\n"
		<< "Agility: " << this->agility << "\n"
		<< "Dexterity: " << this->dexterity << "\n"
		<< "Intelligence: " << this->intelligence << "\n"
		<< "\n"

		<< "HP: " << this->hp << " / " << this->hpMax << "\n"
		<< "Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
		<< "Mana: " << this->mana << " / " << this->manaMax << "\n"
		<< "\n"

		<< "Defence: " << this->defence << "\n"
		<< "Dodge chance: " << this->dodgeChance << "\n"
		<< "Hit rating: " << this->hitRating << "\n"
		<< "Crit chance: " << this->critChance << "\n"
		<< "Magic find: " << this->magicFind << "\n"
		<< "\n"

		<< "Gold: " << this->gold << "\n"
		<< "\n";

	return ss.str();
}
