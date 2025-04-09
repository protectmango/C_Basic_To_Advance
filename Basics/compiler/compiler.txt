What is a Compiler?

Compiler is a program which translates code written in 
	Human Language to Manchine Language.

Human Language Code : c,c++.
Machine Language Code : opcode (operational code).


It have 4 Stages of Compilation :
	Preprocessor : It include the header file and remove comments replace macros and perform conditional compilation.
		input : .c file
		output : .i file //also know as pure c file.
		cmd : cc -E filename.c -o outputfilename.i	
	
	Translator : It check for syntax errors and convert c program into Assembly Code.
		input : .i file
		output : .s file
		cmd : cc -S filename.i -o outputfilename.s

	Assembler : It converts the assembly code into operational code (opcode).
		input : .s file
		output : .o file
		cmd : cc -C filename.s -o outputfilename.o

	Linker : It links with libraries, add os infomation and generate exe file.
		input : .o file
		output : a.out (default)
		cmd : cc filename.o -o output or cc filename.o


		

