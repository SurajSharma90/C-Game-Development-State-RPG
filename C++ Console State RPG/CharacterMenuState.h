#pragma once
#include"State.h"
#include<iostream>

class CharacterMenuState : public State
{
private:
public:
	CharacterMenuState()
		: State()
	{

	}

	void update()
	{
		std::cout << "From CHARACTER MENU!";
	}
};