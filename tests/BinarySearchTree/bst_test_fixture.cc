#include "bst_test_fixture.h"

const int BinarySearchTreeTest::kBinarySearchTreeSize = 11;

void BinarySearchTreeTest::InitBalancedBst(const std::vector<int>& keys, int l,
                                           int r) {
    if (l > r) return;

    int m = (l + r) / 2;
    balanced_bst_.Insert(m);

    InitBalancedBst(keys, l, m - 1);
    InitBalancedBst(keys, m + 1, r);
}

void BinarySearchTreeTest::SetUp() {
    std::vector<int> keys;
    for (int i = 0; i < kBinarySearchTreeSize; ++i) {
        keys.push_back(i);
    }

    /* Init a height balanced BST with 11 elements in the range [0, 10]. */
    InitBalancedBst(keys, 0, keys.size() - 1);
}
