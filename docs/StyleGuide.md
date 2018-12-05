# Code Style Guide
## File Preamble
The beginning of every file starts with the name of the fill and what information is contained in the file.
The second line is the name of the file, followed by a new line for the name of the authors.

## .h Files
Our .h files contain only the declaration of our functions. However, this is the most important file to look over if you want to know what each function does.
Above the declaration of each function we have the following structure:
*name of file : Description of what the function does
*precondition : The conditions that must be true in order for function to work
*postcondition : The things to expects after the function has completed execution
*params : A list of parameters (if applicable)
*    param name : What the params is or what it is used for
*return : What the functon returns (if applicable)

## .cpp Files (Excluding Test Files)
Our .cpp files contain the meat of the code. This is where we implement the functions declared in the .h files.
If a user wants to know how the function does what it does, this is where they should look.
Above every function we have a comment that says which function is being implemented.
Inside of every function, we have commented what is being done.

## .cpp Test Files
The test_main.cpp is the driver for all of our test execuables. The rest of the test_*.cpp files test a specific class name.
We left it up to the implementor to decide whether to comment the code or not. However, in the declaration of each specific test case, we added a meaningful name to discribe the test.
