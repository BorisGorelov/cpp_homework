#include<gtest/gtest.h> 
//#include<algorithm>
//#include<cmath>
#include<vector>
//#include<iostream>
#include"project/hw4/matrix.h"


struct matrix_where_param {
    Matrix<float> input1;
    Matrix<float> input2;
    Matrix<float> expected_output;
};

class matrix_where_test : public ::testing::TestWithParam<matrix_where_param> {};

TEST_P(matrix_where_test, _) {
    const matrix_where_param& param = GetParam();
    Matrix<float> m = where(param.input1 < param.input2, param.input1, param.input2);
    EXPECT_EQ(param.expected_output, m);
}

std::vector<float> input1 {1, 2, 3, 5};
std::vector<float> input2 {3, 2, 1, 6};
std::vector<float> expected_output {1, 2, 1, 5};

INSTANTIATE_TEST_CASE_P(
    _, 
    matrix_where_test, 
    ::testing::Values(
        matrix_where_param{input1, input2, expected_output}
        )
);