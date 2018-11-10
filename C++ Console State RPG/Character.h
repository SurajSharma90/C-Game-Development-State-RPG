#pragma once

#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>

#include"Inventory.h"

//(50/3) * (pow(x, 3) - 6*pow(x, 2) + (x * 17) - 12);

class Character
{
private:
	//location
	unsigned x;
	unsigned y;

	//core
	std::string name;
	std::string bio;
	int level;
	int exp;
	int expNext;
	int statpoints;

	//Stats
	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int mana;
	int manaMax;

	//attributes
	int strenght; //Damage
	int vitality; //HP and stamina
	int agility; //Defence and doge chance
	int dexterity; //Hit chance and crit
	int intelligence; //Mana, magic find
	
	int damageMin;
	int damageMax;
	int defence;
	float hitRating;
	float critChance;
	float magicFind;

	int gold;

	//Skills

	//Weapon
	//Armor

	//Inventory
	Inventory inventory;

	//Functions
	void updateStats();

public:
	Character(std::string name, std::string bio);
	virtual ~Character();

	//Accessors
	inline const unsigned getSeed() const { return this->x + this->y; };
	inline const unsigned getX() const { return this->x; }
	inline const unsigned getY() const { return this->y; }
	inline const int getLevel() const { return this->level; }
	inline const bool isDead() const { return this->hp <= 0; }
	inline const int getHP() const { return this->hp; }
	inline const int getHPMax() const { return this->hpMax; }
	inline const int getStamina() const { return this->stamina; }
	inline const int getDamageMin() const { return this->damageMin; }
	inline const int getDamageMax() const { return this->damageMax; }
	inline const int getDefence() const { return this->defence; }
	inline const int getHitRating() const { return this->hitRating; }
	inline Inventory& getInventory() { return this->inventory; }

	//Modifiers
	void setPosition(const unsigned x, const unsigned y);
	void move(const int x, const int y);

	//Functions
	const std::string flee();
	void reset();
	void takeDamage(const int damage);
	void setDead();
	void addExp(const unsigned exp);
	bool canLevelUp();
	const std::string getMenuBar();
	const std::string toString();
	const std::string toStringPosition();
	const std::string toStringNameBio();
	const std::string toStringStats();
};

