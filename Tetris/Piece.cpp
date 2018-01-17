#include "Piece.h"



Piece::Piece()
{
	/*_piece[0][0] = EMPTY;
	_piece[0][1] = EMPTY;
	_piece[0][2] = EMPTY;
	_piece[0][3] = EMPTY;
	_piece[1][0] = EMPTY;
	_piece[1][1] = RED;
	_piece[1][2] = RED;
	_piece[1][3] = EMPTY;
	_piece[2][0] = EMPTY;
	_piece[2][1] = EMPTY;
	_piece[2][2] = EMPTY;
	_piece[2][3] = EMPTY;
	_piece[3][0] = EMPTY;
	_piece[3][1] = EMPTY;
	_piece[3][2] = EMPTY;
	_piece[3][3] = EMPTY;*/
	_pieces[0][0] = EMPTY;
	_pieces[0][1] = GREEN;
	_pieces[0][2] = EMPTY;
	_pieces[0][3] = EMPTY;
	_pieces[0][4] = GREEN;
	_pieces[0][5] = GREEN;
	_pieces[0][6] = GREEN;
	_pieces[0][7] = EMPTY;
	_pieces[0][8] = EMPTY;
	_pieces[0][9] = EMPTY;
	_pieces[0][10] = EMPTY;
	_pieces[0][11] = EMPTY;
	_pieces[0][12] = EMPTY;
	_pieces[0][13] = EMPTY;
	_pieces[0][14] = EMPTY;
	_pieces[0][15] = EMPTY;

	_pieces[1][0] = RED;
	_pieces[1][1] = RED;
	_pieces[1][2] = RED;
	_pieces[1][3] = RED;
	_pieces[1][4] = EMPTY;
	_pieces[1][5] = EMPTY;
	_pieces[1][6] = EMPTY;
	_pieces[1][7] = EMPTY;
	_pieces[1][8] = EMPTY;
	_pieces[1][9] = EMPTY;
	_pieces[1][10] = EMPTY;
	_pieces[1][11] = EMPTY;
	_pieces[1][12] = EMPTY;
	_pieces[1][13] = EMPTY;
	_pieces[1][14] = EMPTY;
	_pieces[1][15] = EMPTY;

	_pieces[2][0] = BLUE;
	_pieces[2][1] = BLUE;
	_pieces[2][2] = EMPTY;
	_pieces[2][3] = EMPTY;
	_pieces[2][4] = EMPTY;
	_pieces[2][5] = BLUE;
	_pieces[2][6] = BLUE;
	_pieces[2][7] = EMPTY;
	_pieces[2][8] = EMPTY;
	_pieces[2][9] = EMPTY;
	_pieces[2][10] = EMPTY;
	_pieces[2][11] = EMPTY;
	_pieces[2][12] = EMPTY;
	_pieces[2][13] = EMPTY;
	_pieces[2][14] = EMPTY;
	_pieces[2][15] = EMPTY;

	_pieces[3][0] = EMPTY;
	_pieces[3][1] = EMPTY;
	_pieces[3][2] = EMPTY;
	_pieces[3][3] = EMPTY;
	_pieces[3][4] = YELLOW;
	_pieces[3][5] = YELLOW;
	_pieces[3][6] = EMPTY;
	_pieces[3][7] = EMPTY;
	_pieces[3][8] = YELLOW;
	_pieces[3][9] = YELLOW;
	_pieces[3][10] = EMPTY;
	_pieces[3][11] = EMPTY;
	_pieces[3][12] = EMPTY;
	_pieces[3][13] = EMPTY;
	_pieces[3][14] = EMPTY;
	_pieces[3][15] = EMPTY;

	_pieces[4][0] = MAGENTA;
	_pieces[4][1] = MAGENTA;
	_pieces[4][2] = MAGENTA;
	_pieces[4][3] = EMPTY;
	_pieces[4][4] = MAGENTA;
	_pieces[4][5] = EMPTY;
	_pieces[4][6] = EMPTY;
	_pieces[4][7] = EMPTY;
	_pieces[4][8] = EMPTY;
	_pieces[4][9] = EMPTY;
	_pieces[4][10] = EMPTY;
	_pieces[4][11] = EMPTY;
	_pieces[4][12] = EMPTY;
	_pieces[4][13] = EMPTY;
	_pieces[4][14] = EMPTY;
	_pieces[4][15] = EMPTY;

	_pieces[5][0] = ORANGE;
	_pieces[5][1] = ORANGE;
	_pieces[5][2] = ORANGE;
	_pieces[5][3] = EMPTY;
	_pieces[5][4] = EMPTY;
	_pieces[5][5] = EMPTY;
	_pieces[5][6] = ORANGE;
	_pieces[5][7] = EMPTY;
	_pieces[5][8] = EMPTY;
	_pieces[5][9] = EMPTY;
	_pieces[5][10] = EMPTY;
	_pieces[5][11] = EMPTY;
	_pieces[5][12] = EMPTY;
	_pieces[5][13] = EMPTY;
	_pieces[5][14] = EMPTY;
	_pieces[5][15] = EMPTY;

	_pieces[6][0] = EMPTY;
	_pieces[6][1] = PINK;
	_pieces[6][2] = PINK;
	_pieces[6][3] = EMPTY;
	_pieces[6][4] = PINK;
	_pieces[6][5] = PINK;
	_pieces[6][6] = EMPTY;
	_pieces[6][7] = EMPTY;
	_pieces[6][8] = EMPTY;
	_pieces[6][9] = EMPTY;
	_pieces[6][10] = EMPTY;
	_pieces[6][11] = EMPTY;
	_pieces[6][12] = EMPTY;
	_pieces[6][13] = EMPTY;
	_pieces[6][14] = EMPTY;
	_pieces[6][15] = EMPTY;

	_pieceNo = 0;
	_currentRotation = 0;
}


Piece::~Piece()
{
}

Color Piece::getPieceData(int i, int j)
{
	switch (_currentRotation)
	{
		case 0: return _pieces[_pieceNo][i * PIECE_SIZE + j];
		case 1: return _pieces[_pieceNo][12 + i - (j * PIECE_SIZE)];
		case 2: return _pieces[_pieceNo][15 - (i * PIECE_SIZE) - j];
		case 3: return _pieces[_pieceNo][3 - i + (j * PIECE_SIZE)];
	}
	printf("%d ", _pieceNo);
	//return _piece[i * 4 + j];
}

void Piece::rotatePiece()
{
	_currentRotation = (_currentRotation + 1) % 4;
}

void Piece::reverseRotation()
{
	_currentRotation = ((_currentRotation + 4) - 1) % 4;
}

void Piece::randomizePiece()
{
	srand(time(NULL));

	_pieceNo = rand() % 7;
}
