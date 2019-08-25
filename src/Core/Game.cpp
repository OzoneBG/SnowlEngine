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

    SpawnActors();

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

    textureManager = new TextureManager();
}

bool Game::LoadContent()
{
    // Load all assets here
    if(!textureManager->LoadTexture("wood", "wood_texture.jpg"))
    {
        return false;
    }

    return true;
}

void Game::SpawnActors()
{
    Actor* woodPlank = new Actor("wood", textureManager);
    woodPlank->BeginPlay();

    Actors.push_back(woodPlank);
}

void Game::HandleEvents()
{
    sf::Event event;
    while(window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();

        for(auto actor : Actors)
        {
            actor->HandleEvents(event);
        }   

    }
}

void Game::Update(float DeltaTime)
{
    for(auto actor : Actors)
    {
        actor->Tick(DeltaTime);
    }

}

void Game::Render()
{
    window->clear(sf::Color(100, 149, 237, 255));

    for(auto actor : Actors)
    {
        window->draw(*actor->GetSprite());
    }

    window->display();
}

void Game::Close()
{
    textureManager->UnloadTextures();
    
    for(auto actor : Actors)
    {
        actor->Destroy();
    }
}