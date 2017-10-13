#pragma once
#include "Piece.h"
class Queen : public Piece{
public:
	Queen(int x, int y, int bs);
	Diagonal_Move *diag_up_left;
	Diagonal_Move *diag_up_right;
	Diagonal_Move *diag_dwn_left;
	Diagonal_Move *diag_dwn_right;
	~Queen();
};

