// #include "list/linkedList/linkedList.hpp"
#include "list/circularDoubleLinkedList/circularDoubleLinkedList.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    doubleLinkedList<int> x;
    x.insertLast(123);
    x.insertLast(123);
    std::cout << x;

    return 0;
}
