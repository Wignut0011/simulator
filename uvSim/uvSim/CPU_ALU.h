// CPU_ALU Does the arithmetic for the simulator
// Writen & Debugged by Daniel Jones
//----------------------------------------------------------------------------------------------------------------
#pragma once
class CPU_ALU
{
public:
	//Default Constructor and Deconstructor (Daniel Jones)
	CPU_ALU();
	~CPU_ALU();

	//Arithmetic Functions (Daniel Jones)
	//Adds the first number to the second number.
	int add(int first, int sec);
	//Subtracts the second number from the first number.
	int subtract(int first, int sec);
	//Multiplies the first number by the second number.
	int multiply(int first, int sec);
	//Divides a number by a divisor. Does not check for invalid input.
	int divide(int num, int div);

	//Gate Functions(Not implmented)
	int AND();
	int XOR();
};

