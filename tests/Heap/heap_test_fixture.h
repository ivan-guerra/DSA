#include <gtest/gtest.h>

#include "minheap.h"

class MinHeapTest : public ::testing::Test {
   protected:
    const int kDefaultNumElements = 16;

    void SetUp() final;

    data_structures::MinHeap<int> empty_minheap_;
    data_structures::MinHeap<int> nonempty_minheap_;
};
