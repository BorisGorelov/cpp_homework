#include<gtest/gtest.h> 
#include<algorithm>
#include<cmath>
#include"../myproject/functions.cpp"


TEST(message_test, test1){
    std::stringstream ss;
    const char* msg = "Test string: %, %, %\n";
    std::string s = "Test string: abc, 1.123, def\n";
    message(ss, msg, std::string("abc"), 1.123, "def");
    ASSERT_EQ(s, ss.str());

    ss.str(std::string());
    const char* msg1 = "Test error string: %, %, %%\n";
    ASSERT_THROW(message(ss, msg1, std::string("abc"), 1.123, "def"), std::runtime_error);

    ss.str(std::string());
    const char* msg2 = "Test error string: %, %\n";
    ASSERT_THROW(message(ss, msg1, std::string("abc"), 1.123, "def"), std::runtime_error);
}

TEST(cat_test, test1) {
    std::array<float,3> vec1{1.0f,2.0f,3.0f};
    std::array<float,3> vec2{4.0f,5.0f,6.0f};
    std::array<float,6> r = cat(vec1, vec2);
    std::array<float,6> check{1.0f,2.0f,3.0f, 4.0f,5.0f, 6.0f};
    ASSERT_EQ(r, check);
}