#pragma once

#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include<cmath>

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
	
	int defence;
	float dodgeChance;
	float hitRating;
	float critChance;
	float magicFind;

	int gold;

	//Skills

	//Weapon
	//Armor
	//Inventory

	//Functions
	void updateStats();

public:
	Character(std::string name, std::string bio);
	virtual ~Character();

	//Accessors

	//Modifiers
	void setPosition(const unsigned x, const unsigned y);

	//Functions
	void addExp(const unsigned exp);
	bool canLevelUp();
	const std::string getMenuBar();
	const std::string toString();
	const std::string toStringPosition();
	const std::string toStringNameBio();
	const std::string toStringStats();
};

