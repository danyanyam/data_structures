//
//  linkedList.hpp
//  data_structures
//
//  Created by Daniil Buchko on 14.05.2022.
//

#ifndef linkedList_hpp1
#define linkedList_hpp1
#include <stdio.h>

struct Node {
public:
    Node(int newData=0);
    int data;
    Node* next;
    // pointer to next node in linked list

};


class linkedList {
public:
    void append(int value);
    // creates new node with value and inserts it
    // in the ending of linked list O(n)
    
    void insertAtBeginning(int value);
    // creates new node with value and inserts it
    // at beginning of the linked list O(1)
    
    void insertAfter(Node*& before, int newValue);
    // creates new node after provided node
    // with newValue O(1)
    
    void remove(size_t index);
    
    Node* get(size_t index);
    // returns pointer to node at index O(n)
    
    void print();
    // prints the linked list
    
    linkedList();
    // size = 0, head = nullptr
    
    ~linkedList();
    // removes all nodes from list
    
private:
    Node* lastNode();
    // returns pointer to the last Node
    // in list O(n)
    
    Node* head;
    int size;
};



#endif /* linkedList_hpp */
