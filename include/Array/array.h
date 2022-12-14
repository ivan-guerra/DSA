#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstdint>

namespace data_structures {

template <typename T, std::size_t N>
class Array {
   public:
    Array() = default;
    ~Array() = default;
    Array(const Array& rhs) { Copy(rhs); }
    Array(Array&&) = delete;

    Array& operator=(const Array& rhs);
    Array& operator=(Array&&) = delete;
    const T& operator[](std::size_t i) const { return data_[i]; }
    T& operator[](std::size_t i) { return data_[i]; }

    std::size_t MaxSize() const { return N; }
    void Fill(const T& val);

   private:
    void Copy(const Array& rhs);

    T data_[N];
};

template <typename T, std::size_t N>
void Array<T, N>::Copy(const Array& rhs) {
    for (std::size_t i = 0; i < rhs.MaxSize(); ++i) {
        data_[i] = rhs[i];
    }
}

template <typename T, std::size_t N>
Array<T, N>& Array<T, N>::operator=(const Array<T, N>& rhs) {
    if (this == &rhs) return *this;

    Copy(rhs);

    return *this;
}

template <typename T, std::size_t N>
void Array<T, N>::Fill(const T& val) {
    for (std::size_t i = 0; i < N; ++i) {
        data_[i] = val;
    }
}

}  // namespace data_structures

#endif
