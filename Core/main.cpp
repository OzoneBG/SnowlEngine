#include <stdio.h>
#include <string>
#include "Game/Game.h"

int main(int argc, char* args[])
{
	Game* TheGame = new Game("Snowl Engine", 800, 600);

	TheGame->Run();

	return 0;
}