#include "array.h"

#include <gtest/gtest.h>

#include <cstddef>

TEST(ArrayTest, ShouldReturnMaxSizeEqualToTemplateParamN) {
    data_structures::Array<int, 42> arr;
    EXPECT_EQ(arr.MaxSize(), 42);
}

TEST(ArrayTest, ShouldFillArrayWithOnes) {
    constexpr int kArrSize = 42;
    data_structures::Array<int, kArrSize> arr;

    arr.Fill(1);

    for (std::size_t i = 0; i < kArrSize; ++i) {
        ASSERT_EQ(1, arr[i]);
    }
}

TEST(ArrayTest, ShouldCopyArr1ToArr2) {
    constexpr int kArrSize = 42;
    data_structures::Array<int, kArrSize> arr1;
    data_structures::Array<int, kArrSize> arr2;

    arr1.Fill(1);
    arr2 = arr1;
    for (std::size_t i = 0; i < kArrSize; ++i) {
        ASSERT_EQ(arr1[i], arr2[i]);
    }
}
