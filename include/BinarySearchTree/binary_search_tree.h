#ifndef _BIN_SEARCH_TREE_H_
#define _BIN_SEARCH_TREE_H_

#include <cstddef>
#include <vector>

namespace data_structures {

template <typename T>
class BinarySearchTree {
   public:
    BinarySearchTree() : size_(0), root_(nullptr) {}
    ~BinarySearchTree() { DeleteTree(root_); }

    BinarySearchTree(const BinarySearchTree& bst) {
        DeleteTree(root_);
        root_ = CopyTree(root_, bst.root_);
        size_ = bst.size_;
    }
    BinarySearchTree& operator=(const BinarySearchTree& bst);

    BinarySearchTree(BinarySearchTree&&) = delete;
    BinarySearchTree& operator=(BinarySearchTree&&) = delete;

    bool Empty() const { return (0 == size_); }
    std::size_t Size() const { return size_; }
    bool Insert(const T& val);
    bool Erase(const T& val);
    bool Find(const T& val) const { return FindHelper(root_, val); }
    std::vector<T> GetKeys() const;

   private:
    struct Node {
        T val;
        struct Node* left;
        struct Node* right;

        Node(const T& v) : val(v), left(nullptr), right(nullptr) {}
    };

    struct Node* CopyTree(struct Node* dst, struct Node* src);
    void DeleteTree(struct Node* root);
    struct Node* InsertHelper(struct Node* root, const T& val);
    struct Node* FindHelper(struct Node* root, const T& val) const;
    struct Node* EraseHelper(struct Node* root, const T& val) const;
    void GetKeysHelper(struct Node* root, std::vector<T>& keys) const;

    std::size_t size_;
    struct Node* root_;
};

template <typename T>
struct BinarySearchTree<T>::Node* BinarySearchTree<T>::CopyTree(
    struct Node* dst, struct Node* src) {
    if (!src) return nullptr;

    dst = new Node(src->val);
    dst->left = CopyTree(dst->left, src->left);
    dst->right = CopyTree(dst->right, src->right);

    return dst;
}

template <typename T>
void BinarySearchTree<T>::DeleteTree(struct Node* root) {
    if (!root) return;

    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = nullptr;
    size_ = 0;
}

template <typename T>
struct BinarySearchTree<T>::Node* BinarySearchTree<T>::InsertHelper(
    struct Node* root, const T& val) {
    if (!root) {
        root = new Node(val);
    } else if (root->val < val) {
        root->right = InsertHelper(root->right, val);
    } else if (root->val > val) {
        root->left = InsertHelper(root->left, val);
    }
    return root;
}

template <typename T>
struct BinarySearchTree<T>::Node* BinarySearchTree<T>::FindHelper(
    struct Node* root, const T& val) const {
    if (!root) return nullptr;

    if (root->val == val)
        return root;
    else if (root->val < val)
        return FindHelper(root->right, val);
    else
        return FindHelper(root->left, val);
}

template <typename T>
struct BinarySearchTree<T>::Node* BinarySearchTree<T>::EraseHelper(
    struct Node* root, const T& val) const {
    if (!root) return nullptr;

    if (root->val == val) {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        } else if (!root->right) {
            struct Node* tmp = root->left;
            root->val = tmp->val;
            root->left = tmp->left;
            root->right = tmp->right;

            delete tmp;
        } else if (!root->left) {
            struct Node* tmp = root->right;
            root->val = tmp->val;
            root->left = tmp->left;
            root->right = tmp->right;

            delete tmp;
        } else {
            struct Node* predecessor = root;
            struct Node* successor = root->right;
            while (successor->left) {
                predecessor = successor;
                successor = successor->left;
            }

            root->val = successor->val;
            if (successor == root->right)
                predecessor->right = nullptr;
            else
                predecessor->left = nullptr;
            delete successor;
        }
    } else if (root->val < val) {
        root->right = EraseHelper(root->right, val);
    } else {
        root->left = EraseHelper(root->left, val);
    }
    return root;
}

template <typename T>
void BinarySearchTree<T>::GetKeysHelper(struct Node* root,
                                        std::vector<T>& keys) const {
    if (!root) return;

    GetKeysHelper(root->left, keys);
    keys.push_back(root->val);
    GetKeysHelper(root->right, keys);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(
    const BinarySearchTree& bst) {
    if (this == &bst) return *this;

    DeleteTree(root_);
    root_ = CopyTree(root_, bst.root_);
    size_ = bst.size_;

    return *this;
}

template <typename T>
bool BinarySearchTree<T>::Insert(const T& val) {
    if (Find(val)) return false;

    root_ = InsertHelper(root_, val);
    size_++;

    return true;
}

template <typename T>
bool BinarySearchTree<T>::Erase(const T& val) {
    if (!Find(val)) return false;

    root_ = EraseHelper(root_, val);
    size_--;

    return true;
}

template <typename T>
std::vector<T> BinarySearchTree<T>::GetKeys() const {
    std::vector<T> keys;
    GetKeysHelper(root_, keys);

    return keys;
}

}  // namespace data_structures

#endif
