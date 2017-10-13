// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class P_Circuit {
public:
	float Volts;
	float Req;
	float R_total;
	float Current;
	bool isReq_calc;
	int n;
	int r_in_s;
	vector<float>resistors;
	vector<float>s_resistors;
	P_Circuit() {
		int p;
		float v;
		float z1, z2;
		int s;
		cout << "Enter the number of resistors in paralell" << endl;
		cin >> p;
		n = p;
		for (int i = 0; i < p; i++) {
			cout << "Enter resistance for r = " << i << endl;
			scanf("%f", &z1);
			resistors.push_back(z1);
		}
		cout << "Enter the number of additional resistors in series." << endl;
		scanf("%i", &s);
		r_in_s = s;
		for (int k = 0; k < s; k++) {
			cout << "Enter resistance for r = " << k << endl;
			scanf("%f", &z2);
			s_resistors.push_back(z2);
		}
		cout << "Enter the voltage differnece for the power source" << endl;
		scanf("%f", &v);
		Volts = v;
		isReq_calc = false;
	}
	float calculate_Req() {
		isReq_calc = true;
		float sr = 0.0;
		float d = 1.0;
		for (int i = 0; i < n; i++) {
			float f = resistors[i];
			sr = sr + (d / f);
		}
		Req = 1.0 / sr;
		return (1.0 / sr);
	}
	float calculate_current() {
		if (!isReq_calc) {
			calculate_Req();
		}
		float c = Volts / Req;
		Current = c;
		return c;
	}
	float calculate_r_total() {
		if (!isReq_calc) {
			calculate_Req();
		}
		if (!r_in_s) {
			return 0.0;
		}
		float s_res = 0;
		for (int z = 0; z < r_in_s; z++) {
			s_res += s_resistors[z];
		}
		return s_res + Req;
	}

};


int main()
{
	P_Circuit *r1 = new P_Circuit();
	float z = r1->calculate_Req();
	float u = r1->calculate_current();
	cout << "Resistance req: " << z << " Ohms" << endl;
	cout << "Current I: " << u << " Amps" << endl;
	int r;
	cin >> r;
	return r;
}

