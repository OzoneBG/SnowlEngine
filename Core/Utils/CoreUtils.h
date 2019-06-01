#pragma once
#include <string>
#include <stdio.h>
#include "SDL.h"

void DisplayError(std::string message)
{
	printf("%s", message);
	printf(" Error: %s\n", SDL_GetError());
}