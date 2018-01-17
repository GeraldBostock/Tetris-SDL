#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	bool loadFromFile(std::string filePath, SDL_Renderer* render, float scale);
	void free();
	void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	SDL_Texture* getTexture();
	void setTexture(SDL_Texture* texture);

	int getWidth();
	int getHeight();

	void setWidth(int width);
	void setHeight(int height);

private:
	SDL_Texture* _texture;
	SDL_Renderer* _renderer;

	int _textureWidth;
	int _textureHeight;
};

