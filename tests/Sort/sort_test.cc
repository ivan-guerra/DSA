#include <gtest/gtest.h>

#include <cstddef>

#include "sort_test_fixture.h"

TEST_F(SortTest, ShouldReturnSortedKeysAfterInsertionSort) {
    algo::InsertionSort(unsorted_keys_);
    ASSERT_TRUE(std::is_sorted(unsorted_keys_.begin(), unsorted_keys_.end()));
}

TEST_F(SortTest, ShouldReturnSortedKeysAfterBinaryInsertionSort) {
    algo::BinaryInsertionSort(unsorted_keys_);
    ASSERT_TRUE(std::is_sorted(unsorted_keys_.begin(), unsorted_keys_.end()));
}

TEST_F(SortTest, ShouldReturnSortedKeysAfterMergeSort) {
    algo::MergeSort(unsorted_keys_, 0, unsorted_keys_.size() - 1);
    ASSERT_TRUE(std::is_sorted(unsorted_keys_.begin(), unsorted_keys_.end()));
}

TEST_F(SortTest, ShouldReturnSortedKeysAfterQuickSort) {
    algo::QuickSort(unsorted_keys_, 0, unsorted_keys_.size() - 1);
    ASSERT_TRUE(std::is_sorted(unsorted_keys_.begin(), unsorted_keys_.end()));
}

TEST_F(SortTest, ShouldReturnSortedKeysAfterBubbleSort) {
    algo::BubbleSort(unsorted_keys_);
    ASSERT_TRUE(std::is_sorted(unsorted_keys_.begin(), unsorted_keys_.end()));
}

TEST_F(SortTest, ShouldReturnKthSmallestElement) {
    std::vector<int> sorted_keys = unsorted_keys_;
    std::sort(sorted_keys.begin(), sorted_keys.end());
    for (std::size_t i = 0; i < sorted_keys.size(); ++i) {
        ASSERT_EQ(sorted_keys[i], algo::QuickSelect(unsorted_keys_, i));
    }
}
