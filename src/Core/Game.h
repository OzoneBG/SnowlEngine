#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();

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
    virtual void Init();
	virtual bool LoadContent();
	virtual void HandleEvents();
	virtual void Update(float DeltaTime);
	virtual void Render();
	virtual void Close();

private:
    bool quit = false;

    int screenWidth = 640;
	int screenHeight = 480;

	std::string gameName = "SFML";

    sf::RenderWindow* window = nullptr;
};