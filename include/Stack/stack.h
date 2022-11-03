#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>
#include <forward_list>

namespace data_structures {

template <typename T>
class Stack {
   public:
    Stack() = default;
    ~Stack() = default;
    Stack(const Stack& st) = default;
    Stack& operator=(const Stack& st) = default;
    Stack(Stack&&) = default;
    Stack& operator=(Stack&&) = default;

    std::size_t Size() const { return data_.size(); }
    bool Empty() const { return data_.empty(); }
    const T& Top() const { return data_.front(); }
    T& Top() { return data_.front(); }
    void Push(const T& val) { data_.push_front(val); }
    void Pop() { data_.pop_front(); }

   private:
    std::forward_list<T> data_;
};

}  // namespace data_structures

#endif
