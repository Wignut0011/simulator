#include "CPU_ALU.h"



CPU_ALU::CPU_ALU()
{
}


CPU_ALU::~CPU_ALU()
{
}

int CPU_ALU::add(int first, int sec)
{
	return first + sec;
}

int CPU_ALU::subtract(int first, int sec)
{
	return first - sec;
}

int CPU_ALU::multiply(int first, int sec)
{
	return first * sec;
}

int CPU_ALU::divide(int num, int div)
{
	return num / div;
}
