#include <iostream>
#include <cassert>
#include <utility>

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
    vector<T>& operator= (const vector<T>& vec);
    vector<T>& operator= (vector<T>&& vec);

    T* begin() { return this->data; }
    size_t size() { return length; }
    T* end() { return this->data + length; }

    void push_back(const T& val);
    void push_back(T&& val);

    T* erase(T*);
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
    data = x.data;
    x.data = nullptr;
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
    if (len > 0) 
        data = new T[len];
    else
        data = nullptr;
}

template<class T> 
vector<T>::vector(size_t len, const T& buf): length(len) {
    data = new T[len];
    for(size_t i = 0; i < len; ++i)
        data[i] = buf;
}

template<class T>
vector<T>& vector<T>::operator= (const vector<T>& vec) {
    if (&vec == this)
        return *this;
    vector<T> buf(vec);
    swap(buf);
    return *this;
}

template<class T>
vector<T>& vector<T>::operator= (vector<T>&& vec) {
    if (&vec == this)
        return *this;
    swap(vec);
    return *this;
}

template<class T>
T* vector<T>::erase(T* pos){
    assert(pos >= begin() && pos < end() && "wrong iterator");
    T* ans = pos + 1;
    if (pos == end()-1){
        pos->~T();
        length--;
        return ans;
    }
    T* i = pos;
    while(i < end()-1){
        *pos = std::move(*(++i));
        ++pos;
    }
    i->~T();
    length--;
    return ans;
}

template<class T> 
void vector<T>::push_back(const T& val){
    T* n_data = new T[length + 1];
    for (size_t i = 0; i < length; ++i) 
        n_data[i] = std::move(data[i]);
    n_data[length] = val;
    delete[] data;
    data = n_data;
    length++;
    //std::cout << "lvalue" << '\n';
}

template<class T> 
void vector<T>::push_back(T&& val){
    T* n_data = new T[length + 1];
    for (size_t i = 0; i < length; ++i) 
        n_data[i] = std::move(data[i]);
    n_data[length] = std::move(val);
    delete[] data;
    data = n_data;
    length++;
    //std::cout << "rvalue" << '\n';
}

template<class T> 
void vector<T>::swap(vector<T>& vec){
    using std::swap;
    swap(length, vec.length);
    swap(data, vec.data);
}

template <class T>
void swap (vector<T>& x, vector<T>& y){ x.swap(y); }
