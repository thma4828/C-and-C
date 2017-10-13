#include "stdafx.h"
#include "Board.h"


Board::Board(int s){
	size = s;
	
	for (int z = 0; z < s; z++) {
		vector<Tile*>a(s);
		board.push_back(a);
	}

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			char c;
			if (j % 2 == 0) {
				c = 'w';
			}
			else {
				c = 'b';
			}
			Tile *t = new Tile(c, 8, 8);
			board[i][j] = t;
		}
	}
}


Board::~Board(){
	//empty destructor
}
