#include "circular_queue.h"

#include <cstdlib>
#include <iostream>

int main(void) {
    CircularQueue<int, 5> q;
    CircularQueue<int, 5> q2;
    for (int i = 0; i < 5; ++i) q.Push(i + 1);

    q.Pop();
    q.Pop();
    q.Pop();
    q.Pop();

    for (int i = 0; i < 5; ++i) q.Push(i + 1);
    q2 = q;
    while (!q2.Empty()) {
        std::cout << q2.Front() << std::endl;
        q2.Pop();
    }

    exit(EXIT_SUCCESS);
}
