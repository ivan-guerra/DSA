#ifndef _ALGO_H_
#define _ALGO_H_

#include <vector>

namespace algo {

template <typename T>
bool BinarySearch(const std::vector<T>& keys, const T& key) {
    int l = 0;
    int r = keys.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (keys[m] == key)
            return true;
        else if (key < keys[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}

template <typename T>
bool BinarySearch(const std::vector<T>& keys, const T& key, int l, int r) {
    if (l > r) return false;

    int m = (l + r) / 2;
    if (keys[m] == key)
        return true;
    else if (key < keys[m])
        return BinarySearch(keys, key, l, m - 1);
    else
        return BinarySearch(keys, key, m + 1, r);
}

}  // namespace algo

#endif
