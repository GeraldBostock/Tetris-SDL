#pragma once
#include <SDL.h>
#include <time.h>
#include <stdlib.h>

#include "Color.h"
#include "Texture.h"

#define PIECE_SIZE 4

class Piece
{
	public:
		Piece();
		~Piece();

		Color getPieceData(int i, int j);
		void randomizePiece();
		void rotatePiece();
		void reverseRotation();

	private:
		unsigned char _pieceNo;
		unsigned char _currentRotation;

		Color _piece[16];
		Color _pieces[7][16];
};

