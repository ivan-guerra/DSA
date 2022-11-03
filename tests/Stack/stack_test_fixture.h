#include <gtest/gtest.h>

#include "stack.h"

class StackTest : public ::testing::Test {
   protected:
    static const int kStackSize;

    void SetUp() final;

    data_structures::Stack<int> empty_stack_;
    data_structures::Stack<int> nonempty_stack_;
};
