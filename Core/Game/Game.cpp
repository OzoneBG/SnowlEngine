#include "Game.h"
#include "../Utils/CoreUtils.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

Game::Game(std::string gameName, int windowWidth, int windowHeight)
{
	_screenWidth = windowWidth;
	_screenHeight = windowHeight;
	_gameName = gameName;
}

void Game::Run()
{
	if (!this->Init())
	{
		printf("Failed to init!\n");
	}
	else
	{
		if (!LoadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Uint32 lastTime = SDL_GetTicks();

			while (!_quit)
			{
				Uint32 current = SDL_GetTicks();
				float deltaTime = ((current - lastTime) * 1000 / (double)SDL_GetPerformanceFrequency());

				HandleEvents();
				Update(deltaTime);
				Render();

				lastTime = current;
			}
		}
	}

	Close();
}

bool Game::Init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		DisplayError("SDL could not initialize!");
		success = false;
	}
	else
	{
		_window = SDL_CreateWindow(_gameName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
		if (_window == nullptr)
		{
			DisplayError("Window could not be created!");
			success = false;
		}
		else
		{
			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
		}
	}

	return success;
}

bool Game::LoadMedia()
{
	bool success = true;

	//Load all assets here

	return success;
}

void Game::HandleEvents()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
		{
			_quit = true;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			//Probably create some kind of InputManager
		}
	}
}

void Game::Update(float deltaTime)
{
	
}

void Game::Render()
{
	//Clear screen
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);

	//Display screen
	SDL_RenderPresent(_renderer);
}

void Game::Close()
{
	//Destroy the window and quit SDL
	SDL_DestroyWindow(_window);
	_window = nullptr;

	SDL_Quit();
}
