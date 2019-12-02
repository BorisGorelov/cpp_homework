#include<gtest/gtest.h> 
//#include<algorithm>
//#include<cmath>
//#include<vector>
//#include<iostream>
#include"../myproject/matrix.h"
//#include"../myproject/matrix.inl"
//home/boris/dev/cpp_homework/hw4/src/myproject/matrix.cpp


TEST(matrix_test, test1){
  
    typedef float T;
    std::vector<T> vec1 = {1, 5, 5, 1};
    std::vector<T> vec2 = {5, 4, 6, 9, 5, 2, 0, 0, 1};
    Matrix<T> a(vec1), b(vec2);
    // Matrix<T> c = where(a < b, a, b); //cij=min(aij;bij)
    // for(auto i : c.data)
    //     std::cout << i << ' ';

    EXPECT_TRUE(a.is_symmetric(1e-3));
    EXPECT_FALSE(b.is_symmetric(1e-3));
}