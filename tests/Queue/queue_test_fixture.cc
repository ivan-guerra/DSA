#include "queue_test_fixture.h"

const int QueueTest::kQueueSize = 5;

void QueueTest::SetUp() {
    for (int i = 0; i < kQueueSize; ++i) {
        nonempty_queue_.Push(i);
    }
}
