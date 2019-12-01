#include<gtest/gtest.h> 
#include"../myproject/function.cpp"


TEST(turn_left_test, test1){
    std::pair<float, float> one (3, 1.);
    std::pair<float, float> two (-1., 3.);
    std::pair<float, float> three (1., 0.);
    std::pair<float, float> four (0., 1.);
    std::pair<float, float> five (-2., 1.);
    std::pair<float, float> six (-1., -2.);
    std::pair<float, float> seven (0., 0.);
    EXPECT_EQ(turn_left(one), two);
    EXPECT_EQ(turn_left(three), four);
    EXPECT_EQ(turn_left(five), six);
    EXPECT_EQ(turn_left(seven), seven);
}
