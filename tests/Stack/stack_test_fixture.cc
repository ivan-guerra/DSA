#include "stack_test_fixture.h"

const int StackTest::kStackSize = 5;

void StackTest::SetUp() {
    for (int i = 0; i < kStackSize; ++i) {
        nonempty_stack_.Push(i);
    }
}
