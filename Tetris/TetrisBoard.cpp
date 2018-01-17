#include "TetrisBoard.h"

TetrisBoard::TetrisBoard()
{
	_posX = 50;
	_posY = 50;
	resetGame();

	_piecePosY = -1;
	_piecePosX = 4;
	_frame = 0;
}


TetrisBoard::~TetrisBoard()
{
}

void TetrisBoard::randomizeBoard()
{
	srand(time(NULL));

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			//_boardArray[i][j] = rand() % 2;
		}
	}
}

void TetrisBoard::initBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			if (i == 0) _boardArray[i][j] = BORDER;
			else if (i == BOARD_WIDTH - 1) _boardArray[i][j] = BORDER;
			else if (j == BOARD_HEIGHT - 1) _boardArray[i][j] = BORDER;
			else _boardArray[i][j] = EMPTY;
		}
	}
}

void TetrisBoard::setTexture(Texture texture)
{
	_block.setTexture(texture.getTexture());
	_block.setWidth(texture.getWidth());
	_block.setHeight(texture.getHeight());
}

void TetrisBoard::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_Rect rect{ _posX, _posY, BOARD_WIDTH*BLOCK_SIZE + 2, BOARD_HEIGHT*BLOCK_SIZE + 2 };
	//SDL_RenderDrawRect(renderer, &rect);

	for (int i = 0; i < PIECE_SIZE; i++)
	{
		for (int j = 0; j < PIECE_SIZE; j++)
		{
			if (piece.getPieceData(i, j) != EMPTY)
			{
				setColor(piece.getPieceData(i, j));
				_block.render(_posX + (_piecePosX + j) * BLOCK_SIZE + 1, _posY + (_piecePosY + i) * BLOCK_SIZE + 1, renderer, NULL);
			}
		}
	}

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			if (_boardArray[i][j] != EMPTY)
			{
				setColor(_boardArray[i][j]);
				_block.render(_posX + i * BLOCK_SIZE + 1, _posY + j * BLOCK_SIZE + 1, renderer, NULL);
			}
		}
	}
}

bool TetrisBoard::isOccupied(int i, int j)
{
	if (_boardArray[i][j]) return true;
	else return false;
}

void TetrisBoard::update()
{
	if ((_frame % PER_FRAME) == 0 )
	{
		if(canPlace(_piecePosX, _piecePosY + 1))
			_piecePosY += 1;
		else
		{
			for (int i = 0; i < PIECE_SIZE; i++)
			{
				for (int j = 0; j < PIECE_SIZE; j++)
				{
					if (piece.getPieceData(i, j) != EMPTY)
						_boardArray[_piecePosX + j][_piecePosY + i] = piece.getPieceData(i, j);
				}

				if (isLineFull(i + _piecePosY))
				{
					for (int j = 1; j < BOARD_WIDTH - 1; j++)
						_boardArray[j][_piecePosY + i] = WHITE;

					shiftBoard(i + _piecePosY);
				}
			}
			_piecePosX = 4;
			_piecePosY = 0;
			piece.randomizePiece();
		}
	}
	_frame++;
	if (_frame >= PER_FRAME) _frame = 0;
}

void TetrisBoard::handleInput(SDL_Event e)
{
	ArrowKeys input = _input.getPress(e);

	switch (input)
	{
	case RIGHT:
		if (canPlace(_piecePosX + 1, _piecePosY)) _piecePosX++;
		break;
	case LEFT:
		if (canPlace(_piecePosX - 1, _piecePosY)) _piecePosX--;
		break;
	case DOWN:
		if (canPlace(_piecePosX, _piecePosY + 1)) _piecePosY++;
		break;
	case UP:
		piece.rotatePiece();
		if (!canRotate())
			piece.reverseRotation();
		break;
	case RESET:
		resetGame();
		break;
	}
}

bool TetrisBoard::isLineFull(int i)
{
	if (i == BOARD_HEIGHT - 1) return false;

	for (int j = 0; j < BOARD_WIDTH; j++)
	{
		if (_boardArray[j][i] == EMPTY) return false;
	}

	return true;
}

bool TetrisBoard::canPlace(int newPosX, int newPosY)
{
	for (int i = 0; i < PIECE_SIZE; i++)
	{
		for (int j = 0; j < PIECE_SIZE; j++)
		{
			if (newPosX + j >= 0 && newPosX + j < BOARD_WIDTH)
			{
				if (newPosY + i >= 0 && newPosY + i < BOARD_HEIGHT)
				{
					if (piece.getPieceData(i, j) != EMPTY && _boardArray[newPosX + j][newPosY + i] != EMPTY) return false;
				}
			}
		}
	}

	return true;
}

void TetrisBoard::shiftBoard(int row)
{
	for(int i = row; i > 0; i--)
		for (int j = 1; j < BOARD_WIDTH - 1; j++)
		{
			_boardArray[j][i] = _boardArray[j][i - 1];
		}
}

bool TetrisBoard::canRotate()
{
	return canPlace(_piecePosX, _piecePosY);
}

void TetrisBoard::resetGame()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			if (i == 0) _boardArray[i][j] = BORDER;
			else if (i == BOARD_WIDTH - 1) _boardArray[i][j] = BORDER;
			else if (j == BOARD_HEIGHT - 1) _boardArray[i][j] = BORDER;
			else _boardArray[i][j] = EMPTY;
		}
	}

	_piecePosX = 4;
	_piecePosY = -1;
	_frame = 0;

	piece.randomizePiece();
}

void TetrisBoard::setColor(Color color)
{
	switch (color)
	{
		case RED:
			//_block.setColor(160, 0, 0);
			_block.setColor(255, 0, 0);
			break;
		case GREEN:
			//_block.setColor(180, 0, 0);
			_block.setColor(0, 255, 0);
			break;
		case BLUE:
			//_block.setColor(140, 0, 0);
			_block.setColor(0, 0, 255);
			break;
		case YELLOW:
			//_block.setColor(120, 0, 0);
			_block.setColor(255, 255, 0);
			break;
		case MAGENTA:
			//_block.setColor(100, 0, 0);
			_block.setColor(255, 0, 255);
			break;
		case ORANGE:
			//_block.setColor(80, 0, 0);
			_block.setColor(255, 140, 0);
			break;
		case PINK:
			//_block.setColor(60, 0, 0);
			_block.setColor(255, 20, 147);
			break;
		case BORDER:
			_block.setColor(160, 160, 160);
			break;
		case WHITE:
			_block.setColor(255, 255, 255);
			break;
		default:
			_block.setColor(0xFF, 0xFF, 0xFF);
			break;
	}
}
