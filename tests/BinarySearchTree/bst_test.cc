#include <gtest/gtest.h>

#include <algorithm>

#include "bst_test_fixture.h"

TEST_F(BinarySearchTreeTest, ShouldReturnTrueOnEmptyBst) {
    EXPECT_TRUE(empty_bst_.Empty());
}

TEST_F(BinarySearchTreeTest, ShouldReturnFalseOnNonEmptyBst) {
    EXPECT_FALSE(balanced_bst_.Empty());
}

TEST_F(BinarySearchTreeTest, ShouldReturnZeroOnEmptyBst) {
    EXPECT_EQ(0, empty_bst_.Size());
}

TEST_F(BinarySearchTreeTest, ShouldReturnNumKeysInsertedOnNonEmptyBst) {
    EXPECT_EQ(kBinarySearchTreeSize, balanced_bst_.Size());
}

TEST_F(BinarySearchTreeTest, ShouldReturnTrueWhenSearchingForExistingKey) {
    for (int i = 0; i < kBinarySearchTreeSize; ++i) {
        ASSERT_TRUE(balanced_bst_.Find(i));
    }
}

TEST_F(BinarySearchTreeTest, ShouldReturnFalseWhenSearchingForNonExistentKey) {
    for (int i = 0; i < kBinarySearchTreeSize; ++i) {
        ASSERT_FALSE(empty_bst_.Find(i));
    }
}

TEST_F(BinarySearchTreeTest, ShouldReturnTrueWhenInsertingNonExistentKey) {
    ASSERT_EQ(0, empty_bst_.Size());
    for (int i = 0; i < kBinarySearchTreeSize; ++i) {
        ASSERT_TRUE(empty_bst_.Insert(i));
    }
    ASSERT_EQ(kBinarySearchTreeSize, empty_bst_.Size());
}

TEST_F(BinarySearchTreeTest, ShouldReturnFalseWhenInsertingDuplicateKey) {
    for (int i = 0; i < kBinarySearchTreeSize; ++i) {
        ASSERT_FALSE(balanced_bst_.Insert(i));
    }
}

TEST_F(BinarySearchTreeTest, ShouldReturnSortedSetOfKeys) {
    std::vector<int> sorted_keys = balanced_bst_.GetKeys();
    EXPECT_TRUE(std::is_sorted(sorted_keys.begin(), sorted_keys.end()));
}

TEST_F(BinarySearchTreeTest, ShouldEraseKeyWithNoChildren) {
    int deletion_key = 0;
    ASSERT_TRUE(balanced_bst_.Erase(deletion_key));
    ASSERT_FALSE(balanced_bst_.Find(deletion_key));

    std::vector<int> sorted_keys = balanced_bst_.GetKeys();
    EXPECT_TRUE(std::is_sorted(sorted_keys.begin(), sorted_keys.end()));
}

TEST_F(BinarySearchTreeTest, ShouldEraseKeyWithOneChild) {
    int deletion_key = 9;
    ASSERT_TRUE(balanced_bst_.Erase(deletion_key));
    ASSERT_FALSE(balanced_bst_.Find(deletion_key));

    std::vector<int> sorted_keys = balanced_bst_.GetKeys();
    EXPECT_TRUE(std::is_sorted(sorted_keys.begin(), sorted_keys.end()));
}

TEST_F(BinarySearchTreeTest, ShouldEraseKeyWithTwoChildren) {
    int deletion_key = 5;
    ASSERT_TRUE(balanced_bst_.Erase(deletion_key));
    ASSERT_FALSE(balanced_bst_.Find(deletion_key));

    std::vector<int> sorted_keys = balanced_bst_.GetKeys();
    EXPECT_TRUE(std::is_sorted(sorted_keys.begin(), sorted_keys.end()));
}

TEST_F(BinarySearchTreeTest, ShouldEraseAllKeys) {
    for (int i = 0; i < kBinarySearchTreeSize; ++i) {
        ASSERT_TRUE(balanced_bst_.Erase(i));
    }
    ASSERT_EQ(0, balanced_bst_.Size());
}

TEST_F(BinarySearchTreeTest, ShouldCopyTreeFromNonEmptyToEmptyBst) {
    empty_bst_ = balanced_bst_;
    for (int i = 0; i < kBinarySearchTreeSize; ++i) {
        ASSERT_TRUE(empty_bst_.Find(i));
    }
    /* TODO: Add check to verify that tree structures are equivalent. */
}

TEST_F(BinarySearchTreeTest, ShouldCopyTreeFromEmptyToNonEmptyBst) {
    balanced_bst_ = empty_bst_;
    ASSERT_TRUE(balanced_bst_.Empty());
}
