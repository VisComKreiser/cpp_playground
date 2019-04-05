#pragma once

#include "i_sorting_algorithm.h"

template <typename T>
class BubbleSortImpl : public ISortingAlgorithmInPlace<T> {
public:
    // sped up version of bubble sort:
    // perform bubble sort iterations as long as elements are swapped
    // if two elements are swapped, set the iteration count "n" to that new index
    // -> the last elements in the vector are already sorted
    // -> if a swap occured, all previous elements before "new_n" might have changed order
    void sort_in_place(std::vector<T>& data) const override {
        auto n = data.size();
        do {
            size_t new_n = 1;
            for (size_t i = 0; i < n - 1; ++i) {
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                    new_n = i + 1;
                }
            }
            n = new_n;
        } while (n > 1);
    }
};
