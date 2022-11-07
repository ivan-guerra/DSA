#include "singly_linked_list_test_fixture.h"

const int SinglyLinkedListTest::kSinglyLinkedListSize = 5;

void SinglyLinkedListTest::SetUp() {
    for (int i = 0; i < kSinglyLinkedListSize; ++i) {
        nonempty_list_.PushFront(i);
        list_with_dupes_.PushFront(0);
    }
}
