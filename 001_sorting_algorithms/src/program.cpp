#include <vector>
#include <random>
#include <iostream>

#include "bubble_sort_impl.h"
#include "insertion_sort_impl.h"

int main() {
    using RandType = unsigned int;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<RandType> distribution(0, 99);

    std::cout << "initial numbers\n";
    const size_t N{ 10 };
    std::vector<RandType> v(N);
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = distribution(generator);
        std::cout << v[i] << '\n';
    }

    //BubbleSortImpl<RandType> s;
    InsertionSortImpl<RandType> s;
    s.sort_in_place(v);

    std::cout << "sorted numbers (BubbleSort in place)\n";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << '\n';
    }
}
