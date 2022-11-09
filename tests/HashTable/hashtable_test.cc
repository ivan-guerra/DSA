#include "hashtable.h"

#include <gtest/gtest.h>

#include "hashtable_test_fixture.h"

TEST_F(HashTableTest, ShouldReturnTrueOnEmptyHashTable) {
    EXPECT_TRUE(empty_hashtable_.Empty());
}

TEST_F(HashTableTest, ShouldReturnFalseOnNonEmptyHashTable) {
    EXPECT_FALSE(nonempty_hashtable_.Empty());
}

TEST_F(HashTableTest, ShouldReturnZeroOnEmptyHashTable) {
    EXPECT_EQ(empty_hashtable_.Size(), 0);
}

TEST_F(HashTableTest, ShouldReturnNumberOfValuesInsertedOnNonEmptyHashTable) {
    EXPECT_EQ(nonempty_hashtable_.Size(), kDefaultNumElements);
}

TEST_F(HashTableTest, ShouldReturnCapacityProvidedAtConstruction) {
    EXPECT_EQ(kDefaultCapacity, empty_hashtable_.Capacity());
    EXPECT_EQ(kDefaultCapacity, nonempty_hashtable_.Capacity());
}

TEST_F(HashTableTest, ShouldReturnTrueForAllInsertedKeys) {
    for (int i = 0; i < kDefaultNumElements; ++i) {
        ASSERT_TRUE(nonempty_hashtable_.Contains(i));
    }
}

TEST_F(HashTableTest, ShouldReturnFalseForAllMissingKeys) {
    for (int i = 0; i < kDefaultNumElements; ++i) {
        ASSERT_FALSE(empty_hashtable_.Contains(i));
    }
}

TEST_F(HashTableTest, ShouldReturnCurrentLoadFactor) {
    const float kNonEmptyHashTableLoadFactor =
        static_cast<float>(kDefaultNumElements) /
        static_cast<float>(kDefaultCapacity);
    const float kEmptyHashTableLoadFactor = 0.f;

    EXPECT_EQ(kEmptyHashTableLoadFactor, empty_hashtable_.LoadFactor());
    EXPECT_EQ(kNonEmptyHashTableLoadFactor, nonempty_hashtable_.LoadFactor());
}

TEST_F(HashTableTest, ShouldInsertNewKeyValuePairViaInsert) {
    ASSERT_FALSE(nonempty_hashtable_.Contains(kTestKeyAndValue));
    nonempty_hashtable_.Insert(kTestKeyAndValue, kTestKeyAndValue);
    EXPECT_TRUE(nonempty_hashtable_.Contains(kTestKeyAndValue));
}

TEST_F(HashTableTest, ShouldInsertNewKeyValuePairViaIndexing) {
    ASSERT_FALSE(nonempty_hashtable_.Contains(kTestKeyAndValue));
    nonempty_hashtable_[kTestKeyAndValue] = kTestKeyAndValue;
    EXPECT_TRUE(nonempty_hashtable_.Contains(kTestKeyAndValue));
}

TEST_F(HashTableTest, ShouldOverrideExistingValueViaInsert) {
    ASSERT_EQ(nonempty_hashtable_[0], 0);
    nonempty_hashtable_.Insert(0, kTestKeyAndValue);
    EXPECT_EQ(nonempty_hashtable_[0], kTestKeyAndValue);
}

TEST_F(HashTableTest, ShouldOverrideExistingValueViaIndexing) {
    ASSERT_EQ(nonempty_hashtable_[0], 0);
    nonempty_hashtable_[0] = kTestKeyAndValue;
    EXPECT_EQ(nonempty_hashtable_[0], kTestKeyAndValue);
}

TEST_F(HashTableTest, ShouldEraseExistingElement) {
    ASSERT_TRUE(nonempty_hashtable_.Contains(0));
    EXPECT_TRUE(nonempty_hashtable_.Remove(0));
    EXPECT_FALSE(nonempty_hashtable_.Contains(0));
}

TEST_F(HashTableTest, ShouldReturnFalseWhenErasingNonExistingElement) {
    EXPECT_FALSE(empty_hashtable_.Remove(kTestKeyAndValue));
}

TEST_F(HashTableTest, ShouldRehashTableToMeetNewCapacity) {
    std::size_t new_capacity = kDefaultCapacity * 2;
    nonempty_hashtable_.Rehash(new_capacity);

    ASSERT_EQ(nonempty_hashtable_.Capacity(), new_capacity);
    ASSERT_EQ(nonempty_hashtable_.Size(), kDefaultNumElements);

    const float kNewLoadFactor = static_cast<float>(kDefaultNumElements) /
                                 static_cast<float>(new_capacity);
    EXPECT_FLOAT_EQ(kNewLoadFactor, nonempty_hashtable_.LoadFactor());

    for (int i = 0; i < kDefaultNumElements; ++i) {
        ASSERT_TRUE(nonempty_hashtable_.Contains(i));
    }
}
