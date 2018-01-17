#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <thread>
#include <iostream>
#include <chrono>

#include "Texture.h"
#include "TetrisBoard.h"

class Game
{
	public:
		Game();
		Game(std::string windowTitle, int windowWidth, int windowHeight);
		~Game();

		bool Game_Init();
		void Game_Run();
		void Game_Draw();
		void Game_LoadMedia();
	private:
		std::string _windowTitle;
		int _windowWidth;
		int _windowHeight;
		bool _running;
		SDL_Event _e;
		int _boardPositionX;
		int _boardPositionY;

		TetrisBoard _board;
		Texture _blockTexture;
		SDL_Window* _window;
		SDL_Surface* _windowSurface;
		SDL_Renderer* _renderer;
};

