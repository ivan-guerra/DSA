#include "singly_linked_list.h"

#include <cstdlib>
#include <iostream>

int main(void) {
    SinglyLinkedList<int> lst1;
    SinglyLinkedList<int> lst2;
    for (int i = 0; i < 10; ++i) {
        lst2.PushFront(i + 1);
    }
    lst1 = lst2;

    while (!lst1.Empty()) {
        std::cout << lst1.Front() << std::endl;
        lst1.PopFront();
    }

    return 0;
}
