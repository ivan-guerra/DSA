#include <gtest/gtest.h>

#include "singly_linked_list_test_fixture.h"

TEST_F(SinglyLinkedListTest, ShouldReturnTrueWhenListIsEmpty) {
    EXPECT_TRUE(empty_list_.Empty());
}

TEST_F(SinglyLinkedListTest, ShouldReturnFalseWhenListIsNonEmpty) {
    EXPECT_FALSE(nonempty_list_.Empty());
}

TEST_F(SinglyLinkedListTest, ShouldReturnEmptyAfterReversal) {
    empty_list_.Reverse();
    EXPECT_TRUE(empty_list_.Empty());
}

TEST_F(SinglyLinkedListTest, ShouldReturnSizeOfList) {
    EXPECT_EQ(0, empty_list_.Size());
    EXPECT_EQ(kSinglyLinkedListSize, nonempty_list_.Size());
}

TEST_F(SinglyLinkedListTest, ShouldReturnListInReverseOrder) {
    nonempty_list_.Reverse();
    for (int i = 0; i < kSinglyLinkedListSize; ++i) {
        EXPECT_EQ(i, nonempty_list_.Front());
        nonempty_list_.PopFront();
    }
}

TEST_F(SinglyLinkedListTest, ShouldRemoveAllElementsInList) {
    for (int i = 0; i < kSinglyLinkedListSize; ++i) {
        nonempty_list_.Remove(i);
    }
    EXPECT_TRUE(nonempty_list_.Empty());
}

TEST_F(SinglyLinkedListTest, ShouldRemoveAllDuplicates) {
    list_with_dupes_.Unique();
    ASSERT_EQ(list_with_dupes_.Size(), 1);
    EXPECT_EQ(list_with_dupes_.Front(), 0);
}
