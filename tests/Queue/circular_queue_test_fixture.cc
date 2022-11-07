#include "circular_queue_test_fixture.h"

void CircularQueueTest::SetUp() {
    for (int i = 0; i < kQueueSize; ++i) {
        nonempty_queue_.Push(i);
    }
}
