#include <gtest/gtest.h>

#include "vector_test_fixture.h"

TEST_F(VectorTest, ShouldReturnTrueOnEmptyVector) {
    EXPECT_TRUE(empty_vector_.Empty());
}

TEST_F(VectorTest, ShouldReturnFalseOnNonEmptyVector) {
    EXPECT_FALSE(nonempty_vector_.Empty());
}

TEST_F(VectorTest, ShouldReturnZeroOnEmptyVector) {
    EXPECT_EQ(empty_vector_.Size(), 0);
}

TEST_F(VectorTest, ShouldReturnSizeOfNonEmptyVector) {
    EXPECT_EQ(nonempty_vector_.Size(), kVectorSize);
}

TEST_F(VectorTest, ShouldReturnIncreasedCapacityAfterkVectorSizeInsertions) {
    EXPECT_EQ(nonempty_vector_.Capacity(), 8);
}

TEST_F(VectorTest, ShouldCopyNonEmptyVectorToEmptyVector) {
    empty_vector_ = nonempty_vector_;
    ASSERT_EQ(empty_vector_.Size(), nonempty_vector_.Size());
    for (int i = 0; i < kVectorSize; ++i) {
        EXPECT_EQ(empty_vector_[i], nonempty_vector_[i]);
    }
}

TEST_F(VectorTest, ShouldCopyEmptyVectorToNonEmptyVector) {
    nonempty_vector_ = empty_vector_;
    EXPECT_EQ(nonempty_vector_.Size(), 0);
    EXPECT_TRUE(nonempty_vector_.Empty());
}

TEST_F(VectorTest, ShouldPopAllElementsOffVector) {
    for (int i = 0; i < kVectorSize; ++i) {
        nonempty_vector_.PopBack();
        ASSERT_EQ(nonempty_vector_.Size(), kVectorSize - (i + 1));
    }
    EXPECT_TRUE(nonempty_vector_.Empty());
}
