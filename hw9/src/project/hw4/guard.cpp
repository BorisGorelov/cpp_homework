#include <iostream>

struct StreamGuard {
    std::ostream& os;
    std::ios_base::fmtflags ff;
    char fill;
    std::ios_base::iostate exc;
    
    StreamGuard(std::ostream& x): os(x) { 
        ff = x.flags();
        fill = x.fill();
        exc = x.exceptions();
    }
    ~StreamGuard() { 
        this->os.flags(ff);
        this->os.fill(fill);
        this->os.exceptions(exc);
    }
    StreamGuard(const StreamGuard&) = delete;
    StreamGuard& operator=(const StreamGuard&) = delete;
};