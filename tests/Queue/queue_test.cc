#include <gtest/gtest.h>

#include "queue_test_fixture.h"

TEST_F(QueueTest, ShouldReturnTrueWhenQueueIsEmpty) {
    EXPECT_TRUE(empty_queue_.Empty());
}

TEST_F(QueueTest, ShouldReturnFalseWhenQueueIsNonEmpty) {
    EXPECT_FALSE(nonempty_queue_.Empty());
}

TEST_F(QueueTest, ShouldReturnNumberOfElementsPushed) {
    EXPECT_EQ(kQueueSize, nonempty_queue_.Size());
}

TEST_F(QueueTest, ShouldReturnElementAtTheFrontOfTheQueue) {
    EXPECT_EQ(0, nonempty_queue_.Front());
}

TEST_F(QueueTest, ShouldReturnElementsInFifoOrder) {
    for (int i = 0; i < QueueTest::kQueueSize; ++i) {
        EXPECT_EQ(nonempty_queue_.Front(), i);
        nonempty_queue_.Pop();
    }
}
