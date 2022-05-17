//
//  linkedList.cpp
//  data_structures
//
//  Created by Daniil Buchko on 14.05.2022.
//

#include <iostream>

#include "linkedList.hpp"

// ==================== Node =====================

Node::Node(int newData)
{
    data = newData;
    next = nullptr;
}

// ================= linked list =================

linkedList::linkedList()
{
    head = nullptr;
    size = 0;
}

linkedList::~linkedList()
{
    Node *current = head;

    if (current == nullptr)
        return;

    while (current->next != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    delete current;
    size = 0;
}

Node *linkedList::lastNode()
{
    Node *nodePtr = head;

    while (nodePtr->next != nullptr)
        nodePtr = nodePtr->next;

    return nodePtr;
}

void linkedList::append(int value)
{
    Node *newNode = new Node(value);
    ++size;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *end = lastNode();
    end->next = newNode;
}

void linkedList::remove(size_t index)
{

    Node *prev = head;
    Node *next;

    if (index >= size)
    {
        std::cerr << "selected index is not valid";
        return;
    }

    if (index == 0 && size > 0)
    {
        prev = head->next;
        delete head;
        head = prev;
        --size;
        return;
    }

    while (index != 1)
    {
        prev = prev->next;
        --index;
    }

    next = prev->next->next;
    delete prev->next;
    prev->next = next;
    --size;
}

void linkedList::insertAtBeginning(int value)
{
    Node *newNode = new Node(value);
    ++size;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head; // copying link to next Node
    head = newNode;       // head now point to newNode
}

void linkedList::insertAfter(Node *&before, int value)
{

    if (size == 0)
    {
        std::cerr << "Cant insert before element in empty list." << std::endl;
    }

    Node *newNode = new Node(value);
    newNode->next = before->next;
    before->next = newNode;
    ++size;
}

Node *linkedList::get(size_t index)
{
    Node *node_ptr = head;

    if (size == 0 || index == 0 || index > size)
        return node_ptr;

    for (; index != 0; --index)
    {
        node_ptr = node_ptr->next;
    }

    return node_ptr;
}

void linkedList::print()
{
    Node *temp_ptr = head;
    int count = 1;
    std::string trailing;

    if (size == 0)
    {
        std::cout << "[]\n";
        return;
    }

    if (size <= 10)
    {
        std::cout << '[';

        while (temp_ptr != nullptr)
        {
            trailing = (count != size) ? ", " : "]\n";
            std::cout << temp_ptr->data << trailing;
            temp_ptr = temp_ptr->next;
            ++count;
        }
    }
    else
        std::cout << "[ ... ]\n";
}
