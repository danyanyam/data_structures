//
//  main.cpp
//  data_structures
//
//  Created by Daniil Buchko on 14.05.2022.
//

#include <iostream>

#include "linked_list/book/unorderedLinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    
    
    unorderedLinkedList<int> x;
    x.insertLast(1);
    x.insertLast(2);
    x.insertLast(3);
    x.insertLast(4);
    x.insertLast(5);
    x.insertLast(6);
    x.insertLast(7);
    
    for (auto it = x.begin(); it != x.end(); ++it) {
        std::cout << *it << std::endl;
    }
        
    return 0;
}
