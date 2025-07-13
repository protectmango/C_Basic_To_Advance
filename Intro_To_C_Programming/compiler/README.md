# Compliation Stages
>## What is a Compiler?
>Compiler is a program which translates code written in `Human Language` → `Machine Language`.

- Human Language Code : `c`,`c++`.
- Machine Language Code : `opcode` (operational code).

## 4 Stages of Compilation :
>### **Preprocessor**
> It include the `header file` and `remove comments replace macros` and `perform conditional compilation`.  

**input** : `.c` file  
**output** : `.i` file **pure c file**.  
>[!Tip]
>Check the preprocessor stage using 
```sh 
cc -E filename.c -o outputfilename.i	
```

>### **Translator**
>It check for **syntax errors** and convert `c program` → `Assembly Code`.

**input** : `.i` file  
**output** : `.s` file  
>[!Tip]
>Check translator stage using
```sh
cc -S filename.i -o outputfilename.s
```

>### **Assembler**
>It converts the `assembly code` → `operational code` also known as **opcode**.

**input** : `.s` file
**output** : `.o` file
>[!Tip]
>Check Assembler stage using
```sh
cc -C filename.s -o outputfilename.o
```

>### **Linker**
>It links with `libraries`, add `Operating System` infomation and generate `.exe` file.

**input** : `.o` file  
**output** : `a.out` (default)  
>[!Tip]
>Check Linker stage using
```sh
cc filename.o -o output or cc filename.o
```
## Summary Table
| Stage            | Command Syntax                     	| Key Point 		    |
|------------------|--------------------------------------------|---------------------------|
| Preprocessor     | `cc -E filename.c -o outputfilename.i`     | remove comment, replace macro, perform conditional compilation 	    |
| Translator	   | `cc -S filename.i -o outputfilename.s`     | check syntax error     |
| Assembler        | `cc -C filename.s -o outputfilename.o`     | convert assembly  → opcode      |
| Linker 	   | `cc filename.o -o output or cc filename.o` | link libraries and functions  |

## Authod Message
Maintained By : `Gulshan Kumar Rana`  
C compilation stages are important info to debug and understand the errors.
		


