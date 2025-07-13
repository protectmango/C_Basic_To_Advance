# File Documentation 📂

>Defination : `/usr/include/x86_64-linux-gnu/bits` in `libio.h`

It is a typedef name to the predefined structure

>Open File : `FILE *filepointer = fopen("filename.txt","r+");`

- will allocate dynamic memory for structure _IO_FILE

- will communicate with OS

`Operating System` -> `file manager` -> `allocate temp buffer in RAM`

Success ✅ : Return base address of structure.  
Failure ❎ : Return NULL  

>## FILE Functions
```
fopen( "Filepath", "opening mode" );
```  
Success ✅ : Return File pointer  
Failure ❎ : Return NULL  

```
fclose( file pointer );
```
Success ✅ : return 0  
Failure ❎ : EOF or -1  

```
fgetc( file pointer );
```
Success ✅ : ASCII of character  
Failure ❎ : EOF or -1  

```
fputc( character, file pointer );
```
Success ✅ : ASCII of character  
Failure ❎ : EOF or -1  

```
fgets( string, string size, file pointer);
```
Success ✅ : string  
Failure ❎ : NULL  

```
fputs( string, file pointer);
```
Success ✅ : non -ve number  
Failure ❎ : EOF or -1  

```
fprintf( file pointer, "format specifier according to data", data);
```
Success ✅ : no of characters  
Failure ❎ : -ve value  

```
fscanf( file pointer, "format specifier", &data);
```
Success ✅ : no of input item  
Failure ❎ : EOF  

```
rewind( file pointer );
```
Return ↩️ : Nothing  

>## FILE : Binary Function
```
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```
Success ✅ : no of items read  
Failure ❎ : 0  

```
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
```
Success ✅ : no of items written  
Failure ❎ : 0  

>## FILE Pointer Navigation
```
ftell(file pointer);
```  
>Prototype : long ftell(FILE *stream);  

Success ✅ : return current offset  
Failure ❎ : EOF  

```
fseek(file pointer);
```
>Prototype : int fseek( FILE *steam, long offset, int origin);  

Success ✅ : 0  
Failure ❎ : EOF  

Seek from beginning  

- `SEEK_SET` : 0 : `fseek(fp, 0, SEEK_SET);`

Seek from current  

- `SEEK_CUR` : 1 : `fseek(fp, 10, SEEK_CUR);`

Seek from end  

- `SEEK_END` : 2 : `fseek(fp, 0, SEEK_END);`

## Author Remark
Created By : `Gulshan Kumar Rana`

This is a Simple File Function documentation cheat sheet to get a quick revision of file functions which are used in C programming language

- File Opening
- File Closing
- File Reading
- File Writing
- File Navigating

