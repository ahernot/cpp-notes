// g++ -std=c++11 -fopenmp 05-20210324-threading/omp.cpp -o omp

#include <iostream>
#include <omp.h>

int main(){
    #pragma omp parallel for
    for (int i=0; i<20; i++) {
        std::cout << "Element " << i << " dans le thread " << omp_get_thread_num() << std::endl;
    }

}
