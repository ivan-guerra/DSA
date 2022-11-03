#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>
#include <forward_list>

namespace data_structures {

template <typename T>
class Stack {
   public:
    Stack() : size_(0) {}
    ~Stack() = default;
    Stack(const Stack& st) = default;
    Stack& operator=(const Stack& st) = default;
    Stack(Stack&&) = default;
    Stack& operator=(Stack&&) = default;

    std::size_t Size() const { return size_; }
    bool Empty() const { return data_.empty(); }
    const T& Top() const { return data_.front(); }
    T& Top() { return data_.front(); }
    void Push(const T& val);
    void Pop();

   private:
    std::forward_list<T> data_;
    std::size_t size_;
};

template <typename T>
void Stack<T>::Push(const T& val) {
    data_.push_front(val);
    size_++;
}

template <typename T>
void Stack<T>::Pop() {
    data_.pop_front();
    size_--;
}

}  // namespace data_structures

#endif
