#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Move.h"

using namespace std;

class Piece
{
public:
	Piece(int x, int y);
	vector<int>pos;
	Move *move;
	~Piece();
};

