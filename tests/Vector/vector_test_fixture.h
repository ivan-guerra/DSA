#include <gtest/gtest.h>

#include "vector.h"

class VectorTest : public ::testing::Test {
   protected:
    static const int kVectorSize;

    void SetUp() final;

    data_structures::Vector<int> empty_vector_;
    data_structures::Vector<int> nonempty_vector_;
};
