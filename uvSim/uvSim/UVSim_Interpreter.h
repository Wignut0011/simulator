// UVSim_Interpreter Manages memory and running the program
// Writen Mostly by Daniel Espinel, Debugged and compiled by Abinadi Swapp
//----------------------------------------------------------------------------------------------------------------
#pragma once
#include "CPU_ALU.h"
class UVSim_Interpreter
{
public:
	// Initilizes variables
	UVSim_Interpreter();

	// Function for inputing one instruction
	bool Input(int);

	// Function for running one instruction
	bool RunInstruction();

	// Function for later use, that will make sure the user inputs a correct opcode and operand
	bool CheckInstrunction(int instruction);

	// Function that outputs the values in all the registers and shows the contents of memory
	void DebuggingDump();

	// Function that outputs returns error messages. Used with the CheckInstruction function
	bool ErrorHandler(int);

	// Function that loops through memory and runs the program, also increments the PC, and loads the instruction register
	void RunProgram();

	// variables public because we might want to access them outside this class at some point
	int Accumulator = 0;     // Used with arithmetic
	int InstructionRegister; // Holds the current instruction
	int PC;			         // Counts where we are in memory		
	int memory[100] = { 0 }; // Loads memory full of 0's


private: // variables
	int inputCount;         // Used with the Input function, keeps track of where we have inputed in memory
	int opcode;				// Used to store the opcode of the current instruction
	int operand;			// Used to store the operand of the current instruction
	bool flag;				// Will later be used to throw errors when the user inputs an incorrect instruction
	int errorCode;			// Will later be used to throw errors when the user inputs an incorrect instruction
	CPU_ALU alu;			// Gets us the CPU_ALU class. Currently doesn't do more then basic arithmetic


};

