
// Main() written by Abinadi Swapp
//----------------------------------------------------------------------------------------------------------------
#include<iostream>
#include <iomanip>
#include <string>
#include "Interpretor.h"
using namespace std;
int main() {

	// Interpretor
	Interpretor inter;
	

	// Output instructions
	cout << "***** WELCOME TO UVSIM *****" << endl;
	cout << "Instructions: " << endl;
	cout << "1. Input a program instruction " << endl;
	cout << "2. Press enter " << endl;
	cout << "3. Do instructions 1 and 2 over until program is completely inputed" << endl;
	cout << "4. Input -99999 when you want your program to run" << endl;
	cout << endl;


	// variable that will take the input
	string input = "";

	// variable that will count the current line
	int lineCount = 0;

	while (input != "99999") {
	
		// line count print
		cout << setfill('0') << setw(2) << lineCount << " " << "? ";

		// getting the instruction
		cin >> input;

		input = input.substr(1); // remove the + or - for now

		// put in the 
		try {

			inter.InputInstruction(stoi(input));
			lineCount++;
		}
		catch (const std::exception & ex) {
			// do nothing 
		}
	}


	// run the program 
	inter.RunProgram();


	getchar();
	return 0;
}