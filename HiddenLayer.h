#pragma once
#include <iostream>
#include <math.h>
#include "NxM_Matrix.h"
#include "Sqr_Matrix.h"
#include "Network.h"


using namespace std;

class HiddenLayer {
public:
	HiddenLayer(column *i) {
		init_weights();
		if (i != NULL) {
			input = i;
		}
		else {
			cout << "input is null" << endl;
			input = NULL;
		}
	}
	Sqr_Matrix * weights;
	column * input;
private:
	void init_weights() {
		for (int a = 0; a<int(weights->side); a++) {
			for (int b = 0; b<int(weights->side); b++) {
				int va = 1+ (rand() % 3);
				int vb = 1+ (rand() % 3);
				//cout << "	{[4a]} adding weights: " << va << " " << vb << "{[4a]}" << endl;
				weights->rows[a][b] = va;
				weights->rows[a][b] = vb;
				//cout << weights->rows[a][b] << ',';
			}
		}
	}
};
