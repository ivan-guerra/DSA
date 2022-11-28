#include <gtest/gtest.h>

#include <vector>

#include "sort.h"

class SortTest : public ::testing::Test {
   protected:
    void SetUp() final;

    std::vector<int> unsorted_keys_;
};
