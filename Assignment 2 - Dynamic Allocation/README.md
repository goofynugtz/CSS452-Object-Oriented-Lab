# Assignment 2

1. Dealing with dynamic allocation of 1D arrays  
Objective: Learn to use new and delete operator  
- Problem Statement:  
Write a program to dynamically allocate a 1-D array of size n to store a heap data structure.  
Write functions to perform insertion, deletion operation and display on heap.

2. Dealing with dynamic allocation of 2D arrays  
- Problem Statement 1:  
Write a program to dynamically allocate a 2-D array of size n x n and perform.
  - Matrix multiplication
  - Determinant of the matrix
Create a header file ```<myMatrix.h>``` which will include several matrix manipulation related functions

- Problem Statement 2:  
Write a program that accept a set ‘n’ of linear equations. Use Cramer’s rule to solve the equations.  
(Use the function from myMatrix.h header file)  
Objectives:  
  - An application of Determinant of martix  
  - Understanding the use of new and delete operator for dynamic memory allocation/deallocation in C++  
  - Manipulating Strings in C++  

3. Indentation of an unindented code  
Objective: Learn to deal with text files and char strings  
- Problem Statement: (use ```string``` header file in C++)  
Read as input an unindented C/C++ program from a C/C++ file, them write a function ```indent()``` to convert the input code into an indented code. The intended code should be saved in another file “indent.c” and display.  
[Read the input unindented code as an array of strings; treat each line (null terminated) of code as a string; maintain a int variable (say ```tab```). During processing parse each string(line) and increment tab when ```{``` is encountered and decrement tab when ```}``` is encountered. To obtain desired indentation append specific number of blank spaces corresponding to the tab to each string(line) (you may use ```strcat()``` function to achieve this.)]
