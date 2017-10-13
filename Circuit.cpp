#include "stdafx.h"
#include "Circuit.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

Circuit::Circuit(float v_battery){
	B = new Battery();
	B->Voltage = v_battery;
	Wire *win = new Wire();
	win->Voltage = 0.0;
	Wire *wout = new Wire();
	wout->Voltage = B->Voltage;
	B->w_in = win;
	B->w_out = wout;
}

void Circuit::Build() {
	bool isB = true;
	int l_c = 0;
	char last_op = 'B';
	int us;
	int op_i = 0;
	do{
		switch (last_op) {
		case 'B':
			printf("press 1 to add resistor or press 2 to close the circuit");
			scanf("%i", &us);
			if (us == 1) {
				Resistor *rn = new Resistor;
				float r;
				printf("Enter R for resistor");
				scanf("%f", &r);
				rn->R = r;
				Wire *wrout = new Wire();
				rn->w_out = wrout;
				B->w_in->C.R_out = rn;
				last_op = 'R';
				op_buffer[op_i] = last_op;
				++op_i;
			}
			else if (us == 2) {
				B->w_out->C.B_out = B;
				printf("Circuit Closed");
				isB = false;
				op_buffer[op_i] = last_op;
				++op_i;
			}
			else {
				last_op = 'B';
			}
		case 'R':
			printf("press 1 to add resistor or press 2 to close the circuit");
			scanf("%i", &us);
			if (us == 1) {
				Resistor *rn = new Resistor;
				float r;
				printf("Enter R for resistor");
				scanf("%f", &r);
				rn->R = r;
				B->w_in->C.R_out = rn;
				last_op = 'R';
				op_buffer[op_i] = last_op;
				++op_i;
			}
			else if (us == 2) {
				B->w_out->C.B_out = B;
				printf("Circuit Closed");
				isB = false;
				op_buffer[op_i] = last_op;
				++op_i;
			}
			else {
				last_op = 'B';
		}
		
		l_c++;
	} while (isB);
}


Circuit::~Circuit(){
	
}
