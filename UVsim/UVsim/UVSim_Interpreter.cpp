#include "UVSim_Interpreter.h"
#include <iostream>
#include <stdexcept>
using namespace std;

UVSim_Interpreter::UVSim_Interpreter(){
	flag = true;
	opcode = 0;
	operand = 0;
	PC = 0;
}

//void UVSim_Interpreter::Input(int a) {
//
//	do{
//		do {
//				if () { ErrorHandler(4); throw; }
//			memory[PC] = input;
//			flag = InterperterInit(memory, PC);
//		} while (flag == false);
//		PC++;
//	} while(PC < 100);
//
//}

bool UVSim_Interpreter::Input(int input) {

	opcode = input / 100; // Obtain Opcode

							   // Error 1 test (wrong digit length)
	if (opcode < 100 && opcode > 9) {
		operand = input - (opcode * 100); // Obtain Operand

		if (Identify() == false) {
			throw runtime_error(" ");
		}
	}

	else { ErrorHandler(1); 
	throw runtime_error(" ");
	}
	return true;
}

bool UVSim_Interpreter::Identify() {


	switch (opcode) {
		// READ
	case 10: // Branch out to CPU
		if (operand != 0) ErrorHandler(3);
		else {
			cout << "Please input a number: ";
			cin >> Accumulator;
		}
		break;

		// WRITE
	case 11:// Branch out to CPU
		//cout << "Write to location " << operand << endl;
		cout << memory[operand];
		break;

		// LOAD
	case 20:// Branch out to CPU
		//cout << "Load from location " << operand << endl;
		Accumulator = memory[operand];
		break;

		// STORE
	case 21:// Branch out to CPU
		//cout << "Store to loaction " << operand << endl;
		memory[operand] = Accumulator;
		break;

		// ADD
	case 30:// Branch out to CPU
		cout << "Adding from location "<< operand << endl;
		break;

		// SUBTRACT
	case 31:// Branch out to CPU
		cout << "Subtract from location "<< operand << endl;
		break;

		// DIVIDE
	case 32:// Branch out to CPU
		cout << "Divide from locaiton "<< operand << endl;
		break;

		// MULITPLY
	case 33:// Branch out to CPU
		cout << "Multiply from location "<< operand << endl;
		break;

		// BRANCH
	case 40:// Branch out to CPU
		//cout << "this is BRANCH" << endl;
		PC = operand;
		break;

		// BRANCH NEG
	case 41:// Branch out to CPU
		cout << "this is BRANCH NEG" << endl;
		if (Accumulator < 0) 
			PC = operand;
		break;

		// BRANCH ZERO
	case 42:// Branch out to CPU
		cout << "this is BRANCH ZERO" << endl;
		if (Accumulator == 0)
			PC = operand;
		break;

		// HALT
	case 43: if (operand != 00) ErrorHandler(3);
			 else return false;
		break;

		// ERROR 2 (Incorrect opcode)
	default: ErrorHandler(2);
		break;
	}
}

bool UVSim_Interpreter::ErrorHandler(int errorCode) {

	/*
	  *Error code legend*
	------------------------
	1: Decimal length
	2: Wrong opcode
	3: Incompatible Operand
	4: Invalid character
	*/

	switch (errorCode) {

	case 1: cout << "ERROR: Incorrect decimal length" << endl;
		break;

	case 2: cout << "ERROR: Incorrect opcode" << endl;
		break;

	case 3: cout << "ERROR: Incompatible Operand" << endl;
		break;

	case 4: cout << "ERROR: Invalid input, please input intergers only" << endl;
		break;
	}
	return false; // return error flag to halt program
}