#include "search_test_fixture.h"

const int SearchTest::kMinKey = 0;
const int SearchTest::kMaxKey = 20;

void SearchTest::SetUp() {
    for (int i = kMinKey; i <= kMaxKey; i++) {
        sorted_keys_.push_back(i);
    }
}
