#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Sqr_Matrix.h"
#include "NxM_Matrix.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <cstdlib>

using namespace std;

class Network {
public:
	//members
	//list of input vectors
	vector<vector<int>>inp;
	column *input;
	Sqr_Matrix *h_layer_1;
	column *b1;
	Sqr_Matrix *h_layer_2;
	column *b2;
	column *output;
	int inputSize;
	int sideSize;
	//functions
	Network(int input_size, int side, string &fname) {
		cout << " {[0]} Network is building... {[0]}" << endl;
		inputSize = input_size;
		sideSize = side;

		input = new column();
		h_layer_1 = new Sqr_Matrix(side);
		b1 = new column();
		h_layer_2 = new Sqr_Matrix(side);
		b2 = new column();
		output = new column();

		cout << " {[1]} Variables initialized... {[1]}" << endl;

	}
	Network() {
		//useless empty constructor is useless....
	}
	void read_input_data(string &filename) {
		cout << " {[2]} Reading input data... {[2]}" << endl;
		ifstream data;
		string line, token;
		vector<int>d;
		data.open("ddata.txt");
		if (!data.is_open()) {
			cout << "error file did not open" << endl;
		}
		while (getline(data, line)) {
			//cout << "line: " << line << endl;
			istringstream ss(line);
			while (getline(ss, token, ',')) {
				d.push_back(stoi(token));
			}
			//cout << "{[2a]} pushing back data into input... {[2a]}" << endl;
			inp.push_back(d);
			d.clear();
		}
	}
	void init_weights() {
		cout << " {[4]} initializing weights {[4]}" << endl;
		for (int a = 0; a<int(h_layer_1->side); a++) {
			for (int b = 0; b<int(h_layer_1->side); b++) {
				int va = 1 + (rand() % 3);
				int vb = 1 + (rand() % 3);
				//cout << "	{[4a]} adding weights: " << va << " " << vb << "{[4a]}" << endl;
				h_layer_1->rows[a][b] = va;
				h_layer_2->rows[a][b] = vb;
				cout << h_layer_1->rows[a][b] << ',';
			}
			cout << endl;
		}
	}
	void init_biases() {
		cout << " {[3]} initializing biases {[3]}" << endl;
		for (int i = 0; i < h_layer_1->side; i++) {
			int vb1 = rand() % 3;
			int vb2 = rand() % 3;
			b1->col.push_back(vb1);
			b2->col.push_back(vb2);
		}
	}
	column * forward_pass(int n) {
		cout << " {[10]} Forward pass at n = " << n << " {[10]}" << endl;
		column *c_in = new column();
		if (inp.size() < 1) {
			cout << "--- error cannot access input data ---" << endl;
			return NULL;
		}
		c_in->col = inp[n];
		c_in->height = c_in->col.size();
		cout << " --1. input column: " << n << endl;
		h_layer_1->print_col(c_in);
		column *lay_1 = h_layer_1->col_x_mat(c_in, h_layer_1);
		cout << " --1a. weights for layer1: " << endl;
		h_layer_1->print_mat(h_layer_1);
		cout << " --2. input * weights at layer 1: " << endl;
		h_layer_1->print_col(lay_1);
		cout << " --2a. our bias matrix for l1: " << endl;
		h_layer_1->print_col(b1);
		cout << " --3. adding our bias matrix to get: " << endl;
		column *lay_1b = h_layer_1->col_plus_col(lay_1, b1);
		h_layer_1->print_col(lay_1b);
		cout << " --4. activate to get our final output for the 1st layer!!!" << endl;
		column *lay_1c = h_layer_1->act_col(lay_1b);
		h_layer_1->print_col(lay_1c);
		return lay_1c;
	}

	void backward_pass(int initial_loss) {
		//
	}

	column * target_col(column *B) {
		column *C = new column();
		for (int i = 0; i < B->col.size(); i++) {
			if (B->col[i] == 1) {
				C->col.push_back(0);
			}
			else {
				C->col.push_back(1);
			}
		}
		if (B->col.size() != 0) {
			return C;
		}
		else {
			return NULL;
		}
	}
	float euclid_distance(column *A, column *B) {
		if (A->col.size() == B->col.size()) {
			vector<float>ds;
			float sum = 0.0;
			for (int i = 0; i < int(A->col.size()); i++) {
				float var = float(A->col[i]) - float(B->col[i]);
				float v_sq = var * var;
				sum += v_sq;
			}
			float distance = sqrt(sum);
			return distance;
		}
		cout << "error, returning -1" << endl;
		return -1.0;
	}
};
