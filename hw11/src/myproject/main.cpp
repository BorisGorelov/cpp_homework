#include <thread.h>
#include <iostream>

int foo(void*){
    std::cout << "hi from another thread\n";
    return 0;
}

int main(){
    std::cout << "hi\n";
    Thread t(foo, NULL);
    t.join();
    std::cout << "hi\n";
    return 0;
}