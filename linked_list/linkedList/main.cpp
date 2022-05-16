//
//  Start.cpp
//  data_structures
//
//  Created by Daniil Buchko on 14.05.2022.
//

#include "linkedList.hpp"

int main() {
    {
        linkedList list;
        
        list.append(1);             // [1]
        list.append(3);             // [1, 3]
        list.insertAtBeginning(0);  // [0, 1, 3]
        
        Node* node = list.get(1);
        
        list.insertAfter(node, 2);  // [0, 1, 2, 3]
        list.print();
    }  // list is destructed
    
    return 0;
    
}
