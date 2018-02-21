#pragma once
#include "CPU_ALU.h"
class UVSim_Interpreter
{
public:
	UVSim_Interpreter();
	//void Input(int a);
	bool Input(int);
	bool RunInstruction(int instruction);
	bool CheckInstrunction(int instruction);
	bool ErrorHandler(int);
	void RunProgram();

private: // variables
	int inputCount;
	int input;
	int opcode;
	bool flag;
	int operand;
	int errorCode;
	CPU_ALU alu;


	// Public Variables
public: // variables
	int Accumulator;
	int PC;
	int memory[100];

};

