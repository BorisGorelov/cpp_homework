#include <iostream>

struct StreamGuard {
    std::ostream& os;

    StreamGuard(std::ostream& x): os(x) { 
        //изменить состояние x
    }
    ~StreamGuard() { 
        //восстановить состояние x
    }
    StreamGuard(const StreamGuard&) = delete;
    StreamGuard& operator=(const StreamGuard&) = delete;
};