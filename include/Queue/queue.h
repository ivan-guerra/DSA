#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <list>

template <typename T>
class Queue {
   public:
    Queue() = default;
    ~Queue() = default;
    Queue(const Queue&) = default;
    Queue& operator=(const Queue&) = default;
    Queue(Queue&&) = default;
    Queue& operator=(Queue&&) = default;

    std::size_t Size() const { return data_.size(); }
    bool Empty() const { return data_.empty(); }
    const T& Front() const { return data_.front(); }
    T& Front() { return data_.front(); }
    void Push(const T& val) { data_.push_back(val); }
    void Pop() { data_.pop_front(); }

   private:
    std::list<T> data_;
};

#endif
