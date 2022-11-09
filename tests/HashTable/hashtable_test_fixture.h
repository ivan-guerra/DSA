#include <gtest/gtest.h>

#include "hashtable.h"

class HashTableTest : public ::testing::Test {
   protected:
    const std::size_t kDefaultCapacity = 32;
    const int kDefaultNumElements = 16;
    const int kTestKeyAndValue = 1337;

    HashTableTest()
        : empty_hashtable_(kDefaultCapacity),
          nonempty_hashtable_(kDefaultCapacity) {}

    void SetUp() final;

    data_structures::HashTable<int, int> empty_hashtable_;
    data_structures::HashTable<int, int> nonempty_hashtable_;
};
