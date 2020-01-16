#include<gtest/gtest.h> 
#include"project/hw10/function.cpp"


TEST(turn_left_test, test1){
    std::pair<float, float> one (3, 1.);
    std::pair<float, float> two (-1., 3.);
    std::pair<float, float> three (1., 0.);
    std::pair<float, float> four (0., 1.);
    std::pair<float, float> five (-2., 1.);
    std::pair<float, float> six (2., -1.);
    std::pair<float, float> seven (0., 0.);
    EXPECT_EQ(turn(one, 90), two);
    EXPECT_ANY_THROW(turn(three, 91));
    EXPECT_EQ(turn(five, 180), six);
    EXPECT_EQ(turn(seven, 270), seven);
}
