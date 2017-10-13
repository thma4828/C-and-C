#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Move
{
public:
	int change_w;
	int change_h;
	char direction;
	int len;
	bool is_pos_set;
	vector<int>pos; // pos[0] = x, pos[1] = y
	Move(int cw, int ch);
	void set_pos(int x, int y);
	void print_pos();
	void update_dir(char dir);
	void update_pos(int xc, int yc);
	void set_len(int l);
	~Move();
};

class Diagonal_Move : public Move {
public:
	Diagonal_Move(int len, char d) : Move(len, len) {
		change_w = len;
		change_h = len;
		direction = d;
	}

};

