#pragma once

#include "i_sorting_algorithm.h"

template <typename T>
class QuickSortRecursiveImpl : public ISortingAlgorithmInPlace<T> {
public:
    // split data at the pivot element (right most),
    // such that all smaller elements than the pivot are left of it and all larger elements are right of it
    size_t split(std::vector<T>& data, size_t l, size_t r) const {
        auto i = l;
        auto j = r - 1;
        const auto& pivot = data[r];

        do {
            // find next element smaller than pivot
            while (i < r - 1 && data[i] < pivot) {
                i++;
            }

            // find next element greater than pivot
            while (j > l && data[j] >= pivot) {
                j--;
            }

            // swap smaller and greater elements
            if (i < j) {
                std::swap(data[i], data[j]);
            }
        } while (i < j);

        // place pivot at the right position to separate all smaller and larger elements than itself
        if (data[i] > pivot) {
            std::swap(data[i], data[r]);
        }

        // return pivot index
        return i;
    }

    void quicksort_recursive(std::vector<T>& data, size_t l, size_t r) const {
        if (l < r) {
            // split elements at a pivot element
            const auto pivot = split(data, l, r);

            // recursively sort left and right of pivot
            quicksort_recursive(data, l, pivot - 1);
            quicksort_recursive(data, pivot + 1, r);
        }
    }

    void sort_in_place(std::vector<T>& data) const override {
        quicksort_recursive(data, 0, data.size() - 1);
    }
};
