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

//Functions