#include <gtest/gtest.h>

#include "circular_queue_test_fixture.h"

TEST_F(CircularQueueTest, ShouldReturnTrueWhenQueueIsEmpty) {
    EXPECT_TRUE(empty_queue_.Empty());
}

TEST_F(CircularQueueTest, ShouldReturnFalseWhenQueueIsNonEmpty) {
    EXPECT_FALSE(nonempty_queue_.Empty());
}

TEST_F(CircularQueueTest, ShouldReturnNumberOfElementsPushed) {
    EXPECT_EQ(kQueueSize, nonempty_queue_.Size());
}

TEST_F(CircularQueueTest, ShouldReturnElementAtTheFrontOfTheQueue) {
    EXPECT_EQ(0, nonempty_queue_.Front());
}

TEST_F(CircularQueueTest, ShouldReturnElementsInFifoOrder) {
    for (int i = 0; i < kQueueSize; ++i) {
        EXPECT_EQ(nonempty_queue_.Front(), i);
        nonempty_queue_.Pop();
    }
}

TEST_F(CircularQueueTest, ShouldCopyNonEmptyQueueToTempQueue) {
    data_structures::CircularQueue<int, kQueueSize> tmp;

    tmp = nonempty_queue_;
    for (int i = 0; i < kQueueSize; ++i) {
        ASSERT_FALSE(nonempty_queue_.Empty());
        ASSERT_FALSE(tmp.Empty());
        EXPECT_EQ(tmp.Front(), nonempty_queue_.Front());

        nonempty_queue_.Pop();
        tmp.Pop();
    }
}

TEST_F(CircularQueueTest, ShouldReturnFalseWhenPushingToFullQueue) {
    EXPECT_FALSE(nonempty_queue_.Push(0));
}

TEST_F(CircularQueueTest, ShouldReturnFalseWhenPoppingOnEmptyQueue) {
    EXPECT_FALSE(empty_queue_.Pop());
}
