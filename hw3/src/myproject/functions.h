#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <sstream>

//закончились аргументы, s не должна содержать процентов
void message(std::ostream &out, char const* s) {
    while(*s) {
        if(*s == '%')
            throw std::runtime_error("invalid format string: missing arguments");
        out << *s++;
    }
}

template<class T,class... Args>
void message(std::ostream &out, char const* s, T const& value, Args const&... args) {
    while(*s) {
        if(*s == '%') { 
            out << value;
            return message(out, ++s, args...);
            }
        out << *s++;
    }
    throw std::runtime_error("extra arguments provided to message");
}

template<size_t N, class T, class... Args>
auto cat (std::array<T, N> const& head, Args&& ... tail){ 

    std::array<std::array<T, N>, N> input = {head, std::forward<Args>(tail)...};
    std::array<T, N*(sizeof...(tail)+1)> ans;
    int counter = 0;
    for (int i = 0; i < input.size(); ++i)
        for(int j = 0; j < N; ++j) {
            ans[counter] = std::move(input[i][j]);
            counter++;
        }
    return ans;
}


template<class T,int N,int M>
struct Tie {
    std::array<T*, M> data;
    Tie(std::array<T*, M> arr) : data(arr){}
    void operator=(const std::array<T,N*M>& rhs) {
        int count = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) 
                data[i][j] = *(rhs.data() + count + j);
            count += N;
        }
    }
};

template<class T, size_t N, class... Args>
auto array_tie(std::array<T, N> & head, Args&& ... tail) -> Tie<T, N, sizeof...(tail)+1> {
    std::array<T*, sizeof...(tail) + 1> arr {head.data(), std::forward<Args>(tail).data()...};
    return Tie<T, N, sizeof...(tail) + 1>(arr);
}

// namespace detail {
// struct ignore_t {
//     template <typename T>
//     const ignore_t& operator=(const T&) const { return *this; }
// };
// }
// const detail::ignore_t ignore;



