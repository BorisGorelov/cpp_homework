#include<gtest/gtest.h> 
#include"../myproject/guard.cpp"

void print_hex (int i) {
    StreamGuard g(std::cout);
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
    //или std::cout << std::hex
    std::cout << i << std::endl;
}

TEST(guard_test, test1){
    std::cout << 15 << std::endl;
    print_hex(15);
    std::cout << 15 << std::endl;
}

