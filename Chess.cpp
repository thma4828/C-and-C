// Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include "Tile.h"


int main()
{
	Board *b = new Board(8);
	cout << b->board[1][2]->color << endl;
	int r;
	cin >> r;
    return r;
}

