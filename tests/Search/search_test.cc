#include <gtest/gtest.h>

#include "search_test_fixture.h"

TEST_F(SearchTest, ShouldReturnTrueForAllInsertedKeys) {
    for (int i = kMinKey; i <= kMaxKey; ++i) {
        ASSERT_TRUE(algo::BinarySearch(sorted_keys_, i));
        ASSERT_TRUE(
            algo::BinarySearch(sorted_keys_, i, 0, sorted_keys_.size() - 1));
    }
}

TEST_F(SearchTest, ShouldReturnFalseWhenSearchingOffLeftEnd) {
    ASSERT_FALSE(algo::BinarySearch(sorted_keys_, kMinKey - 1));
    ASSERT_FALSE(algo::BinarySearch(sorted_keys_, kMinKey - 1, 0,
                                    sorted_keys_.size() - 1));
}

TEST_F(SearchTest, ShouldReturnFalseWhenSearchingOffRightEnd) {
    ASSERT_FALSE(algo::BinarySearch(sorted_keys_, kMaxKey + 1));
    ASSERT_FALSE(algo::BinarySearch(sorted_keys_, kMaxKey + 1, 0,
                                    sorted_keys_.size() - 1));
}
