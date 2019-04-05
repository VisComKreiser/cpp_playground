#pragma once

#include "i_sorting_algorithm.h"

template <typename T>
class InsertionSortImpl : public ISortingAlgorithmInPlace<T> {
public:
    void sort_in_place(std::vector<T>& data) const override {
        for (size_t i = 1; i < data.size(); ++i) {
            // temporarily store value which will be sorted in
            const auto value = data[i];

            // initialize loop variable at current index
            auto j = i;

            // search from current index to the front,
            // as long as there are larger values, shift them one to the back
            while (j > 0 && data[j - 1] > value) {
                data[j] = data[j - 1];
                --j;
            }

            // when location is found, insert value of interest at its index
            data[j] = value;
        }
    }
};
