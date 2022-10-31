#include "array.h"

#include <cstdlib>
#include <iostream>

int main(void) {
    Array<int, 10> my_array;
    my_array.Fill(0);
    for (std::size_t i = 0; i < my_array.Size(); ++i) {
        std::cout << my_array[i] << std::endl;
    }

    exit(EXIT_SUCCESS);
}
