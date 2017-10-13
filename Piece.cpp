#include "stdafx.h"
#include "Piece.h"


Piece::Piece(int x, int y){
	pos.push_back(x);
	pos.push_back(y);
}


Piece::~Piece(){
	//empty destructor
}
