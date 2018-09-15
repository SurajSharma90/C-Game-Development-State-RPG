#pragma once

#include<string>
#include<iostream>
#include<vector>
#include<sstream>

class Character
{
private:
	//core
	std::string name;
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
	Character(std::string name);
	virtual ~Character();

	const std::string getMenuBar();
	const std::string toString();
};

