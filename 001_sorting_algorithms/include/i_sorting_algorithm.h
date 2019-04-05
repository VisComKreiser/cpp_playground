#pragma once

#include <vector>

template <typename T>
class ISortingAlgorithmInPlace {
public:
    virtual void sort_in_place(std::vector<T>& data) const = 0;
};

template <typename T>
class ISortingAlgorithmOutOfPlace {
public:
    virtual std::vector<T> sort_out_of_place(const std::vector<T>& data) const = 0;
};
