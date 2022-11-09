#include "vector_test_fixture.h"

const int VectorTest::kVectorSize = 5;

void VectorTest::SetUp() {
    for (int i = 0; i < kVectorSize; ++i) {
        nonempty_vector_.PushBack(i);
    }
}
