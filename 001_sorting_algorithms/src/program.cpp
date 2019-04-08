#include <vector>
#include <random>
#include <iostream>

#include "bubble_sort_impl.h"
#include "insertion_sort_impl.h"
#include "selection_sort_impl.h"
#include "quick_sort_recursive_impl.h"
#include "quick_sort_iterative_impl.h"

int main() {
    using RandType = unsigned int;
    using SignedIntegerType = int;

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
    //InsertionSortImpl<RandType> s;
    //SelectionSortImpl<RandType> s;
    QuickSortRecursiveImpl<RandType, SignedIntegerType> s;
    //QuickSortIterativeImpl<RandType> s;
    s.sort_in_place(v);

    std::cout << "sorted numbers\n";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << '\n';
    }
}
