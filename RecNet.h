#pragma once
#include <iostream>
#include "NxM_Matrix.h"
#include "Sqr_Matrix.h"
#include "Network.h"

using namespace std;

class RecNet : public Network {
public:
	int r_size;
	Sqr_Matrix *r_layer_1;
	Sqr_Matrix *r_layer_2;
	RecNet(int input, int side, string &f, int rs) : Network(input, side, f) {
		read_input_data(f);
		init_weights();
		init_biases();
		r_size = rs;
	}
};
