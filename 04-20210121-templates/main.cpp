// g++ -std=c++11 04-20210121-templates/main.cpp -o t

#include <vector>
#include <iostream>

/*
template<typename T>
T add (const T& a, const T& b) {
    return a + b;
};
*/

template<typename T, int N>
void printVector(std::vector<T>& vector) {

    for (int i = 0; i < N; i++) {
        std::cout << vector[i];
        if (i < N - 1) { std::cout << ", "; };
    };

    std::cout << std::endl;
};





int main () {

    std::vector<double> v1 = {1, 2, 3, 4, 5};
    /*
    v1.push_back(1);
    v1.push_back(2):
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    */
    std::vector<int> v2 = {1, 2, 3, 4, 5};

    printVector<double, 3>(v1);
    printVector<int, 3>(v2);

    return 0;
};
