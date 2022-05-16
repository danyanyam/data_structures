//
//  doubleLinkedList.hpp
//  linked_list
//
//  Created by Daniil Buchko on 16.05.2022.
//

#ifndef doubleLinkedList_hpp
#define doubleLinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <cassert>


template <class Type>
struct Node {
    Type data;
    Node* prev;
    Node* next;
    
    // https://adaickalavan.github.io/cpp/template-operator-overload/#gsc.tab=0
    template<class T>  // hackaround operator<< overloading
    friend std::ostream& operator<<(std::ostream& stream, const Node<T>& node);
};



template <class Type>
class doubleLinkedList {
public:
    const doubleLinkedList<Type>& operator=(const doubleLinkedList<Type>&);
    // because pointers should point to new memory adresses
    // after copying data
    
    doubleLinkedList<Type>(const doubleLinkedList<Type>&);
    // copy constructor
    
    doubleLinkedList<Type>();
    // default constructor. Sets pointers to nullptr and count =0
    
    ~doubleLinkedList<Type>();
    // deletes nodes
    
    void insertLast(const Type value);
    // appends element to the end of the list
    
    void insertFirst(const Type value);
    // inserts element at the beginning of the list
    
    void remove(const Type value);
    // removes first occurence of the value in the list
    
    bool search(const Type value) const;
    // search for the first occurence of the value in the list
    
    int length() const;
    // number of the nodes in the linked list
    
    void destroyList();
    // removes all elements in the list
    
    bool isEmpty() const;
    // checks if there are elements in the list
    
    // https://adaickalavan.github.io/cpp/template-operator-overload/#gsc.tab=0
    template<class T>  // hackaround operator<< overloading
    friend std::ostream& operator<<(std::ostream& stream, const doubleLinkedList<T>& linkedList);
    
private:
    int count;               // amount of elements in the list
    Node<Type>* head;        // pointer to the beginning of the list
    Node<Type>* tail;        // pointer to the end of the list
    void copyList(const doubleLinkedList&); // copy operator
};



// =================================  definitions  =================================
// =================================  constructors =================================
template <class Type>
doubleLinkedList<Type>::doubleLinkedList() {
    count = 0;
    head = nullptr;
    tail = nullptr;
}


template <class Type>
doubleLinkedList<Type>::doubleLinkedList(const doubleLinkedList<Type>& otherList) {
    copyList(otherList);
}


// =================================  public       =================================
template <class Type>
bool doubleLinkedList<Type>::isEmpty() const {
    return count == 0;
}


template <class Type>
void doubleLinkedList<Type>::destroyList() {
    
    if (count == 0)
        return;
    
    Node<Type>* current = head;  // starting with second element of list
    
    while (count != 0) {
        Node<Type>* temp = current;    // copying ptr to current node to delete it
        current = current->next;
        
        delete temp;
        temp = nullptr;
        --count;
    }
    
    assert(count == 0);
    head = nullptr;
    tail = nullptr;
}


template <class Type>
doubleLinkedList<Type>::~doubleLinkedList() {
    destroyList();
}


template <class Type>
void doubleLinkedList<Type>::insertLast(const Type value) {
    // O(1)
    Node<Type>* newNode = new Node<Type>;  // new tail
    
    if (isEmpty()){
        head = newNode;
        tail = newNode;
    }
    
    newNode->data = value;
    newNode->next = head;                 // next of new tail is head
    newNode->prev = tail;                 // prev of new tail is old tail
    
    tail->next = newNode;
    head->prev = newNode;
    
    tail = newNode;
    ++count;
}


template <class Type>
void doubleLinkedList<Type>::insertFirst(const Type value) {
    // O(1)
    Node<Type>* newNode = new Node<Type>;  // new head
    
    if (isEmpty()){
        head = newNode;
        tail = newNode;
    }
    
    newNode->data = value;
    newNode->next = head;                 // next of new head is old head
    newNode->prev = tail;                 // prev of new head is tail
    
    tail->next = newNode;
    head->prev = newNode;
    
    head = newNode;
    ++count;
}


template <class Type>
void doubleLinkedList<Type>::remove(const Type value) {
    // O(n)
    
    if (isEmpty()) {
        std::cerr << "Cant delete from empty list\n";
        return;
    }
    
    Node<Type>* current = head;               // to iterate over all elements
    bool found = false;                       // will control loop and result
    
    
    for (int i = 0; i != count; ++i) {
        if (current->data == value) {
            found = true;
            break;
        }
        current = current->next;
    }
    
    if (!found) {
        std::cerr << "Value is not found\n";
        return;
    }
    
    current->prev->next = current->next;  // linking prev of current with next of current
    current->next->prev = current->prev;  // linking next of current with prev of current
    
    if (current == head)
        head = current->next;
    
    if (current == tail)
        tail = current->prev;
    
    
    delete current;
    --count;
    
}


template <class Type>
bool doubleLinkedList<Type>::search(const Type value) const {
    Node<Type>* current = head;
    bool found = false;
    
    for (int i = 0; i != count && !found; ++i) {  // logical or
        if (current->data == value)
            return true;
        
        current = current->next;
    }
    return found;
}
    

template <class Type>
int doubleLinkedList<Type>::length() const {
    return count;
}

    
template <class Type>
const doubleLinkedList<Type>& doubleLinkedList<Type>::operator=(const doubleLinkedList<Type>& otherList) {
    
    // avoiding self copy
    if (this == &otherList)
        return *this;
    
    // deleting all from this list
    if (count)
        destroyList();
    
    copyList(otherList);
}


// =================================  private      =================================
template <class Type>
void doubleLinkedList<Type>::copyList(const doubleLinkedList<Type>& otherList) {
    
    if (head || tail)             // if this list is not empty
        destroyList();            // resetting pointers and count
    
    if (otherList.count == 0)
        return;
    
    // AT LEAST ONE ELEMENTED OTHER LIST
    count = otherList.count;
    head = new Node<Type>;
    head->data = otherList.head->data;
    head->prev = head;            // next of one elemented list is head
    head->next = head;            // prev of one elemented list is head
    
    tail = head;
    
    Node<Type>* currentNode = otherList.head->next;      // for creating nodes in the loop
    Node<Type>* prevNode = head;                         // for linking nodes
    
    for (int i = 0; i != count; ++i) {
        // creating new node in heap and link it to prev node
        tail = new Node<Type>;
        tail->data = currentNode->data;
        tail->prev = prevNode;
        tail->next = head;
        
        // linking prev node with new node
        prevNode->next = tail;
        prevNode = tail;                   // now new node is prev
        currentNode = currentNode->next;   // using next node from other list
    }
}

template <class Type>
std::ostream& operator<<(std::ostream& stream, const Node<Type>& node) {
    return stream << node.data;
}


template <class Type>
std::ostream& operator<<(std::ostream& stream, const doubleLinkedList<Type>& linkedList) {
    Node<Type>* current = linkedList.head;
    
    for (int i = 0; i != linkedList.count; ++i) {
        std::cout << *current << ' ';
        current = current->next;
    }
    return stream;
}

#endif /* doubleLinkedList_hpp */
