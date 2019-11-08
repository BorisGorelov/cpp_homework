#include"vector.h"
//#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<random>

int main(){
    using std::ofstream;
    vector<ofstream> vec;
    for (int i = 0; i < 5; ++i) {
        ofstream outf;
        std::string name = "file" + std::to_string(i) + ".txt";
        outf.open(name.c_str());
        vec.push_back(std::move(outf));
    }
    std::shuffle(vec.begin(), vec.end(), std::random_device());
    for (int i = 0; i < vec.size(); ++i)
        vec[i] << std::to_string(i) << std::endl;
    return 0;
}