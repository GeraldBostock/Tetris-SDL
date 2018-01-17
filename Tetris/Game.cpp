#include "Game.h"



Game::Game()
{
	_windowTitle = "Tetris";
	_windowWidth = 800;
	_windowHeight = 850;
	_boardPositionX = 50;
	_boardPositionY = 50;
}

Game::Game(std::string windowTitle, int windowWidth, int windowHeight)
{
	_windowTitle = windowTitle;
	_windowWidth = windowWidth;
	_windowHeight = windowHeight;
}


Game::~Game()
{
}

bool Game::Game_Init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Could not initialize SDL. SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		_window = SDL_CreateWindow(_windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN);
		if (_window == NULL)
		{
			printf("Could not create window. SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (_renderer == NULL)
			{
				printf("Could not initialize renderer. SDL_Error: %s", SDL_GetError());
				success = 0;
			}
			else
			{
				SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("Could not initialize SDL_Image. SDL_Image error: %s", IMG_GetError());
					success = false;
				}
				else
				{
					_windowSurface = SDL_GetWindowSurface(_window);

					SDL_FillRect(_windowSurface, NULL, SDL_MapRGB(_windowSurface->format, 0xFF, 0xFF, 0xFF));
				}
			}
		}
	}
	_running = true;

	Game_LoadMedia();

	return success;
}

void Game::Game_LoadMedia()
{
	_blockTexture.loadFromFile("res/block.png", _renderer, 0.35f);
	_board.setTexture(_blockTexture);
}

void Game::Game_Run()
{
	while (_running)
	{
		while (SDL_PollEvent(&_e) != 0)
		{
			if (_e.type == SDL_QUIT) _running = false;
			_board.handleInput(_e);
		}

		_board.update();
		Game_Draw();
	}
}

void Game::Game_Draw()
{
	SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(_renderer);

	_board.draw(_renderer);

	SDL_RenderPresent(_renderer);
}
