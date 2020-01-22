#include "merge_sort.h"
#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    std::vector<int> vec;
    for(int i = 0; i < 4; ++i){
        vec.push_back(dist(mt));
        std::cout << vec.back() << ' '; 
    }

    std::tuple<std::vector<int>, int, int> tup1;
    tup1 = std::make_tuple (vec, 0, 4);
    void* arg1 = &tup1;
    mergeSortMT(arg1);

    std::cout << std::endl;
    for (auto i : vec)
        std::cout << i << ' ';
    return 0;
}