#include <gtest/gtest.h>

#include <vector>

#include "search.h"

class SearchTest : public ::testing::Test {
   protected:
    static const int kMinKey;
    static const int kMaxKey;

    void SetUp() final;

    std::vector<int> sorted_keys_;
};
