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
static void Merge(std::vector<T>& keys, int l, int m, int r) {
    int llen = m - l + 1;
    T larr[llen];

    int rlen = r - m;
    T rarr[rlen];

    for (int i = 0; i < llen; ++i) larr[i] = keys[l + i];
    for (int i = 0; i < rlen; ++i) rarr[i] = keys[m + i + 1];

    int i = 0;
    int j = 0;
    int k = l;
    while ((i < llen) && (j < rlen)) {
        if (larr[i] <= rarr[j])
            keys[k++] = larr[i++];
        else
            keys[k++] = rarr[j++];
    }

    while (i < llen) keys[k++] = larr[i++];
    while (j < rlen) keys[k++] = rarr[j++];
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

template <typename T>
void MergeSort(std::vector<T>& keys, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    MergeSort(keys, l, m);
    MergeSort(keys, m + 1, r);

    Merge(keys, l, m, r);
}

}  // namespace algo

#endif
