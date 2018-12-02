#include "Character.h"

//Private functions
void Character::updateStats()
{
	this->hpMax = this->vitality * 10 + this->vitality;
	//this->hp = this->hpMax;
	this->staminaMax = this->vitality * 2;
	this->stamina = this->staminaMax;
	this->manaMax = this->vitality * 10 + this->vitality;
	this->mana = this->manaMax;

	this->damageMin = this->strength * 2;
	this->damageMax = this->strength + this->strength * 2;

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
	this->exp = 0;
	this->expNext = 46;
	this->statpoints = 5;
	this->location = -1;

	this->strength = 1;
	this->vitality = 1;
	this->agility = 1;
	this->dexterity = 1;
	this->intelligence = 1;

	this->gold = 100;

	this->weapon = new Weapon(2, 4, "Sword", WEAPON, COMMON, 200);

	this->updateStats();
	this->resetHP();

	this->inventory.add(Weapon(5, 10, "Super-Sword", WEAPON, RARE, 500));

	//Initialize attributes and core stats
}

Character::~Character()
{
	delete this->weapon;
}

//Accessors
const int Character::getAttribute(const unsigned attribute)
{
	switch (attribute)
	{
	case STRENGTH:
		return this->strength;
		break;
	case VITALITY:
		return this->vitality;
		break;
	case AGILITY:
		return this->agility;
		break;
	case DEXTERITY:
		return this->dexterity;
		break;
	case INTELLIGENCE:
		return this->intelligence;
		break;
	default:
		return -1;
		break;
	}
}

const int Character::getDamageMin() const
{
	if (this->weapon)
		return this->damageMin + this->weapon->getDamageMin();

	return this->damageMin;
}

const int Character::getDamageMax() const
{
	if (this->weapon)
		return this->damageMax + this->weapon->getDamageMax();

	return this->damageMax;
}

const int Character::getTotalDamage() const
{
	if(this->weapon)
		return rand() % ((this->damageMax + this->weapon->getDamageMax()) - (this->damageMin + this->weapon->getDamageMin())) + (this->damageMin + this->weapon->getDamageMin());

	return rand() % (this->damageMax - this->damageMin) + this->damageMin;
}

Weapon* Character::getWeapon() 
{
	return this->weapon;
}

//Modifiers
void Character::setLocation(const int location)
{
	this->location = location;
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

void Character::setWeapon(Weapon * weapon)
{
	this->weapon = weapon;
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

void Character::resetHP()
{
	this->hp = this->hpMax;
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

bool Character::addExp(const unsigned exp)
{
	bool levelup = false;

	this->exp += exp;

	while (this->exp >= this->expNext)
	{
		this->level++;
		this->exp -= this->expNext;
		this->expNext = (50 / 3) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12);
		this->statpoints++;

		this->strength += this->level % 2;
		this->vitality += this->level % 2;
		this->agility += this->level % 2;
		this->dexterity += this->level % 2;
		this->intelligence += this->level % 2;

		levelup = true;

		this->updateStats();
		this->resetHP();
	}

	return levelup;
}

bool Character::addStatpoint(const unsigned attribute)
{
	if (this->statpoints > 0)
	{
		this->statpoints--;

		switch (attribute)
		{
		case STRENGTH:
			this->strength++;
			break;
		case VITALITY:
			this->vitality++;
			break;
		case AGILITY:
			this->agility++;
			break;
		case DEXTERITY:
			this->dexterity++;
			break;
		case INTELLIGENCE:
			this->intelligence++;
			break;
		default:
			this->statpoints++;
			return false;
			break;
		}

		this->updateStats();
		this->resetHP();

		return true;
	}

	return false;
}

const std::string Character::getMenuBar(const bool show_attributes)
{
	std::stringstream ss;

	int expDone = 10 * (static_cast<float>(this->exp) / this->expNext);
	int expRemain = 10 - expDone;

	ss
		<< std::string(4, ' ') << " | Name: " << this->name << "\n"
		<< std::string(4, ' ') << " | Level: " << this->level << " [" << std::string(expDone, '=') << std::string(expRemain, '-') << "]" << "\n"
		<< std::string(4, ' ') << " | HP: " << this->hp << " / " << this->hpMax << "\n"
		<< std::string(4, ' ') << " | Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
		<< std::string(4, ' ') << " | Stat points available: " << this->statpoints << "\n";
	
	if (show_attributes)
	{
		ss
			<< "\n"
			<< std::string(4, ' ') << " | Strength: " << this->strength << "\n"
			<< std::string(4, ' ') << " | Vitality: " << this->vitality << "\n"
			<< std::string(4, ' ') << " | Agility: " << this->agility << "\n"
			<< std::string(4, ' ') << " | Dexterity: " << this->dexterity << "\n"
			<< std::string(4, ' ') << " | Intelligence: " << this->intelligence << "\n";
	}

	ss << "\n";

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

		<< " Strenght: " << this->strength << "\n"
		<< " Vitality: " << this->vitality << "\n"
		<< " Agility: " << this->agility << "\n"
		<< " Dexterity: " << this->dexterity << "\n"
		<< " Intelligence: " << this->intelligence << "\n"
		<< "\n"

		<< " HP: " << this->hp << " / " << this->hpMax << "\n"
		<< " Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
		<< " Mana: " << this->mana << " / " << this->manaMax << "\n"
		<< "\n";

	if (this->weapon)
	{
		ss << " Weapon: " << this->weapon->toString() << "\n"
			<< "\n";

		ss << " Damage: " << this->damageMin + this->weapon->getDamageMin() << " (" << this->damageMin << ") " 
			<< " - " << this->damageMax + this->weapon->getDamageMax() << " (" << this->damageMax << ") "
			<< "\n";
	}
	else
	{
		ss << " Weapon: " << "None equipped" << "\n"
			<< "\n";

		ss << " Damage: " << this->damageMin << " - " << this->damageMax
			<< "\n";
	}
	
		ss << " Defence: " << this->defence << "\n"
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

		<< " Strenght: " << this->strength << "\n"
		<< " Vitality: " << this->vitality << "\n"
		<< " Agility: " << this->agility << "\n"
		<< " Dexterity: " << this->dexterity << "\n"
		<< " Intelligence: " << this->intelligence << "\n"
		<< "\n"

		<< " HP: " << this->hp << " / " << this->hpMax << "\n"
		<< " Stamina: " << this->stamina << " / " << this->staminaMax << "\n"
		<< " Mana: " << this->mana << " / " << this->manaMax << "\n"
		<< "\n";

		if (this->weapon)
		{
			ss << " Weapon: " << this->weapon->toString() << "\n"
				<< "\n";

			ss << " Damage: " << this->damageMin + this->weapon->getDamageMin() << " (" << this->damageMin << ") "
				<< " - " << this->damageMax + this->weapon->getDamageMax() << " (" << this->damageMax << ") "
				<< "\n";
		}
		else
		{
			ss << " Weapon: " << "None equipped" << "\n"
				<< "\n";

			ss << " Damage: " << this->damageMin << " - " << this->damageMax
				<< "\n";
		}

		ss << " Defence: " << this->defence << "\n"
		<< " Hit rating: " << this->hitRating << "\n"
		<< " Crit chance: " << this->critChance << "\n"
		<< " Magic find: " << this->magicFind << "\n"
		<< "\n"

		<< " Gold: " << this->gold << "\n"
		<< "\n";

	return ss.str();
}

const std::string Character::toStringEquipped() const
{
	std::stringstream ss;

	if (this->weapon)
	{
		ss << " Weapon: " << this->weapon->toString() << "\n"
			<< "\n";
	}
	else
	{
		ss << " Weapon: " << "None equipped" << "\n"
			<< "\n";
	}

	return ss.str();
}
