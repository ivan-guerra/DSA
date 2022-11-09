#include "hashtable_test_fixture.h"

void HashTableTest::SetUp() {
    for (int i = 0; i < kDefaultNumElements; ++i) {
        nonempty_hashtable_[i] = i;
    }
}
