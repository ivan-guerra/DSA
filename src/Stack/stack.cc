#include "stack.h"

#include <cstdlib>
#include <iostream>

int main(void) {
    Stack<int> st;
    for (int i = 0; i < 10; ++i) {
        st.Push(i);
    }

    while (!st.Empty()) {
        std::cout << st.Top() << std::endl;
        st.Pop();
    }

    exit(EXIT_SUCCESS);
}
