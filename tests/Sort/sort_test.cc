#include <gtest/gtest.h>

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
