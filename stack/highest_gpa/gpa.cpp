//
//  gpa.cpp
//  stack
//
//  Created by Daniil Buchko on 15.05.2022.
//

#include <iostream>
#include "../stackType.hpp"

#include <string>
#include <fstream>

int Main(int argc, const char * argv[]) {

    double GPA;
    double highestGpa;
    stackType<std::string> students(100);
    std::string name;

    std::ifstream infile;
    infile.open("input.txt");
    
    if (!infile)
        std::cerr << "File not found" << std::endl;
    
    infile >> GPA >> name;
    
    highestGpa = GPA;
    students.push(name);
    
    while (infile) {
        infile >> GPA >> name;
        
        if (GPA < highestGpa)
            continue;
        
        if (students.isFullStack()) {
            std::cerr << "Stack is overfilled" << '\n';
            continue;
        }
        
        if (GPA == highestGpa)
            students.push(name);
        else {
            students.initializeStack();
            students.push(name);
            highestGpa = GPA;
        }
    }
    
    std::cout << "Highest GPA is " << highestGpa << '\n';
    while (!students.isEmptyStack()) {
        std::cout << students.top() << '\n';
        students.pop();
    }
    return 0;

}
