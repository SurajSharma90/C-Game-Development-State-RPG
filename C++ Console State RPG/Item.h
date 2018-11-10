#pragma once

#include<string>
#include<sstream>

enum item_types {WEAPON = 0, ARMOR};
enum item_rarities {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, MYTHIC};

class Item
{
private:
	std::string name;
	unsigned type;
	unsigned rarity;
	unsigned value;

	void generate();

public:
	Item(std::string name,
		unsigned type,
		unsigned rarity,
		unsigned value);
	virtual ~Item();

	//Accessors
	const std::string& getName();
	const unsigned& getType();
	const unsigned& getRarity();
	const unsigned& getValue();

	//Functions
	const std::string toString() const;
};

