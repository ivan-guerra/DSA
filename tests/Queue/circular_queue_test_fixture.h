#include <gtest/gtest.h>

#include "circular_queue.h"

class CircularQueueTest : public ::testing::Test {
   protected:
    static constexpr int kQueueSize = 5;

    void SetUp() final;

    data_structures::CircularQueue<int, kQueueSize> empty_queue_;
    data_structures::CircularQueue<int, kQueueSize> nonempty_queue_;
};
