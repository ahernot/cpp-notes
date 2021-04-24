// g++ -std=c++11 05-20210324-threading/pi.cpp -o pi

#include <iostream>
#include <iomanip>

#include <thread>
#include <mutex>
#include <vector>

// number of points
#define nb_point 1e9

std::mutex mtx;

void pi_thread_worker(const uint& nbpoint, const uint tid, const uint nbthread, double& pi){
    double s = 0.;
    double l = 1. / nbpoint;
    int start = tid * (nbpoint / nbthread);
    int stop = (tid + 1) * (nbpoint / nbthread);

    if( tid == nbthread - 1) {
        stop += nbpoint % nbthread;
    }

    double x;

    double myPiContrib = 0;

    for (int i=start; i<stop; i++) {
        x = l * ( i + 0.5 );
        myPiContrib += l * ( 4. / (1 + x*x ) );
    }

    mtx.lock();
    pi += myPiContrib;
    mtx.unlock();
}



int main(int argc, char* argv []){

    // Exception when no threading specified
    if( argc == 1 ){
        std::cerr << "Specify the number of thread" << std::endl;
        return 1;
    }
    
    // Read number of threads
    int nb_thread = atoi(argv[1]);

    // Initialise value of pi
    double pi = 0.;

    // Create threads
    std::vector<std::thread> threads;
    for (int i=0; i<nb_thread; i++) {
        threads.push_back( std::thread( pi_thread_worker, nb_point, i, nb_thread, std::ref(pi) ) );
        // std::ref(pi) pour passer par référence
    }

    // Join threads
    for (int i=0; i<nb_thread; i++) {
        threads[i].join();
    }

    // Display result
    std::cout << std::setprecision(20) << pi << std::setprecision(5) << std::endl;

    return 0;
}

//  std::setprecision(5)






// Fonction anonyme (lambda function):
// [capture] (params) -> ret { body }
//      paramas est la liste des params d'entrée
//      ret est le type de retour
//      capture est la liste des variables dans le scope de déclaration de la fonction anonyme
// Exemple :
// auto f = [] () {
//     std::cout << "coucou" << std::endl;
// };
