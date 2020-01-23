#include "merge_sort.h"
#include <iostream>
#include <random>
#include <thread>

class Timer {
    private:
        using clock_t = std::chrono::high_resolution_clock;
        using second_t = std::chrono::duration<double, std::ratio<1> >;
        std::chrono::time_point<clock_t> m_beg;
    
    public:
        Timer() : m_beg(clock_t::now())
        {
        }
    
        void reset()
        {
            m_beg = clock_t::now();
        }
    
        double elapsed() const
        {
            return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
        }
};


int main() {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 2000000);
    std::vector<double> vec, vec1;
    Timer t;

    for(int size = 32768; size <= 4194304; size *= 2) {
        vec.clear();
        vec1.clear();
        for(int i = 0; i < size; ++i)
            vec.push_back(dist(mt));
        vec1 = vec;

        std::cout << std::endl;
        std::cout << "size: " << size << std::endl;
        t.reset();
        mergeSort(vec, 0, size);
        std::cout << "1 thread time: " << t.elapsed() << std::endl;
        
        t.reset();
        mergeSortMT_std(vec1, 0, size);
        std::cout << "multi thread time: " << t.elapsed() << std::endl;
        std::cout << "Same results: " << (vec == vec1? "yes": "no") << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << vec1[i] << ' ';
    std::cout << std::endl;
    return 0;
}

/*
size: 32768
1 thread time: 0.0452531
multi thread time: 0.0293012
Same results: yes

size: 65536
1 thread time: 0.0871272
multi thread time: 0.0418306
Same results: yes

size: 131072
1 thread time: 0.15332
multi thread time: 0.0739125
Same results: yes

size: 262144
1 thread time: 0.314718
multi thread time: 0.149789
Same results: yes

size: 524288
1 thread time: 0.66367
multi thread time: 0.306419
Same results: yes

size: 1048576
1 thread time: 1.35427
multi thread time: 0.621353
Same results: yes

size: 2097152
1 thread time: 2.81679
multi thread time: 1.2775
Same results: yes

size: 4194304
1 thread time: 5.87097
multi thread time: 2.58563
Same results: yes

1.14239 1.35485 1.98639 2.26012 2.70972 3.0459 3.08306 3.36397 3.74312 4.08867
*/