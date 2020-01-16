#pragma once

template <class T> 
class Matrix{
    public:
        std::vector<T> data;
        Matrix() {data = {};}
        Matrix(const std::vector<T>&);
        ~Matrix() {data.clear();}
        Matrix<char> operator<(const Matrix<T>&) const;
        Matrix<T> transposed() const;
        bool is_symmetric(double) const; 
        Matrix<T> operator-(const Matrix<T>&) const;
        Matrix<char> operator<(double) const;  
        bool operator==(const Matrix<T>&) const;
};
#include "project/hw4/matrix.inl"
