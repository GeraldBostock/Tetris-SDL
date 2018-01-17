#pragma once
#include <SDL.h>
#include <stdio.h>

enum ArrowKeys
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	RESET
};

class Input
{
	bool KEYS[322];

	public:
		Input();
		~Input();

		ArrowKeys getPress(SDL_Event e);

	private:
		bool _leftPressed;
		bool _rightPressed;
		bool _upPressed;
		bool _downPressed;
		bool _rPressed;

		int _downFrame;
		int _rightFrame;
		int _leftFrame;
};

