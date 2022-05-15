//
//  stackType.hpp
//  stack
//
//  Created by Daniil Buchko on 15.05.2022.
//

#ifndef stackType_hpp
#define stackType_hpp

#include <stdio.h>
#include "stackADT.h"
#include <cassert>

template <class Type>
class stackType: public stackADT<Type>
{
/*
                                  array  [idx]
                                   ___
                                  |   |  [100]
 stack                             ...
  _____________________           |   |    [4]
 |               |     |          | D |    [3]
 | maxStackSize  | 100 |          | C |    [2]
 | stackTop      |  4  |          | B |    [1]
 | list          |  * --------->  | A |    [0]
 |_______________|_____|           ---
 
 */
    
public:
    const stackType<Type>& operator=(const stackType<Type>&);
    // overload assignment operator because of pointer in member
    
    void initializeStack();
    // stackTop = 0
    
    bool isEmptyStack() const;
    // checks if stack is empty
    
    bool isFullStack() const;
    // checks if stack is full
    
    void push(const Type& newItem);
    // push elemnt on top
    // stack must exist and not be full
    
    Type top() const;
    // retrieve element from the top of the stack
    // stack must exist before we retrieve top element
    
    void pop();
    // remove element from the top
    // stack must exist before we remove top element
    
    stackType(int stackSize = 100);
    // overload c-tor because of pointer in member
    
    stackType(const stackType<Type>& otherStack);
    // copy c-tor
    
    ~stackType();
    // overload des-tor because of pointer in member
    
private:
    int maxStackSize;
    int stackTop;      // index of element on top
    Type* list;        // pointer to the data, held within stack
    
    void copyStack(const stackADT<Type>& otherStack);
    
};

template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack) {
    if (this != &otherStack)
        copyStack(otherStack);
    
    return *this;
}

template <class Type>
void stackType<Type>::initializeStack() {
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const {
    return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const {
    return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type &newItem)  {
    
    assert(!isFullStack());
    list[stackTop++] = newItem;  // put data on the top & increment index of top el
}

template <class Type>
Type stackType<Type>::top() const {
    
    assert(!isEmptyStack());
    return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop() {
    
    assert(!isEmptyStack());
    stackTop--;
}

template <class Type>
void stackType<Type>::copyStack(const stackADT<Type>& otherStack) {
    
    delete [] list;
    
    // copying parameters of other stack
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];
    
    // copying data from other stack
    for (int i = 0; i != stackTop; i++) {
        list[i] = otherStack.list[i];
    }
}

template <class Type>
stackType<Type>::stackType(int stackSize) {
    
    assert(stackSize > 0);
    maxStackSize = stackSize;
    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType() {
    delete[] list;
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack) {
    list = nullptr;
    copyStack(otherStack);
}




#endif /* stackType_hpp */
