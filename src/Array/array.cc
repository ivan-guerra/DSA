#include "array.h"

#include <cstdlib>
#include <iostream>

template <typename T, std::size_t N>
void PrintArray(Array<T, N> data) {
    std::cout << "[";
    for (std::size_t i = 0; i < data.Size() - 1; ++i) {
        std::cout << data[i] << ' ';
    }
    std::cout << data[data.Size() - 1] << "]" << std::endl;
}

int main(void) {
    Array<int, 10> my_array;
    my_array.Fill(0);

    /* Note, this is a pass by value call meaning the argument array will
       trigger the copy constructor of the Array class. */
    PrintArray(my_array);

    for (std::size_t i = 0; i < my_array.Size(); ++i) {
        my_array[i] = i + 1;
    }
    PrintArray(my_array);

    exit(EXIT_SUCCESS);
}
