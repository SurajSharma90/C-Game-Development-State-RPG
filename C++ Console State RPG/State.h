#pragma once

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
	virtual void update() = 0; //Pure virtual function

};