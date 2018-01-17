#include "Input.h"



Input::Input()
{
	_upPressed = false;
	_downPressed = false;
	_leftPressed = false;
	_rightPressed = false;

	_leftFrame = 0;
	_rightFrame = 0;

	for (int i = 0; i < 322; i++) { // init them all to false
		KEYS[i] = false;
	}
}


Input::~Input()
{
}

ArrowKeys Input::getPress(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_r:
				_rPressed = true;
				break;
			case SDLK_UP:
				_upPressed = true;
				break;
			case SDLK_DOWN:
				return DOWN;
				_downPressed = true;
				_downFrame++;
				if (_downFrame >= 5) return DOWN;
				break;
			case SDLK_LEFT:
				return LEFT;
				_leftPressed = true;
				_leftFrame++;
				if (_leftFrame >= 5) return LEFT;
				break;
			case SDLK_RIGHT:
				return RIGHT;
				_rightPressed = true;
				_rightFrame++;
				if (_rightFrame >= 5) return RIGHT;
				break;
		}
	}
	else if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_r:
				if (_rPressed)
				{
					_rPressed = false;
					return RESET;
				}
				break;
			case SDLK_UP:
				if (_upPressed)
				{
					_upPressed = false;
					return UP;
				}
				break;
			case SDLK_DOWN:
				if (_downPressed) 
				{
					_downPressed = false;
					_downFrame = 0;
					return DOWN;
				}
				break;
			case SDLK_RIGHT:
				if (_rightPressed)
				{
					_rightPressed = false;
					_rightFrame = 0;
					return RIGHT;
				}
				break;
			case SDLK_LEFT:
				if (_leftPressed)
				{
					_leftPressed = false;
					_leftFrame = 0;
					return LEFT;
				}
				break;
		}
	}
}
