//
//  Header.h
//  tree
//
//  Created by Daniil Buchko on 15.05.2022.
//

#ifndef Header_h
#define Header_h

#include <string>

//TODO: sudoku, 8queen!!!!!!

int fact(int value) {
    return (value == 0)? 1: value * fact(value - 1);
}


int maximum(const int list[], int lowerIndex, int upperIndex) {
    if (lowerIndex == upperIndex) {
        return list[lowerIndex];
    }
    int max = maximum(list, lowerIndex + 1, upperIndex);
    return (list[lowerIndex] >= max)? list[lowerIndex]: max;
}

int fibonacci(int n) {
   if (n == 1 || n == 2)
       return 1;
   
    return fibonacci(n - 1) + fibonacci(n - 2);
}


void asBinary(int x) {
    if (x > 0)
    {
        asBinary(x / 2);
        std::cout << x % 2;
    }
}


#endif /* Header_h */
