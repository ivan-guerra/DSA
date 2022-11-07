#include <gtest/gtest.h>

#include "queue.h"

class QueueTest : public ::testing::Test {
   protected:
    static const int kQueueSize;

    void SetUp() final;

    data_structures::Queue<int> empty_queue_;
    data_structures::Queue<int> nonempty_queue_;
};
