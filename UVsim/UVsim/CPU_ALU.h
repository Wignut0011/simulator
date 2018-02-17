/*
	Written by Daniel Jones
*/
#pragma once
class CPU_ALU
{
public:
	CPU_ALU();
	~CPU_ALU();

	//Arithmetic Functions (Daniel Jones)
	int add(int first, int sec);
	int subtract(int first, int sec);
	int multiply(int first, int sec);
	int divide(int num, int div);

	//Gate Functions
	int AND();
	int XOR();
};

