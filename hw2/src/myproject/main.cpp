#include"vector.h"
//#include<vector>
#include<iostream>

int main(){
    using namespace std;

    vector<int> vec(4, 4);
    vector<int> vec1(vec);
    for (const auto &i : vec1)
        cout << i*i << ' ';
    cout << '\n';
    vec1.push_back(4+4);
    vec1.push_back(5/6);
    int a = 5;
    vec1.push_back(a);
    vec.swap(vec1);
    for (const auto &i : vec1)
        cout << i << ' ';
    cout << '\n';
    return 0;
}