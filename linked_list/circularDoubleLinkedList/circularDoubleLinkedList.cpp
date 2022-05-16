//
//  doubleLinkedList.cpp
//  linked_list
//
//  Created by Daniil Buchko on 16.05.2022.
//

#include "circularDoubleLinkedList.hpp"
#include <iostream>

int Main(int argc, const char * argv[]) {
    
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
