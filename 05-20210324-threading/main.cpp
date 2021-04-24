// g++ -std=c++11 05-20210324-threading/main.cpp -o thr

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

int main () {

    const int n_threads {10};
    std::vector<std::thread> _threads;

    // One thread
    // std::thread myThread (threadFunc);
    // myThread.join();


    auto threadFunc = [](const int& tid) -> void {
        for (int i=0; i<10; i++) {

            // Mutex pour verrouiller lorsque un thread écrit
            mtx.lock();
            std::cout << "Hello World from thread " << tid << std::endl;
            mtx.unlock();
            // ou bien std::unique_lock<std::mutex> lck (mtx); // avant la ligne à locker, sera détruit automatiquement
        }
    };

    for( int i=0; i<n_threads; i++){
        _threads.push_back(std::thread(threadFunc, i));
    }

    // Join threads
    for(std::thread& thread: _threads){
        thread.join();
    }

    return 0;
}









// Fonction anonyme (lambda function):
// [capture] (params) -> ret { body }
//      paramas est la liste des params d'entrée
//      ret est le type de retour
//      capture est la liste des variables dans le scope de déclaration de la fonction anonyme
// Exemple :
// auto f = [] () {
//     std::cout << "coucou" << std::endl;
// };
