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
static int Partition(std::vector<T>& keys, int l, int r) {
    T pivot_elem = keys[r];
    int pivot_idx = l - 1;
    for (int i = l; i < r; ++i) {
        if (keys[i] < pivot_elem) {
            pivot_idx++;
            std::swap(keys[i], keys[pivot_idx]);
        }
    }
    pivot_idx++;
    std::swap(keys[r], keys[pivot_idx]);

    return pivot_idx;
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

template <typename T>
void QuickSort(std::vector<T>& keys, int l, int r) {
    if (l >= r) return;

    int pivot = Partition(keys, l, r);
    QuickSort(keys, l, pivot - 1);
    QuickSort(keys, pivot + 1, r);
}

template <typename T>
void BubbleSort(std::vector<T>& keys) {
    for (std::size_t i = 1; i < keys.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (keys[j] > keys[j + 1]) {
                std::swap(keys[j], keys[j + 1]);
            } else {
                break;
            }
        }
    }
}

template <typename T>
T QuickSelect(std::vector<T>& keys, int k) {
    int left = 0;
    int right = keys.size() - 1;
    while (left != right) {
        int pivot_index = Partition(keys, left, right);
        if (k == pivot_index)
            return keys[pivot_index];
        else if (k < pivot_index)
            right = pivot_index - 1;
        else
            left = pivot_index + 1;
    }
    return keys[left];
}

}  // namespace algo

#endif
