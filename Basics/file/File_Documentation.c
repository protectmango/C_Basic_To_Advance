/*
-------------------------------------------------------------------------------------------------------------
		FILE : typedef struct_IO_FILE FILE

defination : /usr/include/x86_64-linux-gnu/bits	in "libio.h"
		+ It is a typedef name to the predefined structure

		Open File : FILE *filepointer = fopen("filename.txt","r+");
		+ will allocate dynamic memory for structure _IO_FILE
		+ will communicate with OS ( OS->file manager ->allocate temp buffer in RAM
Success : Return base address of structure.
Failure : Return NULL
-------------------------------------------------------------------------------------------------------------
		FILE Functions
	
	1. fopen( "Filepath", "opening mode" );
Success : FILE*
Failure : NULL
	
	2. fclose( file pointer );
Success : return 0
Failure : EOF or -1
	
	3. fgetc( file pointer );
Success : ASCII of character
Failure : EOF or -1

	4. fputc( character, file pointer );
Success : ASCII of character
Failure : EOF or -1

	5. fgets( string, string size, file pointer);
Success : string
Failure : NULL

	6. fputs( string, file pointer);
Success : non -ve number
Failure : EOF or -1

	7. fprintf( file pointer, "format specifier according to data", data);
Success : no of characters
Failure : -ve value
	
	8. fscanf( file pointer, "format specifier", &data);
Success : no of input item
Failure : EOF

	9. rewind( file pointer );
Return 	: Nothing
-------------------------------------------------------------------------------------------------------------
		FILE : BINARY Function

	1. size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
Success : no of items read
Failure : 0

	2. size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
Success : no of items written
Failure : 0

-------------------------------------------------------------------------------------------------------------
		FILE Pointer Navigation
	
	1. ftell(file pointer);
	   Prototype : long ftell(FILE *stream);	
Success : return current offset
Failure : EOF
	
	2. fseek(file pointer);
	   Prototype : int fseek( FILE *steam, long offset, int origin);
Success : 0
Failure : EOF

	+ SEEK_SET : 0	: fseek(fp, 0, SEEK_SET);	: Seek from beginning 
	+ SEEK_CUR : 1  : fseek(fp, 10, SEEK_CUR);	: Seek from current
	+ SEEK_END : 2  : fseek(fp, 0, SEEK_END);	: Seek from end

-------------------------------------------------------------------------------------------------------------
*/
