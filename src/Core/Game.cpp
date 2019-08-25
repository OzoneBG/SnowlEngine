#include "Game.h"
#include "../Helpers/utils.h"

const unsigned int FPS = 120;

Game::Game()
{
}

Game::Game(std::string gameName, int windowWidth, int windowHeight)
{
	screenWidth = windowWidth;
	screenHeight = windowHeight;
	this->gameName = gameName;
}

void Game::Run()
{
    Init();

    if (!LoadContent())
    {
        printError("Failed to load media..");
        return;
    }

    sf::Clock clock;

    while(window->isOpen()) {
        float DeltaTime = clock.restart().asSeconds();

        HandleEvents();
        Update(DeltaTime);
        Render();
    }

    Close();
}

void Game::Init()
{
    window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), gameName);
    window->setFramerateLimit(FPS);
}

bool Game::LoadContent()
{
    bool success = true;

    // Load all assets here

    return success;
}

void Game::HandleEvents()
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Game::Update(float DeltaTime)
{

}

void Game::Render()
{
    window->clear(sf::Color(100, 149, 237, 255));

    // window.draw(sprite);

    window->display();
}

void Game::Close()
{
    
}