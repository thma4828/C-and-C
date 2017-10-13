#include "stdafx.h"
#include "Move.h"
#include <iostream>

using namespace std;

void Move::print_pos() {
	if (is_pos_set) {
		cout << "(";
		for (int i = 0; i<int(pos.size()); i++) {
			cout << pos[i] << " , ";
		}
		cout << " )";
	}
	else {
		cout << "error, pos is not set. " << endl;
	}
}

Move::Move(int cw, int ch){
	change_w = cw;
	change_h = ch;
	is_pos_set = false;
}

void Move::update_pos(int xc, int yc) {
	pos[0] += xc;
	pos[1] += yc;
}

void Move::set_pos(int x, int y) {
	pos.push_back(x);
	pos.push_back(y);
}

void Move::update_dir(char dir) {
	direction = dir;
}

void Move::set_len(int l) {
	len = l;
}	

Move::~Move() {
	//empty destructor
}