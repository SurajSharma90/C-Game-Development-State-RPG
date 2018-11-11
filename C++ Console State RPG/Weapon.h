#pragma once
#include "Item.h"
class Weapon :
	public Item
{
private:
	int damageMax;
	int damageMin;

public:
	Weapon(
		int damageMin,
		int damageMax,
		std::string name,
		unsigned type,
		unsigned rarity,
		unsigned value);

	virtual ~Weapon();

	//Functions
};

