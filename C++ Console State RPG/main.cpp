#include"Game.h"

//Global scope

//Main function
int main()
{
	Game game;

	//Game loop
	while (!game.getQuit())
	{
		game.update();
	}

	system("PAUSE");

	return 0; //Exit program
}