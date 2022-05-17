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



#endif /* doubleLinkedList_hpp */
