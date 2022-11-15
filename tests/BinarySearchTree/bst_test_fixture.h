#include <gtest/gtest.h>

#include "binary_search_tree.h"

class BinarySearchTreeTest : public ::testing::Test {
   protected:
    static const int kBinarySearchTreeSize;

    void SetUp() final;

    data_structures::BinarySearchTree<int> empty_bst_;
    data_structures::BinarySearchTree<int> balanced_bst_;

   private:
    void InitBalancedBst(const std::vector<int>& keys, int l, int r);
};
