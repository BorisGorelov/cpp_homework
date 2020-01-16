#pragma once
#include "project/hw4/matrix.h"
#include <vector>
#include <cmath>
#include <stdexcept>

template <class T> 
Matrix<T>::Matrix(const std::vector<T>& vec){

    double size = sqrt(vec.size());
    if((floor(size) != ceil(size)) || !size)
        throw std::runtime_error("size is not square or empty");

    for (const auto& i : vec)
        data.push_back(i);
}

template <class T>
Matrix<char> Matrix<T>::operator< (const Matrix& m) const {

    if(m.data.size() != this->data.size())
        throw std::runtime_error("sizes do not match");

    Matrix<char> ans;
    for(size_t i = 0; i < m.data.size(); ++i)
        ans.data.push_back(this->data[i] < m.data[i]);
    return ans;
}

template <class T>
Matrix<T> where(const Matrix<char>& flag, const Matrix<T>& a, const Matrix<T>& b) {
    Matrix<T> ans;
    for(size_t i = 0; i < a.data.size(); ++i)
        ans.data.push_back(flag.data[i]? a.data[i] : b.data[i]);
    return ans;
}

template <class T>
Matrix<T> matrixAbs(const Matrix<T>& m){
    Matrix<T> ans;
    for(const auto& i : m.data)
        ans.data.push_back(abs(i));
    return ans;
}

//all elements are positive
template <class T>
bool all(const Matrix<T>& m){
    bool flag = true;
    for(const auto& i : m.data)
        if (!i) {
            flag = false;
            break;
        }
    return flag;
}

template <class T>
Matrix<T> Matrix<T>::transposed() const{
    size_t size = static_cast<size_t>(sqrt(data.size()));
    Matrix<T> ans;
    ans.data.resize(data.size());

    for (size_t i = 1; i <= size; ++i)
        for (size_t j = 1; j <= size; ++j)
            ans.data[j*size + i - 1 - size] = data[i*size + j - 1 - size];
    return ans;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>&m) const{
    if(m.data.size() != this->data.size())
        throw std::runtime_error("sizes do not match");

    Matrix<T> ans;
    for (size_t i = 0; i < this->data.size(); ++i)
        ans.data.push_back(this->data[i] - m.data[i]);
    return ans;
}

template <class T>
Matrix<char> Matrix<T>::operator<(double d) const{
    Matrix<char> ans;
    for(const auto& i : this->data)
        ans.data.push_back(i < d);
    return ans;
}

template <class T>
bool Matrix<T>::is_symmetric(double eps) const{
    return all(matrixAbs(*this - this->transposed()) < eps);
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& m) const {
    return (this->data == m.data);
}
