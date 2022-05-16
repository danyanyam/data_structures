//
//  unorderedLinkedList.hpp
//  data_structures
//
//  Created by Daniil Buchko on 14.05.2022.
//

#ifndef unorderedLinkedList_hpp
#define unorderedLinkedList_hpp

#include <stdio.h>
#include "linkedListMastered.hpp"

// declaration
// ================= unorderedLinkedList =================
template <class Type>
class unorderedLinkedList: public linkedListType<Type> {
public:
    bool search(const Type& searchItem) const;
    // determines whether searchItem is in the list
    
    void insertFirst(const Type& newItem);
    // function inserts newItem to the beginning of the list
    
    void insertLast(const Type& newItem);
    // function inserts newItem to the end of the list
    
//    void deleteNode(const Type& deleteItem);
    // funtion deletes node from the list
    
};


// definition
// ================= unorderedLinkedList =================
template <class Type>
bool unorderedLinkedList<Type>::search(const Type &searchItem) const {
    
    nodeType<Type>* current;  // pointer to traverse the list
    current = this->first;
    
    while (current != nullptr) {
        
        if (current->data == searchItem)
            return true;
        current = current->link;
    }
    return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type &newItem) {
    nodeType<Type>* newNode;
    
    newNode = new nodeType<Type>;
    newNode->data = newItem;
    newNode->link = this->first;
    
    this->count++;
    this->first = newNode;
    
    
    if (this->last == nullptr)   // if list was empty before inserting
        this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type &newItem) {
    nodeType<Type>* newNode;
    
    newNode = new nodeType<Type>;
    newNode->data = newItem;
    newNode->link = nullptr;
    
    this->count++;
    
    if (this->first == nullptr)      // if list was empty before inserting
        this->first = newNode;       // now added element is the first
    else {
        this->last->link = newNode;  // previos node points to newNode
    }
    this->last = newNode;            // newNode now is the last element of list
    
}

//template <class Type>
//void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
    
//}

#endif /* unorderedLinkedList_hpp */
