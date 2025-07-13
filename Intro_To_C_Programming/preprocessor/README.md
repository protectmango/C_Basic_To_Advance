# Preprocessor `#`

>[!Note]
>The `#` token (hash/pound symbol) plays a crucial role in the C preprocessor.   
>It is used to denote preprocessor directives 
- `#include` `#define`and as `#` stringizing operator). 

## Let's break it down:

### 1. `#` in Preprocessor Directives 
All preprocessor directives start with `#` at the beginning of a line.  
Examples:
```c
#include <stdio.h>   // File inclusion
#define PI 3.14      // Macro definition
#ifdef DEBUG         // Conditional compilation
#error "Something went wrong!"  // Force an error
#endif
```
- The `#` must be the first non-whitespace character on the line.
- It tells the preprocessor: "<ins>This line is a command, not C code.</ins>"



### 2. `#` in Macros (Stringizing Operator)
Inside macro definitions, `#` can **convert a macro argument into a string literal**.  
Example:
```c
#define STRINGIZE(x) #x

int main() {
    printf("%s\n", STRINGIZE(Hello));  // Output: "Hello"
}
```

>[!Note]
>1. The preprocessor sees `STRINGIZE(Hello)`.
>2. `#x` converts `x` (`Hello`) into `"Hello"`.
>3. The compiler gets:  
```c 
   printf("%s\n", "Hello");
```

### 3. `##` Token Concatenation Operator
While not strictly `#` alone, `##` is related—it **concatenates** two tokens in a macro.  
Example:
```c
#define CONCAT(a, b) a##b

int main() {
    int xy = 42;
    printf("%d\n", CONCAT(x, y));  // Expands to `xy`, prints 42
}
```

>[!Note]
>1. `CONCAT(x, y)` → `x##y` → `xy`.
>2. The compiler sees `printf("%d\n", xy)`.



### 4. `#` in `#pragma` (Compiler-Specific Directives)
`#pragma` is used for compiler-specific instructions (e.g., disabling warnings).  
Example:
```c
#pragma GCC diagnostic ignored "-Wunused-variable"
```


### 5. `#` in `#error` and `#warning`
- `#error` forces compilation to fail with a message:  
```c
#if !defined(VERSION)
#error "VERSION must be defined!"
#endif
```
  
- `#warning` shows a compiler warning but continues:
```c
#warning "This is deprecated, use new_function() instead"
```

### 6. Special Case: `#` in `#if`, `#elif`
Used in preprocessor conditions:
```c
#if defined(__linux__)
    #define OS "Linux"
#elif defined(__APPLE__)
    #define OS "macOS"
#endif
```

>[!Important]
>How to Experiment with `#`?
1. See Preprocessor Output:
```sh
gcc -E test.c -o test.i
```
   (Examine `test.i` to see how `#define` and `#include` are processed.)

2. Test Stringizing:
```c   
#define DEBUG_PRINT(x) printf(#x " = %d\n", x)
int num = 42;
DEBUG_PRINT(num);  // Output: "num = 42"
```   


## Summary Table
| Usage            | Example                     | Effect 		    |
|------------------|-----------------------------|--------------------------|
| Directives       | `#include <stdio.h>`        | Includes a file 	    |
| Stringizing      | `#define STR(x) #x`         | Converts `x` to `"x"`    |
| Concatenation    | `a##b` → `ab`               | Combines two tokens      |
| Compiler Control | `#pragma once`              | Ensures single inclusion |
| Error/Warning    | `#error "Fail!"`            | Stops compilation        |

## Author Message

Maintained By : `Gulshan Kumar Rana`  
Preprocessor are sometimes tricky to understand, this is a gist which covers all the preprocessors.


