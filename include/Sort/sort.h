#ifndef _SORT_H_
#define _SORT_H_

#include <algorithm>
#include <vector>

namespace algo {

template <typename T>
static int bsearch(const std::vector<T>& keys, const T& key, int l, int r) {
    int m = (l + r) / 2;
    while (l <= r) {
        m = (l + r) / 2;
        if (keys[m] == key)
            return m;
        else if (keys[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

template <typename T>
void InsertionSort(std::vector<T>& keys) {
    int i = 1;
    while (i < static_cast<int>(keys.size())) {
        int j = i - 1;
        T key = keys[i];
        while ((j >= 0) && (keys[j] > key)) {
            keys[j + 1] = keys[j];
            --j;
        }
        i++;
    }
}

template <typename T>
void BinaryInsertionSort(std::vector<T>& keys) {
    int i = 1;
    while (i < static_cast<int>(keys.size())) {
        T key = keys[i];
        int location = algo::bsearch(keys, key, 0, i - 1);
        int j = i - 1;
        while (j >= location) {
            keys[j + 1] = keys[j];
            --j;
        }
        keys[j + 1] = key;
        ++i;
    }
}

}  // namespace algo

#endif
