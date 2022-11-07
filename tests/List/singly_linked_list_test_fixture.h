#include <gtest/gtest.h>

#include "singly_linked_list.h"

class SinglyLinkedListTest : public ::testing::Test {
   protected:
    static const int kSinglyLinkedListSize;

    void SetUp() final;

    data_structures::SinglyLinkedList<int> empty_list_;
    data_structures::SinglyLinkedList<int> nonempty_list_;
    data_structures::SinglyLinkedList<int> list_with_dupes_;
};
