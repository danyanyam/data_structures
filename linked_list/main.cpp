//
//  main.cpp
//  data_structures
//
//  Created by Daniil Buchko on 14.05.2022.
//

#include <iostream>
#include "circularDoubleLinkedList/circularDoubleLinkedList.hpp"

int main(int argc, const char * argv[]) {
    
    doubleLinkedList<int> list;
    
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    
    list.remove(3);
    
    list.insertFirst(0);
    
    std::cout << list;
    std::cout << list.search(2);
    std::cout << list.search(3);
    
    return 0;
}
