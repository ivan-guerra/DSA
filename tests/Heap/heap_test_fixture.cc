#include "heap_test_fixture.h"

void MinHeapTest::SetUp() {
    for (int i = kDefaultNumElements - 1; i >= 0; --i) {
        nonempty_minheap_.Insert(i);
    }
}
