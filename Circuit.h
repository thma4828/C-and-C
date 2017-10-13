#pragma once

struct Wire {
	float Voltage;
	struct Connections {
		Battery *B_in;
		Battery *B_out;
		Resistor *R_in;
		Resistor *R_out;
	}C;
};

struct Battery {
	float Voltage;
	Wire *w_in;
	Wire *w_out;
};

struct Resistor {
	float R;
	Wire *w_in;
	Wire *w_out;
};


class Circuit{
public:
	Battery *B;
	char op_buffer[10];
	Circuit(float vb);
	void Build();
	~Circuit();
};

