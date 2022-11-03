#include <gtest/gtest.h>

#include "stack_test_fixture.h"

TEST_F(StackTest, ShouldReturnTrueWhenStackIsEmpty) {
    EXPECT_TRUE(empty_stack_.Empty());
}

TEST_F(StackTest, ShouldReturnFalseWhenStackIsNonEmpty) {
    EXPECT_FALSE(nonempty_stack_.Empty());
}

TEST_F(StackTest, ShouldReturnNumberOfElementsPushed) {
    EXPECT_EQ(kStackSize, nonempty_stack_.Size());
}

TEST_F(StackTest, ShouldReturnElementAtTheTopOfTheStack) {
    EXPECT_EQ(kStackSize - 1, nonempty_stack_.Top());
}

TEST_F(StackTest, ShouldReturnElementsInLifoOrder) {
    int i = StackTest::kStackSize;
    while (--i) {
        EXPECT_EQ(nonempty_stack_.Top(), i);
        nonempty_stack_.Pop();
    }
}
