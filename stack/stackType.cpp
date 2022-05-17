//
//  stack
//
//  Created by Daniil Buchko on 15.05.2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

#include "stackType.hpp"

template <class Type>
const stackType<Type> &stackType<Type>::operator=(const stackType<Type> &otherStack)
{
    if (this != &otherStack)
        copyStack(otherStack);

    return *this;
}

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type &newItem)
{

    assert(!isFullStack());
    list[stackTop++] = newItem; // put data on the top & increment index of top el
}

template <class Type>
Type stackType<Type>::top() const
{

    assert(!isEmptyStack());
    return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop()
{

    assert(!isEmptyStack());
    stackTop--;
}

template <class Type>
void stackType<Type>::copyStack(const stackADT<Type> &otherStack)
{

    delete[] list;

    // copying parameters of other stack
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];

    // copying data from other stack
    for (int i = 0; i != stackTop; i++)
    {
        list[i] = otherStack.list[i];
    }
}

template <class Type>
stackType<Type>::stackType(int stackSize)
{

    assert(stackSize > 0);
    maxStackSize = stackSize;
    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType()
{
    delete[] list;
}

template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}
