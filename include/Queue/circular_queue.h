#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_

#include <cmath>
#include <cstddef>

namespace data_structures {

template <typename T, std::size_t N>
class CircularQueue {
   public:
    CircularQueue() : head_(0), tail_(0) {}
    ~CircularQueue() = default;
    CircularQueue(const CircularQueue& q) { Copy(q); }
    CircularQueue& operator=(const CircularQueue&);
    CircularQueue(CircularQueue&&) = delete;
    CircularQueue& operator=(CircularQueue&&) = delete;

    std::size_t Size() const { return std::abs(head_ - tail_); }
    bool Empty() const { return (head_ == tail_); }
    const T& Front() const { return data_[head_]; }
    T& Front() { return data_[head_]; }
    bool Push(const T& val);
    bool Pop();

   private:
    void Copy(const CircularQueue& rhs);

    T data_[N + 1];
    int head_;
    int tail_;
};

template <typename T, std::size_t N>
void CircularQueue<T, N>::Copy(const CircularQueue& rhs) {
    head_ = rhs.head_;
    tail_ = rhs.tail_;

    for (std::size_t i = 0; i < N + 1; ++i) {
        data_[i] = rhs.data_[i];
    }
}

template <typename T, std::size_t N>
CircularQueue<T, N>& CircularQueue<T, N>::operator=(const CircularQueue& rhs) {
    if (this == &rhs) return *this;

    Copy(rhs);

    return *this;
}

template <typename T, std::size_t N>
bool CircularQueue<T, N>::Push(const T& val) {
    int next_slot = (tail_ + 1) % (N + 1);
    if (next_slot == head_) return false;

    data_[tail_] = val;
    tail_ = next_slot;
    return true;
}

template <typename T, std::size_t N>
bool CircularQueue<T, N>::Pop() {
    if (Empty()) return false;

    head_ = (head_ + 1) % (N + 1);
    return true;
}

}  // namespace data_structures

#endif
