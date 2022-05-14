//
//  linkedListMastered.hpp
//  data_structures
//
//  Created by Daniil Buchko on 14.05.2022.
//

#ifndef linkedListMastered_hpp
#define linkedListMastered_hpp

#include <stdio.h>

template <class Type> struct nodeType
{
    Type data;
    nodeType<Type> *link;
    
};

template <class Type>
class linkedListIterator {
public:
    linkedListIterator();
    // default constructor, current = NULL;
    
    linkedListIterator(nodeType<Type> *ptr);
    // current = ptr;
    
    Type operator*();
    // dereferencing, returns data from current node

    linkedListIterator<Type> operator++();
    // overloading of preincrement operator => iterator
    // points to the next node
    
    bool operator==(const linkedListIterator<Type>& right) const;
    // true if current iterator equals right iterator
    
    bool operator!=(const linkedListIterator<Type>& right) const;
    // true if current iterator doesnt equal right iterator
    
private:
    nodeType<Type>* current;
    // points to current node in the linked list
};



//***********************************************************
// Author: D.S. Malik
// This class specifies the members to implement the basic
// properties of a linked list. This is an abstract class.
// We cannot instantiate an object of this class.
//***********************************************************

template <class Type>
class linkedListType {
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    // overloading the assignment operator
    // For classes that include pointer data members, the assignment
    // operator must be explicitly overloaded. For the same reason,
    // the definition of the class also includes a copy constructor.
    
    void initializeList();
    // initializes list with empty state
    // count = 0, first = nullptr, last = nullptr
    
    bool isEmpty() const;
    // checks if list is empty
    
    void print() const;
    // prints data in each node
    
    int length() const;
    // returns size of the linked list
    
    void destroyList();
    // deletes all nodes from the list
    // count = 0, first = nullptr, last = nullptr
    
    Type front() const;
    // returns the first element in the list if it exists.
    // if list is empty program terminates
    
    Type back() const;
    // returns the first element in the list if it exists.
    // if list is empty program terminates
    
    virtual bool search(const Type& searchItem) const = 0;
    // determines whether searchItem is in the list
    
    virtual void insertFirst(const Type& newItem) = 0;
    // function inserts newItem to the beginning of the list
    
    virtual void insertLast(const Type& newItem)  = 0;
    // function inserts newItem to the end of the list
    
//    virtual void deleteNode(const Type& deleteItem) = 0;
    // funtion deletes node from the list
    
    linkedListIterator<Type> begin();
    // returns iterator, pointing to the beginning of the list (current = first)
    linkedListIterator<Type> end();
    // returns iterator, pointing to the end of the list (current = nullptr)
    
    linkedListType();
    // count = 0, first = nullptr, last = nullptr
    
    linkedListType(const linkedListType<Type>& otherList);
    // copy constructor
    
    ~linkedListType();
    // deletes all nodes from the list
    
protected:
    int count;              // linked list size
    nodeType<Type> *first;  // pointer to the first element of linked list
    nodeType<Type> *last;   // pointer to the last element of linked list
    
private:
    void copyList(const linkedListType<Type>& otherList);
    // makes copy of otherList and assigns to the current instance
    // of linked list
};

// =============================== linkedListIterator ===============================
template<class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = nullptr;
}

template<class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) {
    current = ptr;
}

template<class Type>
Type linkedListIterator<Type>::operator*() {
    return current->data;
}

template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
    current = current->link;
    return *this;
}

template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const {
    return (current == right.current);
}

template<class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const {
    return (current != right.current);
}

// =============================== linkedListType ===============================

template<class Type>
bool linkedListType<Type>::isEmpty() const {
    return (first == nullptr);
}

template<class Type>
linkedListType<Type>::linkedListType() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template<class Type>
void linkedListType<Type>::destroyList() {
    // O(n)
    
    nodeType<Type>* temp;
    
    while (first != nullptr) {
        temp = first;
        first = temp->link;
        delete temp;
    }
    
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList() {
    destroyList();
}

template <class Type>
void linkedListType<Type>::print() const {
    nodeType<Type>* current;
    current = first;
    
    while (current != nullptr) {
        std::cout << current->data << ' ';
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const {
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const {
    assert(first != nullptr);  // list is not empty
    return first->data;
}

template <class Type>
Type linkedListType<Type>::back() const {
    assert(last != nullptr);   // last element exists
    return last->data;
}

// ==================== Iterator ====================
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
    linkedListIterator<Type> temp(nullptr);
    return temp;
}

// ==================== Copying ====================
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList) {
    // deepcopy of otherLinkedList
    
    nodeType<Type>* newNode;  // pointer to create a node
    nodeType<Type>* current;  // pointer to traverse the list
    
    if (first != nullptr)     // if current list is non-empty, reinitializing
        destroyList();
    
    if (otherList.first == nullptr) {  // if other is empty
        first = otherList.first;
        last = otherList.last;
        count = 0;
        return;
    }
    
    current     = otherList.first;
    count       = otherList.count;
    first       = new nodeType<Type>;
    first->data = current->data;
    first->link = nullptr;                  // because it is the only element
    
    last = first;                           // one is the first and the last
    current = current->link;
    
    while (current != nullptr) {
        newNode       = new nodeType<Type>;
        newNode->data = current->data;
        newNode->link = nullptr;            // inserting at the end
        last->link    = newNode;            // now last points to newNode
        current       = current->link;
    }
}

template <class Type>
linkedListType<Type>::~linkedListType() {
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
    first = nullptr;
    copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList) {
    // avoid self-copy
    if (this != &otherList) {
        copyList(otherList);
    }
    return *this;
}



#endif /* linkedListMastered_hpp */
