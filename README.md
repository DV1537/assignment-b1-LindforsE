### B1: Polymorphism
Instructions:
- Implement a Figure class enabling grouping of shapes. The Figure class should have the following methods:
- addShape(Shape s) adds a shape to the group
- getBoundingBox() calculates the minimum axis-aligned bounding rectangle to fit all the shapes. The method returns the top left and bottom right corners of the box.

- Your program should read from a file containing multiple shapes (one per line) and return the top-left and bottom-right corners of the bounding box. The file can contain any number of shapes.

## General instructions

1. Use GIT version control to manage your code and submit assignments unless specified otherwise (see separate instructions on how to set up and use GIT Classroom)
2. Your program should use text files as the only input. No keyboard input is permitted. Path to the input file should be the first parameter to the program.
3. Format output exactly as specified/exemplified in the assignment descriptions
4. Follow good code writing practices:
	
	1. Do not use global variables
	2. Divide classes into .cpp and .h files
	3. All parameters that are constants should be declared as such
	4. All variable and class names should be in English, self-explanatory, and must use camelCase. 
	5. All code that is not used should be removed
	6. Use code comments when the reasoning behind the solution is not obvious
	7. Always check that that all allocated memory is released and avoid memory leaks

5. You should not use any external libraries other than `cmath`, `iostream`, `fstream`, and `strings`. If you wish to use another library please check with the lab assistants first. 
6. The program should be robust against wrong input data. If there is an error with input file the program should gracefully terminate with an non zero exit code.
7. Real numbers should be printed with the precision of 3 decimal digits.


## Assignment A

The aim of assignment A is to test your understanding on pointers and working with classes. The focus
is on memory management, class inheritance, encapsulation, and overloading.