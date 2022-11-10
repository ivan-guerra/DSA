#include <gtest/gtest.h>

#include "heap_test_fixture.h"

TEST_F(MinHeapTest, ShouldReturnTrueOnEmptyHeap) {
    EXPECT_TRUE(empty_minheap_.Empty());
}

TEST_F(MinHeapTest, ShouldReturnFalseOnNonEmptyHeap) {
    EXPECT_FALSE(nonempty_minheap_.Empty());
}

TEST_F(MinHeapTest, ShouldReturnZeroOnEmptyHeap) {
    EXPECT_EQ(empty_minheap_.Size(), 0);
}

TEST_F(MinHeapTest, ShouldReturnNumElementInsertedOnNonEmptyHeap) {
    EXPECT_EQ(nonempty_minheap_.Size(), kDefaultNumElements);
}

TEST_F(MinHeapTest, ShouldReturnMinElement) {
    EXPECT_EQ(nonempty_minheap_.Top(), 0);
}

TEST_F(MinHeapTest, ShouldReturnElementsInAscendingOrder) {
    for (int i = 0; i < kDefaultNumElements; ++i) {
        ASSERT_EQ(nonempty_minheap_.Poll(), i);
    }
}

TEST_F(MinHeapTest, ShouldInsertElementAtTheTopOfTheHeap) {
    const int kNewMinElement = -1;
    nonempty_minheap_.Insert(kNewMinElement);
    ASSERT_EQ(nonempty_minheap_.Size(), kDefaultNumElements + 1);
    EXPECT_EQ(nonempty_minheap_.Top(), kNewMinElement);
}

TEST_F(MinHeapTest, ShouldInsertElementAtTheBottomOfTheHeap) {
    nonempty_minheap_.Insert(kDefaultNumElements);
    ASSERT_EQ(nonempty_minheap_.Size(), kDefaultNumElements + 1);
    for (int i = 0; i < kDefaultNumElements + 1; ++i) {
        ASSERT_EQ(nonempty_minheap_.Poll(), i);
    }
}
