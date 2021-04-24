// g++ -std=c++11 05-20210324-threading/pi.cpp -o pi

#include <iostream>
#include <iomanip>

#include <thread>
#include <mutex>
#include <vector>

// number of points
#define nb_point 1e9

std::mutex mtx;

void thread_worker(std::vector<int> matrix_line, std::vector<int> vector, const int vector_size, std::vector<int>& result){

    int sum = 0;

    for (int i = 0; i < vector_size; i++) {
        sum += matrix_line[i] * vector[i];
    };

    
}



int main(int argc, char* argv []){
    std::vector<int> matrix;
    std::vector<int> vector;
    
    int mat_height = 10; // n
    int mat_width = 10; // m

    int nb_thread = mat_height; // for now

    // Initialise result
    std::vector<int> result (mat_height);

    // Create threads
    std::vector<std::thread> threads;
    for (int i=0; i<nb_thread; i++) {

        // Extract matrix line
        std::vector<int>::const_iterator first = matrix.begin() + i * mat_width;
        std::vector<int>::const_iterator last = matrix.begin() + (i + 1) * mat_width;
        std::vector<int> matrix_line (first, last);

        // Run thread
        threads.push_back( std::thread( thread_worker, matrix_line, vector, mat_width, std::ref(result) ) );
    }

    // Join threads
    for (int i=0; i<nb_thread; i++) {
        threads[i].join();
    }

    // Display result
    std::cout << result << std::endl;

    return 0;
}
