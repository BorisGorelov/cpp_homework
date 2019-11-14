#include <iostream>
#include <string>

template<typename T,typename... Args>
void message(std::ostream &out, const char* s, const T& value, const Args&... args) {
    while(*s) {
        if(*s == '%' && *++s != '%') { // ignore the character that follows the ‘%’: we already know the type!
            out << value;
            return message(out, (++s), args... );
            }
        out << *s++;
    }
    throw std::runtime_error("extra arguments provided to message");
}

void message(std::ostream &out, const char* s) {
    while(*s) {
        if(*s == '%' && *++s != '%')
            throw std::runtime_error("invalid format string: missing arguments");
        out << *s++;
    }
}

int main(){

    message(std::cout, "%+%=%\n", 8, 2, 3.0);

    return 0;
}
