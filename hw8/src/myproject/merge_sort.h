#pragma once
#include <vector>
#include <tuple>
#include <functional>
#include "../../../hw11/src/myproject/thread.h"

template<class T>
void merge(std::vector<T>& a, int left, int mid, int right){
    int it1 = 0;
    int it2 = 0;
    std::vector<T> result(right-left);

    while ((left+it1 < mid) && (mid + it2) < right)
        if (a[left + it1] < a[mid + it2]) {
            result[it1+it2] = a[left+it1];
            it1++;
        }
        else {
            result[it1+it2] = a[mid+it2];
            it2++;
        }
    while (left +it1 < mid){
        result[it1+it2] = a[left+it1];
        it1++;
    }
    while (mid + it2 < right){
        result[it1+it2] = a[mid+it2];
        it2++;
    }
    for (int i = 0; i < it1+it2; ++i)
        a[left + i] = result[i];
} 

template <class T>
void mergeSort(std::vector<T>& a, int left, int right){
    if (left + 1 >= right)
        return;
    int mid = (left + right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
}

//template <class T>
int mergeSortMT(void* arg){
    std::tuple<std::reference_wrapper<std::vector<int>>, int, int> tup = \
    *static_cast<std::tuple<std::reference_wrapper<std::vector<int>>, int, int>*>(arg);

    std::vector<int>& a = std::get<0>(tup);
    int left = std::get<1>(tup);
    int right = std::get<2>(tup);
    //std::tie(a, left, right) = tup;

    if (left + 1 >= right)
        return -1;

    int mid = (left + right)/2;

    std::tuple<std::vector<int>, int, int> tup1;
    std::tuple<std::vector<int>, int, int> tup2;
    tup1 = std::make_tuple (a, left, mid);
    tup2 = std::make_tuple (a, mid, right); 

    void* arg1 = &tup1;
    void* arg2 = &tup2;
    Thread t(mergeSortMT, arg1);
    mergeSortMT(arg2);
    t.join();
    merge(a, left, mid, right);
    return 0;
}