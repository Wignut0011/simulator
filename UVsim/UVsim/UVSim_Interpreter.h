#pragma once
class UVSim_Interpreter
{
public:
	UVSim_Interpreter();
	//void Input(int a);
	bool Input(int);
	bool Identify();
	bool ErrorHandler(int);

	
private: // variables
	int input;
	int opcode;
	bool flag;
	int operand;
	int errorCode;

	// Public Variables
public: // variables
	int Accumulator;
	int PC;
	int memory[100];

};

