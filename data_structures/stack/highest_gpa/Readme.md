
### Programming example. Ch. 7


Task:
    In this example, we write a C++ program that reads a data file consisting of each student’s GPA followed by the student’s name. The program then prints the highest GPA and the names of all the students who received that GPA. The program scans the input file only once. Moreover, we assume that there are a maximum of 100 students in the class.
    
Input:
    The program reads an input file consisting of each student’s GPA, followed by the student’s name. Sample data is as follows:
    
    3.5 Bill
    3.6 John
    2.7 Lisa
    3.9 Kathy
    3.4 Jason
    3.9 David
    3.4 Jack

Output:
    The program outputs the highest GPA and all the names associated with the highest GPA. For example, for the preceding data, the highest GPA is 3.9 and the students with that GPA are Kathy and David.
    
Program design:

We will keep names of the students with the highest GPAs in the stack. After reading the file there are several possible situations:

    1. The current GPA is smaller than the maximum        -> skipped
    2. The current GPA equals the current maximum         -> add name to the stack
    3. The current GPA is higher than the current maximum -> stack is cleared and new name added
