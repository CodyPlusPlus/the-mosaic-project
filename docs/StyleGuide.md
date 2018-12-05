# Code Style Guide
### By A.Golovin, B.Pascoe, C.Stuck

## Code Format
Even though our code was written by three different people, all with different coding styles, and in multiple development environments, we attempted to standardize the format or style of our code.

To accomplish this, we used a formatting tool called: clang-format. Using this tool we formatted all .h and .cpp files to Google's style guide. This was accomplished using the "-style=Google" flag.

Using this tool, our code is uniformally formatted and the only way to tell who it is written by is by looking at file preamble.

## File Preamble
The beginning of every .h and .cpp file follows a similar style:
* Name of file (not include .h/.cpp) : A description of what is in the file
* Name of file (including .h/.cpp)
* Name of author/s

## .h Files
Our .h files contain only the declaration of our functions. However, this is the most important file to look over if you want to know what each function does.

Above the declaration of each function we have the following structure:
* name of file : Description of what the function does
* precondition : The conditions that must be true in order for function to work
* postcondition : The things to expects after the function has completed execution
* params : A list of parameters (if applicable)
  * param name : What the params is or what it is used for
* return : What the functon returns (if applicable)

## .cpp Files (Excluding Test Files)
Our .cpp files contain the meat of the code. This is where we implement the functions declared in the .h files.

If a user wants to know how the function does what it does, this is where they should look:
* Above every function we have a comment that says which function is being implemented.
* Inside of every function, we have commented what is being done.

## .cpp Test Files
The test_main.cpp is the driver for all of our test execuables.

The rest of the test_*.cpp files test a specific class name.

We left it up to the implementor to decide whether to comment the code or not, since writing testcode was not required. However, in the declaration of each specific test case, we added a meaningful name to discribe the test.
