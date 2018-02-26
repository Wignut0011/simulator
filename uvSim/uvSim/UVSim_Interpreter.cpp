#include "UVSim_Interpreter.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>  
using namespace std;

UVSim_Interpreter::UVSim_Interpreter() {

	// Just setting the values of data attributes
	flag = true;
	opcode = 0;
	operand = 0;
	PC = 0;
	inputCount = 0;
}

bool UVSim_Interpreter::Input(int input) {

	//opcode = input / 100; // Obtain Opcode

						  // Error 1 test (wrong digit length)
	//if (opcode < 100 && opcode > 9) {


		//operand = input - (opcode * 100); // Obtain Operand

		//if (Identify() == false) {
		//	throw runtime_error(" ");
		////}

		// Put here by abinadi swapp
	//if (CheckInstrunction(input)) {
	//	throw runtime_error("");
	//	}
		// check input
		

		// Grab the inputed instruction and increment the current inputedCount
		memory[inputCount] = input;
		inputCount++;

	//}

	//else {
	//	ErrorHandler(1);
	//	throw runtime_error(" ");
	//}
	return true;
}

bool UVSim_Interpreter::RunInstruction() {
	

	switch (opcode) {
		// READ
	case 10: // Branch out to CPU
			cout << "Please input a number: ";
			cin >> memory[operand]; // Abinadi changed this
		
		break;

		// WRITE
	case 11:// Branch out to CPU
			//cout << "Write to location " << operand << endl;
			cout << "Contents at " << operand << ": " << memory[operand] << endl;
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
			Accumulator = alu.add(Accumulator, memory[operand]);
		break;

		// SUBTRACT
	case 31:// Branch out to CPU
			Accumulator = alu.subtract(Accumulator, memory[operand]);
		break;

		// DIVIDE
	case 32:// Branch out to CPU
			Accumulator = alu.divide(Accumulator, memory[operand]);
		break;

		// MULITPLY
	case 33:// Branch out to CPU
			Accumulator = alu.multiply(Accumulator, memory[operand]);
		break;

		// BRANCH
	case 40:// Branch out to CPU
			//cout << "this is BRANCH" << endl;
			PC = operand-1;
		break;

		// BRANCH NEG
	case 41:// Branch out to CPU
		cout << "this is BRANCH NEG" << endl;
		if (Accumulator < 0)
			PC = operand-1;
		break;

		// BRANCH ZERO
	case 42:// Branch out to CPU
		cout << "this is BRANCH ZERO" << endl;
		if (Accumulator == 0)
			PC = operand-1;
		break;

	// HALT
	case 43: if (operand != 00) ErrorHandler(3);
			 else return false;
			 break;

	case 0: 
		// do nothing because we are justing fillilng memory
		// placed here by abinadi
		break;

	// ERROR 2 (Incorrect opcode)
	default: ErrorHandler(2);
		break;
	}
	return true;
}

bool UVSim_Interpreter::CheckInstrunction(int instruction)
{
	opcode = instruction / 100; // Obtain Opcode
	operand = instruction - (opcode * 100);

	switch (opcode) {
	case 10:
		return false;
		break;

	case 11:
		return false;

		break;

	case 20:
		return false;
		break;

	case 21:
		return false;
		break;

	case 30:
		return false;
		break;

	case 31:
		return false;
		break;

	case 32:
		return false;
		break;

	case 33:
		return false;
		break;

	case 40:
		return false;
		break;

	case 41:
		return false;
		break;

	case 42:
		return false;
		break;

	case 43: 
		return false;
		break;

	case 0:
		if (operand != 0) {
			return true; // this means they aren't just clearing a space in memory
		}
		return false;
		break;

		
	default: 
		ErrorHandler(2); // ERROR 2 (Incorrect opcode)
		return true;	// throw an exception
		break;
	}

	return false;
}

void UVSim_Interpreter::DebuggingDump()
{
	cout << "Registers: " << endl;

	// Display the contents of all Registers and format in a cool way:
	stringstream _accumulator;
	_accumulator << std::setfill('0') << std::setw(5) << Accumulator;
	cout << "Accumulator: " <<  "\t \t" << std::right << setfill(' ') << setw(6) <<  _accumulator.str() << endl;

	stringstream _pc;
	_pc << std::setfill('0') << std::setw(2) << PC;
	cout << "Instruction Counter: " << '\t' <<  std::right << setfill(' ') << setw(6) << _pc.str() << endl;

	cout << "Instruction Register: " << '\t' << std::right << setfill(' ') << setw(6) << InstructionRegister << endl;

	cout << "Operation Code: " << '\t' << std::right << setfill(' ') << setw(6) << opcode << endl;

	stringstream _operand;
	_operand << std::setfill('0') << std::setw(2) << operand;
	cout << "Operand: " << "\t \t" << std::right << setfill(' ') << setw(6) << _operand.str() << endl;

	cout << endl;

	cout << "Memory: " << endl;


	// memory dump
	// top column names
	cout << "     ";

	for (int j = 0; j < 10; j++) {
		cout << std::right << std::setfill('0') << std::setw(2) << j << "   ";
	}

	// Display the contents of memory
	for (int i = 0; i < 100; i++) {
		if (i == 0 || i % 10 == 0) {
			cout << endl;
			 cout << std::setfill('0') << std::setw(2) << (i)/10 << " ";
		}
			cout << std::setfill('0') << std::setw(4) << memory[i] << " ";

		
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

void UVSim_Interpreter::RunProgram()
{

	cout << "****** Program Executing *********" << endl;
	// Loop through memory
	while (true) {
		// Get the instructions and opcodes
		InstructionRegister = memory[PC];
		opcode = InstructionRegister / 100; // Obtain Opcode
		operand = InstructionRegister - (opcode * 100);
		// Check if we run into a halt
		if (memory[PC] == 4300) {
			break;
		}
		// Run the instruction and increment the PC
		RunInstruction();
		PC++;
	}

	cout << "****** Program Terminated ********" << endl;

	// display all debugging stuff
	DebuggingDump();
}


