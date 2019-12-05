#include<gtest/gtest.h> 
//#include<algorithm>
//#include<cmath>
#include<vector>
//#include<iostream>
#include"../myproject/matrix.h"


// TEST(matrix_test, test1){
  
//     typedef float T;
//     std::vector<T> vec1 = {1, 5, 5, 1};
//     std::vector<T> vec2 = {5, 4, 6, 9, 5, 2, 0, 0, 1};
//     Matrix<T> a(vec1), b(vec2);
//     // Matrix<T> c = where(a < b, a, b); //cij=min(aij;bij)
//     // for(auto i : c.data)
//     //     std::cout << i << ' ';

//     EXPECT_TRUE(a.is_symmetric(1e-3));
//     EXPECT_FALSE(b.is_symmetric(1e-3));
// }

struct matrix_isSymmetric_param {
    Matrix<float> input;
    bool expected_output;
};

class matrix_isSymmetric_test : public ::testing::TestWithParam<matrix_isSymmetric_param> {};

TEST_P(matrix_isSymmetric_test, _) {
    const matrix_isSymmetric_param& param = GetParam();
    bool result = param.input.is_symmetric(1e-3);
    EXPECT_EQ(param.expected_output, result);
}

std::vector<float> input1 {1, 2, 3, 5};
std::vector<float> input2 {3, 2, 1, 6};
std::vector<float> input3 {1, 2, 2, 1};
std::vector<float> input4 {1, 0, 0, 0, 1, 0, 0, 0, 1};

INSTANTIATE_TEST_CASE_P(
    _, 
    matrix_isSymmetric_test, 
    ::testing::Values(
        matrix_isSymmetric_param{input1, false}, 
        matrix_isSymmetric_param{input2, false}, 
        matrix_isSymmetric_param{input3, true}, 
        matrix_isSymmetric_param{input4, true}
    )
);