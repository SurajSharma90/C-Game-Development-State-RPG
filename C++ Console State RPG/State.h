#pragma once

#include<iostream>
#include<iomanip>
#include"msg_functions.h"

using namespace std;

/*
Abstract class
- Template for other state classes
*/

class State
{
private:
	bool quit;

public:
	State();
	virtual ~State();

	//Accessors
	const bool& getQuit() const;

	//Modifiers
	void setQuit(const bool quit);

	//Functions
	virtual int getChoice() const;
	virtual void update() = 0; //Pure virtual function

};