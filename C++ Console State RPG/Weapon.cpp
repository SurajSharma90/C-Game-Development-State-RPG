#include "Weapon.h"

Weapon::Weapon(
	int damageMin,
	int damageMax,
	std::string name,
	unsigned type,
	unsigned rarity,
	unsigned value)
	: Item(name, type, rarity, value)
{
	this->damageMax = damageMax;
	this->damageMin = damageMin;
}

Weapon::~Weapon()
{

}

const std::string Weapon::toString()
{
	std::stringstream ss;

	ss << this->getName() << " | Rarity: " << this->getRarity() << " | Damage: " << this->damageMin << " - " << this->damageMax;

	return ss.str();
}

//Functions