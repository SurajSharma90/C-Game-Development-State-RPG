#include "Armor.h"

#include "Weapon.h"

Armor::Armor(
	int defence,
	unsigned armor_type,
	std::string name,
	unsigned type,
	unsigned rarity,
	unsigned value)
	: Item(name, type, rarity, value)
{
	this->armorType = armor_type;
	this->defence = defence;
}

Armor::~Armor()
{

}

//Accessors
const std::string Armor::getArmorTypeAsString() const
{
	std::string typestr = "ERROR";

	switch (this->armorType)
	{
	case ARMOR_HEAD:
		typestr = "Head";
		break;

	case ARMOR_CHEST:
		typestr = "Chest";
		break;

	case ARMOR_SHOULDERS:
		typestr = "Shoulders";
		break;

	case ARMOR_ARMS :
		typestr = "Arms";
		break;

	case ARMOR_LEGS:
		typestr = "Legs";
		break;

	default:
		break;
	}

	return typestr;
}

//Functions
Armor * Armor::clone() const
{
	return new Armor(*this);
}

const std::string Armor::toString() const
{
	std::stringstream ss;

	ss << " | Name: " << this->getName()
		<< " | Defence: " << this->defence
		<< " | Type: " << this->getTypeAsString()
		<< " | Rarity: " << this->getRarityAsString() //std::string(this->getRarity(), '*')
		<< " | Value: " << this->getValue();

	return ss.str();
}

//Functions
