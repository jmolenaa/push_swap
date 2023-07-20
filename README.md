# Push_swap

The Push_swap project aims to sort data on a stack using a limited set of instructions and achieving the lowest possible number of actions.  
The goal is to learn about sorting algorithms.

## Functionality

The program takes a list of numbers and sorts them from lowest to highest.  
To do this it uses 2 stacks and a set of predetermined operations that change the positions of the numbers on the stacks. The [operations](#operations).  
The program handles input as one string of integers, integers as separate arguments or a mix of the two.  
The checker program takes a list of integers and then reads from standard input operations to be executed on the stacks. Once an EOF is encountered the program checks if the list has been sorted and prints an OK if yes and KO if not.

## Usage

Clone the project and run 'make' in the repository. For the checker program run 'make bonus'.
Once compiled run the program with a list of integers as arguments.  
For the checker run the program with a list of integers as arguments and then input operations to sort them.

## Implementation

The numbers in the list get indexed from smallest to biggest. This way we're always working with numbers starting from 1 and increasing by 1, instead of having values ranging from minimum integer to maximum integer.  
  
For lists smaller than 10 I use a simple algorithm that looks for the smallest number in stack a, pushes it to stack b and then repeats until only 3 numbers are left in stack a. Then it runs a sort three function and pushes back everything from stack b to stack a.  

For lists smaller than 5000 and bigger than 10 the program uses a custom algorithm that consists of several different algorithms.  
First it pushes the numbers from stack a to stack b, sorting them into buckets, each bucket containing numbers with values within a certain range. The numbers get pushed from smallest to biggest and if the number is under half of a current bucket it also gets rotated to the bottom of stack b.  
f.e. with a list of 100, we sort the numbers into buckets of values 1-50, 51-75, 76-88, 89-100. If for the first bucket the number is smaller than 25, after getting pushed to b it will get rotated to the bottom.  
A small optimization with this step is to leave the longest increasing sequence of numbers in stack a. This is done using patience sort.  
  
After pushing all the numbers to b the program uses a pathfinding algorithm to find the fastest way to push a number from the first bucket of b to a. It will first try the number on top of stack b, find the number of operations and then move throught the bucket up and down trying to find a number with a smaller number of operations. Once it decides on a number it rotates the stacks into position and pushes the number to stack a.  

For lists bigger than 5000 the pathfinding algorithm was getting rather slow, so the program uses the radix sorting algorithm.  
This algorithm checks the first bit of the numbers and if it's 0 it will push the number to stack b. It will rotate the whole stack and once it's done it will push everything back to stack a. It will repeat this process for however many bits there are in the highest number in the stack.  
At the end the list will be sorted.

### Operations

- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.  
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.  
- ss: sa and sb at the same time.  
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.  
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.  
- rr: ra and rb at the same time.  
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.  
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.  
- rrr: rra and rrb at the same time.
