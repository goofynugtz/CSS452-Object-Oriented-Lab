# Assignment 1 

1. Generating random numbers  
Objective: Learn how generate pseudo-random numbers are generated using linear congruential generator 
[More details here](https://en.wikipedia.org/wiki/Linear_congruential_generator)
- Problem Statement:  
Write a code to generate that will implement your random number generator function ```myrand()``` using the multiplicative congruential generator formula: Xi+1=(Xi * a) % m;
Set X0 the initial value of the series to be the system time using ```time()``` function.
Now generate 10000 random numbers in the range [1,50] using ```myrand()``` and also using library function ```rand()```. Display the Chi-square test value of both the random series and comment if they are acceptable. You may set the suitable values for a, c & m (refer wiki page).

2. A trigonometric function plotter  
Objective: Learn to use manipulators
- Problem Statement:  
Write a C++ code to display the plot of 
  - cosine function
  -	sine function
  -	exponential
Your program should take as input the initial and final value of theta (in degrees), step count and also the char to be used to fill up the pattern.


3. Displaying number patterns  
Objective: Learn to use manipulators
- Problem Statement:  
Write a C++ code to accept a value of ‘n’ and display a number pattern as following:
Example for input n=5:
```
1 2 3 4 5 4 3 2 1  
  2 3 4 5 4 3 2   
    3 4 5 4 3    
      4 5 4     
        5       
      4 5 4     
    3 4 5 4 3    
  2 3 4 5 4 3 2   
1 2 3 4 5 4 3 2 1  
```