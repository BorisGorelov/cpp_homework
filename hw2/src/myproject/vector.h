#include <iostream>
#include <cassert>

template <class T> class vector
{
    private:
    size_t length;
    T* data; 

    public:
    vector(): length(0), data(nullptr) {}
    vector(size_t len);
    vector(size_t len, const T& buf);
    ~vector() { delete[] data; }

    vector(const vector& vec);
    vector(vector&& x);
    T& operator= (const T& vec);
    T& operator= (T&& vec);

    T* begin() { return this->data; }
    size_t size() { return length; }
    T* end() { return this->data + length; }

    void push_back(const T& val);
    //void push_back(T&& val);

    void erase(size_t pos);
    void pop_back(){
        erase(length-1);
        return;
    }

    T& operator[] (const size_t index){ return data[index]; }
    const T& operator[] (const size_t index) const { return data[index]; }

    void swap (vector& vec);

};

template<class T> 
vector<T>::vector(vector&& x): length(x.length){
    data = x->data;
    x->data = nullptr;
    x.length = 0;
}

template<class T> 
vector<T>::vector(const vector& vec): length(vec.length){
    data = new T[vec.length];
    for(size_t i = 0; i < vec.length; ++i)
        data[i] = vec[i];
}

template<class T> 
vector<T>::vector(size_t len): length(len) {
    assert(len >= 0 && "the length of the vector must be nonnegative");
    if (len > 0) 
        data = new T[len];
    else
        data = nullptr;
}

template<class T> 
vector<T>::vector(size_t len, const T& buf): length(len) {
    assert(len > 0 && "the length of the vector must be posetive");
    data = new T[len];
    for(size_t i = 0; i < len; ++i)
        data[i] = buf;
}

template<class T>
T& vector<T>::operator= (const T& vec) {
    if (&vec == this)
        return *this;
    length = vec.lenght;
    delete[] data;
    data = new T[vec.length];
    for(size_t i = 0; i < vec.length; ++i)
        data[i] = vec[i];
    return *this;
}

template<class T>
T& vector<T>::operator= (T&& vec) {
    if (&vec == this)
        return *this;
    length = vec.lenght;
    vec.length = 0;
    delete[] data;
    data = vec.data;
    vec.data = nullptr;
    return *this;
}

template<class T> 
void vector<T>::erase(size_t pos){
    assert(pos >= 0 && pos < length && "wrong index");
    if (!pos) {
        T* n_data = new T[length-1];
        for(size_t i = 0; i < length - 1; ++i)
            n_data[i] = data[i+1];
        delete[] data;
        data = n_data;
        length--;
        return;
    }
    else if (pos == length - 1){
        T* n_data = new T[length-1];
        for(size_t i = 0; i < length - 1; ++i)
            n_data[i] = data[i];
        delete[] data;
        data = n_data;
        length--;
        return;
    }
    else {
        T* n_data = new T[length-1];
        for(size_t i = 0; i < pos; ++i)
            n_data[i] = data[i];
        for(size_t i = pos + 1; i < length; ++i)
            n_data[i-1] = data[i];
        delete[] data;
        data = n_data;
        length--;
        return;
    }
}

template<class T> 
void vector<T>::push_back(const T& val){
    T* n_data = new T[length + 1];
    for (size_t i = 0; i < length; ++i) 
        n_data[i] = data[i];
    n_data[length] = val;
    delete[] data;
    data = n_data;
    length++;
    std::cout << "lvalue" << '\n';
}

// template<class T> 
// void vector<T>::push_back(T&& val){
//     T* n_data = new T[length + 1];
//     for (size_t i = 0; i < length; ++i) 
//         n_data[i] = data[i];
//     n_data[length] = val;
//     delete[] data;
//     data = n_data;
//     length++;
//     std::cout << "rvalue" << '\n';
// }

template<class T> 
void vector<T>::swap(vector& vec){
    vector<T> buf = *this;
    *this = vec;
    vec = buf;
}

