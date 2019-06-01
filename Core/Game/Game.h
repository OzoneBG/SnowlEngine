#pragma once
#include "SDL.h"
#include <string>

class Game
{
public:
	/*
	* Constructor for the game
	* @param gameName - The name of the window
	* @param windowWidth - Width size of the window in pixels
	* @param windowHeight - Height size of the window in pixels
	**/
	Game(std::string gameName, int windowWidth, int windowHeight);

	/*
	* Initializes the game, loads the assets, runs the main loop and exists
	**/
	void Run();

protected:
	virtual bool Init();
	virtual bool LoadMedia();
	virtual void HandleEvents();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Close();

private:
	bool _quit = false;

	int _screenWidth = 640;
	int _screenHeight = 480;

	std::string _gameName = "SDL";

	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

};

