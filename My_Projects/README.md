Systems Programming & Low-Level Development:

Operating System Kernel Development:

SimpleOS (32-bit bare-bones OS): This project aims to be a learning resource for OS development. It's a great starting point to understand the fundamentals without getting overwhelmed by a full-fledged OS.

GitHub: https://github.com/xing1357/SimpleOS

Dreamos64 (x86-64 OS experiments): This project focuses on experiments in 64-bit OS development, offering more advanced concepts.

GitHub: https://github.com/dreamos82/Dreamos64

ByteOS (Lightweight UEFI based OS): This project goes into UEFI-based OS development, which is a more modern approach.

GitHub: https://github.com/Mysteriusz/ByteOS

Learning KVM - implement your own kernel: (Part of a larger project-based tutorial list) This isn't a single repo, but a very advanced topic. You can find this within the "Project-Based-Tutorials-in-C" repository mentioned below, specifically under the "Operating Systems" section.

Relevant section in a curated list: https://github.com/nCally/Project-Based-Tutorials-in-C#operating-systems

Network Protocol Stack Implementation:

"Let's code a TCP/IP stack" (Tutorial series): Again, not a single repo, but a highly regarded series of tutorials that guides you through building a TCP/IP stack in C. You can find links to the parts in the "Project-Based-Tutorials-in-C" repository.

Relevant section in a curated list: https://github.com/nCally/Project-Based-Tutorials-in-C#computer-networking

PacketFilteringKernelModule: A project that involves writing a kernel module for packet filtering, which ties into network stack concepts.

GitHub: https://github.com/BitterOcean/PacketFilteringKernelModule

Embedded Systems/IoT Firmware Development:

quadcopter-drone-flight-control: A flight controller for an autonomous quadcopter drone. This involves PID control, IMU integration, and low-level hardware interaction.

GitHub: https://github.com/giusenso/quadcopter-drone-flight-control

p256 (ECDSA P-256 signature verification for embedded use): Focuses on highly optimized cryptographic implementations for resource-constrained environments.

GitHub: https://github.com/oreparaz/p256

High-Performance Computing (HPC) with C:

HPC (High Performance Computing exercises): This repository contains C/C++ code for various HPC exercises, including cache hit/miss ratio, loop transformations, SIMD vectorization, and CUDA matrix multiplication.

GitHub: https://github.com/ramesh-adhikari/HPC

mfem (Lightweight, general, scalable C++ library for finite element methods): While primarily C++, it's a significant HPC project that demonstrates parallel computing and scientific computing principles often implemented in C.

GitHub: https://github.com/mfem/mfem

II. Compilers, Interpreters, and Language Tools:

c-compiler (A C compiler made using Lex and Yacc): This project aims to accept any valid C program and produce a symbol table, parse tree, annotated syntax tree, and intermediate code.

GitHub: https://github.com/AnjaneyaTripathi/c-compiler

C-Compiler-Design (Compiler design project): Another project implementing a C compiler, covering lexical analysis, parsing, semantic analysis, and code generation.

GitHub: https://github.com/aliebayani/C-Compiler-Design

"Let's Build a Compiler: A C & x86 version" / "Write a C Interpreter": These are tutorial-based projects (found within nCally/Project-Based-Tutorials-in-C) that guide you through building a compiler or interpreter, offering a fantastic deep dive into language engineering.

Relevant section in a curated list: https://github.com/nCally/Project-Based-Tutorials-in-C#programming-languages

Static/Dynamic Code Analyzer for C:

Uno (Simple static source code analysis tool for C code): This tool focuses on common C defects like uninitialized variables, null pointer dereferencing, and out-of-bounds array indexing. It's a great starting point for building your own analysis tools.

GitHub: https://github.com/nimble-code/Uno

Infer Static Analyzer (Facebook's mobile app analyzer): While more complex and involving C++, it's a powerful open-source static analyzer from Facebook that you could study and potentially contribute to.

GitHub: https://github.com/facebook/infer

III. Core Infrastructure & Libraries:

Lightweight Database Management System (DBMS):

Database-Management-System-with-C-Language: A project that implements a database management system with C, capable of processing SQL commands.

GitHub: https://github.com/KoalaChelsea/Database-Management-System-with-C-Language

ARBAB (A simple Database in C - Data Structure and Algorithm): Focuses on indexing and hashmap implementations for a simple database.

GitHub: https://github.com/mahanzavari/ARBAB

Database-Implementation (CS525--Advanced Database Organization): A cooperative repository for a database course, likely containing more advanced concepts.

GitHub: https://github.com/llgeek/Database-Implementation

Custom Memory Allocator:

Memory-Allocator (Minimalistic memory allocator for C/C++): A project to implement malloc(), calloc(), realloc(), and free() with a focus on memory alignment, block reuse, and coalescing.

GitHub: https://github.com/Zeyt8/Memory-Allocator

C_Allocator (Fixed Block Memory Allocator in C): This project focuses on a fixed block memory allocator design, useful for specific performance characteristics and fragmentation prevention.

GitHub: https://github.com/endurodave/C_Allocator

Generic Data Structure Library with Advanced Features:

algorithms (Collection of different kinds of algorithms in C): While it says "newbies encouraged," a 10-year experienced developer can find inspiration here to implement highly optimized and concurrent versions of these algorithms and data structures. Look for opportunities to introduce lock-free designs or SIMD optimizations.

GitHub: https://github.com/Privanom/algorithms

You might need to find more specific projects for concurrent or lock-free data structures in C. Search for terms like "concurrent hash table C", "lock-free queue C" on GitHub.

IV. Niche and Specialized Areas:

Real-time Audio/Video Processing:

Learn FFmpeg libav the Hard Way: This is a tutorial-based project (again, from nCally/Project-Based-Tutorials-in-C) that dives into the FFmpeg libraries, which are highly optimized C libraries for multimedia processing. Implementing something on top of or modifying parts of FFmpeg would be a significant challenge.

Relevant section in a curated list: https://github.com/nCally/Project-Based-Tutorials-in-C#uncategorized

Security-focused Projects:

nuke (A program to 'nuke' storage devices): A low-level project for secure file deletion, which touches on data security principles.

GitHub: https://github.com/jithin-renji/Nuke

For cryptography, you might look into open-source implementations of cryptographic primitives in C (e.g., specific AES or RSA implementations) and try to optimize them or integrate them into a secure communication library. Search for "AES C implementation" or "RSA C library" on GitHub.

General Resource for Project Ideas and Tutorials:

Project-Based-Tutorials-in-C: This is an excellent curated list of projects with links to tutorials and sometimes code. It's not a single project, but a goldmine for advanced C project ideas.

GitHub: https://github.com/nCally/Project-Based-Tutorials-in-C