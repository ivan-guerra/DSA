#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstddef>

namespace data_structures {

template <typename T>
class Vector {
   public:
    Vector();
    ~Vector();

    Vector(const Vector& rhs) { Copy(rhs); }
    Vector(Vector&&) = delete;

    Vector& operator=(const Vector& rhs);
    Vector& operator=(Vector&&) = delete;

    T& operator[](int i) { return data_[i]; }
    const T& operator[](int i) const { return data_[i]; }

    bool Empty() const { return (0 == size_); }
    std::size_t Size() const { return size_; }
    std::size_t Capacity() const { return capacity_; }

    void PushBack(const T& val);
    void PopBack();
    T& Front() { return data_[0]; }
    const T& Front() const { return data_[0]; }
    T& Back() { return data_[size_ - 1]; }
    const T& Back() const { return data_[size_ - 1]; }

   private:
    static const int kScaleFactor = 2;

    void Copy(const Vector& rhs);

    T* data_;
    std::size_t size_;
    std::size_t capacity_;
};

template <typename T>
void Vector<T>::Copy(const Vector& rhs) {
    if (data_) delete[] data_;

    data_ = new T[rhs.capacity_];
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    for (std::size_t i = 0; i < rhs.size_; ++i) {
        data_[i] = rhs.data_[i];
    }
}

template <typename T>
Vector<T>::Vector() : data_(nullptr), size_(0), capacity_(1) {
    data_ = new T[capacity_];
}

template <typename T>
Vector<T>::~Vector() {
    if (data_) delete[] data_;
    size_ = 0;
    capacity_ = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs) {
    if (this != &rhs) Copy(rhs);
    return *this;
}

template <typename T>
void Vector<T>::PushBack(const T& val) {
    if (size_ == capacity_) {
        /* TODO: It's possible for new to throw std::bad_alloc. We should
           probably handle that... */

        /* Place Vector data in a temp buffer. */
        T* tmp = new T[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            tmp[i] = data_[i];
        }

        /* Scale up the Vector capacity and allocate a new buffer with that
           new capacity. */
        delete[] data_;
        capacity_ *= kScaleFactor;
        data_ = new T[capacity_];

        /* Copy the data from the temp buffer and free the temp buffer. */
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = tmp[i];
        }

        delete[] tmp;
    }

    data_[size_++] = val;
}

template <typename T>
void Vector<T>::PopBack() {
    if (size_ > 0) size_--;
}

}  // namespace data_structures

#endif
