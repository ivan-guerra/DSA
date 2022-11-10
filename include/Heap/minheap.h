#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <algorithm>
#include <cstddef>
#include <vector>

namespace data_structures {

template <typename T>
class MinHeap {
   public:
    MinHeap() = default;
    ~MinHeap() = default;

    MinHeap(const MinHeap&) = default;
    MinHeap(MinHeap&&) = default;

    MinHeap& operator=(const MinHeap&) = default;
    MinHeap& operator=(MinHeap&&) = default;

    bool Empty() const { return data_.empty(); }
    std::size_t Capacity() const { return data_.capacity(); }
    std::size_t Size() const { return data_.size(); }

    const T& Top() const { return data_.front(); }
    T& Top() { return data_.front(); }
    T Poll();
    void Insert(const T& val);

   private:
    void HeapifyDown();
    void HeapifyUp();

    int GetParentIndex(int child_index) const {
        return ((child_index - 1) / 2);
    }
    int GetLeftChildIndex(int parent_index) const {
        return (parent_index * 2 + 1);
    }
    int GetRightChildIndex(int parent_index) const {
        return (parent_index * 2 + 2);
    }

    bool HasParent(int child_index) const {
        return (GetParentIndex(child_index) >= 0);
    }
    bool HasLeftChild(int parent_index) const {
        return (GetLeftChildIndex(parent_index) < static_cast<int>(Size()));
    }
    bool HasRightChild(int parent_index) const {
        return (GetRightChildIndex(parent_index) < static_cast<int>(Size()));
    }

    T& GetParent(int child_index) { return data_[GetParentIndex(child_index)]; }
    T& GetLeftChild(int parent_index) {
        return data_[GetLeftChildIndex(parent_index)];
    }
    T& GetRightChild(int parent_index) {
        return data_[GetRightChildIndex(parent_index)];
    }

    std::vector<T> data_;
};

template <typename T>
void MinHeap<T>::HeapifyUp() {
    int index = Size() - 1;
    while (HasParent(index) && (GetParent(index) > data_[index])) {
        std::swap(data_[index], data_[GetParentIndex(index)]);
        index = GetParentIndex(index);
    }
}

template <typename T>
void MinHeap<T>::HeapifyDown() {
    int index = 0;
    while (HasLeftChild(index)) {
        int smaller_child_index = GetLeftChildIndex(index);
        if (HasRightChild(index) &&
            (GetRightChild(index) < data_[smaller_child_index])) {
            smaller_child_index = GetRightChildIndex(index);
        }

        if (data_[index] < data_[smaller_child_index]) {
            break;
        } else {
            std::swap(data_[index], data_[smaller_child_index]);
            index = smaller_child_index;
        }
    }
}

template <typename T>
T MinHeap<T>::Poll() {
    T ret = data_[0];

    data_[0] = data_.back();
    data_.pop_back();

    if (!Empty()) HeapifyDown();

    return ret;
}

template <typename T>
void MinHeap<T>::Insert(const T& val) {
    data_.push_back(val);
    HeapifyUp();
}

}  // namespace data_structures

#endif
