#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Tile.h"
using namespace std;
class Board
{
public:
	int size;
	vector<vector<Tile*>>board; // board[0][3]
	Board(int s);
	~Board();
};

