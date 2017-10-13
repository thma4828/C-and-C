#include "stdafx.h"
#include "Queen.h"


Queen::Queen(int x, int y, int bs) : Piece(x, y){
	diag_up_left = new Diagonal_Move(bs, 'w');
	diag_up_right = new Diagonal_Move(bs, 'w');
	diag_dwn_left = new Diagonal_Move(bs, 'd');
	diag_dwn_right = new Diagonal_Move(bs, 'd');
}


Queen::~Queen(){
	//empty
}
