```
        ___  ___  ___      ___ ________  ___  _____ ______      
       |\  \|\  \|\  \    /  /|\   ____\|\  \|\   _ \  _   \    
       \ \  \\\  \ \  \  /  / | \  \___|\ \  \ \  \\\__\ \  \   
        \ \  \\\  \ \  \/  / / \ \_____  \ \  \ \  \\|__| \  \  
         \ \  \\\  \ \    / /   \|____|\  \ \  \ \  \    \ \  \ 
          \ \_______\ \__/ /      ____\_\  \ \__\ \__\    \ \__\
           \|_______|\|__|/      |\_________\|__|\|__|     \|__|
                                 \|_________|
```
## UVSIM MACHINE LANGUAGE SIMULATOR (Work In Progress)


### Team:
  * Abinadi Swapp   -GUI, Compiler
								
  * Daniel Jones    -CPU
				
  * Daniel Espinel  -Interpreter, Readme

### Index
```
	*INTRO
	*DIRECTIONS
		-MEMORY
		-ACCUMULATOR
		-PC
		-OPCODE
		-OPERAND
		-CONTROL BRANCH

	*INSTRUCTIONS
		-IO
			-READ
			-WRIT
		-READ\WRITE
			-LOAD
			-STORE
		-ARITHMITIC
			-ADD
			-SUBTRACT
			-DIVIDE
			-MULTIPLY
		-CONTROL
			-BRANCH
			-BRANCH NEG
			-BRANCH ZERO
			-HALT
```


##                              INTRO


*This program is intended as a learning tool for Machine language*

In real life, hardware works in 1s and 0s, binary. When you program in high 
level languages like c++ and python, that program gets converted to this
binary machine language when it compiles. Every CPU has it's different machine
language but in the end, every program gets converted so your machine can run
that program in binary. UVSIM is a simulator that emulates machine language 
programing.

This simulator uses lines of code comprising of 4 digits each line; 2 digit 
opcode and a 2 digit operand. It utilizes one register called the Accumulator.
The total memory space is 100 lines in total.

*Please refer to the instruction list in order to input the correct code*


## DIRECTIONS


In order to understand Machine Language, there's a few components to 
understand.

* Memory
* Accumulator (Register)
* PC
* Opcode
* Operand
* Control Branch


### Memory

```
Memory is the total space that your program can by stored on. This 
simulator can hold 100 lines of code. Each line has a location named by
a 2 decimal number such as 01, 53, 99 etc. You can't go beyond the limits
of this hard number since this simulator is intended to emulate machine 
language and in real life this limit would be the amount of actual memory
it contains.
```

### Accumulator

```
This represents a single register. The accumulator is meant to simulate the
cache inside your CPU. A temporary location to store data outside memory for
fast and easy access. In terms of this simulator, you will use the 
accumulator to manipulate data depending on which instruction you use.
```

### PC

```
The PC or Program Counter is a counter that displays where in memory the
program currently is. For example, if the PC is 53 then the program is 
currently located at 53 in memory. The PC can be manipulated to simulate
conditional branching paths in the code through Branch Control instructions.
If one of these instructions are executed then the program will deviate to 
that location. EG: PC is 45 and 45 contains a Branch instruction to 67 then 
the PC will deviate to location 67 and the program will continue from there.
```

### Opcode

```
The 2 digit signature that tells the CPU what instruction is to be executed
such as Load(20), Add(30), Branch(40), etc. This 2 digit signature is the
first half of your code with the second half being the operand.
```

### Operand

```
The second half of a line of code. The operand of your code tell the CPU what
to do with the instruction that is to be executed. For example, if an ADD 
instruction is executed, the operand of the code tell the CPU what is to be 
added with the accumulator EG: 3014 where 30 is the ADD instruction and 
14 (the operand) is where the data to be added to the accumulator is located.

*Some instructions don't require an opcode so please refer to the opcode 
section of this readme for more information
```

### Control Branch

```
This lets conditional deviations in the program possible. By manipulating the 
PC, you can branch off to a different part of the program depending on which 
Control Branch opcode you use. There's 3 in total in UVSIM. Branch, Branch
Negative, and Branch Zero. While the first branch can executed by simply
running the line, the other are conditional depending on the accumulator.
if the accumulator contains a 0 and the PC runs into a BranchZero then
and only then can it be executed; vice versa with BranchNegative if the 
accumulator contains a negative.
```
## INSTRUCTIONS

### I/O

* 10 READ
```
Read instruction that takes input from the user. 
*Please leave operand at 00
```

* 11 WRITE
```
Write instruction that displays data in the accumulator to the console 
window.
*Please leave operand at 00
```

### READ/WRITE

* 20 LOAD
```
Load instruction that loads data from the location listed in the operand
to the accumulator.
```

* 21 STORE
```
Store instruction that stores data from the accumulator to the location 
listed in the operand.
```

### ARITHMITIC

* 30 ADD
```
Add instruction that adds data in the accumulator with data located in 
the operand. Result is stored in the accumulator.
```

* 31 SUBTRACT
```
Subtract instruction that subtracts data in the accumulator with data 
located in the operand. Result is stored in the accumulator.		
```

* 32 DIVIDE
```
Divide instruction that divides data in the accumulator with data located 
in the operand. Result is stored in the accumulator.		
```	

* 33 MULTIPLY
```
Multiply instruction that multiplies data in the accumulator with data 
located in the operand. Result is stored in the accumulator.		
```

### CONTROL

* 40 BRANCH
```
Branch instruction that directs the PC to the location listed in the 
operand
```

* 41 BRANCH NEG
```
Branch instruction that directs the PC to the location listed in the 
operand if the last arithmetic operation resulted in a negative.
```

* 42 BRANCH ZERO
```
Branch instruction that directs the PC to the location listed in the 
operand if the last arithmetic operation resulted in a zero.
```

* 43 HALT
```
Halts the PC and stops the program. (End of program)
*Please leave operand at 00
```
