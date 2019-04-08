#pragma once

#include "i_sorting_algorithm.h"

template <typename T>
class SelectionSortImpl : public ISortingAlgorithmInPlace<T> {
public:
    void sort_in_place(std::vector<T>& data) const override {
        for (size_t idx_outer = 0; idx_outer < data.size() - 1; ++idx_outer) {
            size_t min_idx = idx_outer;
            for (size_t idx_inner = idx_outer + 1; idx_inner < data.size(); ++idx_inner) {
                if (data[idx_inner] < data[min_idx]) {
                    min_idx = idx_inner;
                }
            }
            std::swap(data[idx_outer], data[min_idx]);
        }
    }
};
