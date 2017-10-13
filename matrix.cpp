// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "NxM_Matrix.h"
#include "Sqr_Matrix.h"
#include "Network.h"
using namespace std;

int main()
{
	/// ----- new main ----- ///
	string file = "in.txt";
	Network *nnet = new Network(3, 3, file);
	nnet->read_input_data(file);
	nnet->init_biases();
	nnet->init_weights();
	for (int z = 0; z < 7; z++) {
		column *il = new column();
		il->col = nnet->inp[z];
		il->height = il->col.size();
		cout << "========== FORWARD PASS BELOW =========" << endl;
		column *o1 = nnet->forward_pass(z);
		column *t1 = nnet->target_col(il);
		cout << "=======================================" << endl;
		cout << "*** input ****" << endl;
		nnet->h_layer_1->print_col(il);
		cout << "**** target ****" << endl;
		nnet->h_layer_1->print_col(t1);
		cout << "**** actual ****" << endl;
		nnet->h_layer_1->print_col(o1);
		cout << "**** loss ****" << endl;
		cout << nnet->euclid_distance(o1, t1) << endl;
	}
	
	int r;
	cin >> r;
    return r;
}

