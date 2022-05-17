//
//  stackADT.h
//  stack
//
//  Created by Daniil Buchko on 15.05.2022.
//

#ifndef stackADT_h
#define stackADT_h

template <class Type>
class stackADT
{
    // Last in First out.
    // Stack of predefined size is initialized
    // via array. Then new elements of Type are
    // added on the top of the stack, where top
    // is the index of last element in the array.
    //
    // stackTop - index of top element in array
    //
    // --------
    // Example:
    // --------
    //
    //    0  1  2  3  4  5
    //   [ ][ ][ ][ ][ ][ ]
    //    a  b  c
    //
    // stackTop = 2;
    // // pushing e
    //
    //    0  1  2  3  4  5
    //   [ ][ ][ ][ ][ ][ ]
    //    a  b  c  e
    // stackTop = 2;

public:
    virtual void initializeStack() = 0;
    // cleares stack before we begin to use it

    virtual bool isEmptyStack() const = 0;
    // checks if stack is empty

    virtual bool isFullStack() const = 0;
    // checks if stack is full

    virtual void push(const Type &newItem) = 0;
    // push elemnt on top
    // stack must exist and not be full

    virtual Type top() const = 0;
    // retrieve element from the top of the stack
    // stack must exist before we retrieve top element

    virtual void pop() = 0;
    // remove element from the top
    // stack must exist before we remove top element
};

#endif /* stackADT_h */
