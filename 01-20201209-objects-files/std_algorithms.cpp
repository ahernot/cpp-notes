/* STL (Standard Templates Library)

To run:
    g++ -std=c++11 std_algorithms.cpp -o stda
    ./stda
*/


#include <iostream>

#include <vector>
#include <algorithm>






class Integer {

private:
    int _value;
    int _min;
    int _max;

public: 
    Integer(): _value(0){}
    Integer(const int& x): _value(x){}
    Integer(const int& x, const int& a, const int& b): _value(x), _min(a), _max(b){
    }

    void set(const int& x) {
        this->_value = x;
    }

    int get() const {
        return this->_value;
    }

    void print() const {
        std::cout << "Value = " << this->_value << std::endl;
    }

    static void coucou(){
        std::cout << "Une methode statique " << std::endl;
    }

    bool operator<(const Integer& other) const {
        return this->_value < other._value ;
    }

};





void printBreak() {
    std::cout << std::endl;
    // std::cout << "----------" << std::endl;
}


int main() {


    std::vector<int> vec = {2, 4, 1, 2, 3, 10, 8, 7, 8, 1};


    // Find
    auto x = std::find( vec.begin(), vec.end(), 3 ); // find position of value 3 in vec with iterator from address vec.begin() to address vec.end()

    if (x != vec.end()) {
        std::cout << "Value 3 found in vec" << std::endl;
    }
    else { std::cout << "Value 3 not found in vec" << std::endl; }



    // Sort
    std::sort( vec.begin(), vec.end() ); // sort vec using iterator from address vec.begin() to address vec.end()
    printBreak();
    for (auto x: vec) { std::cout << x << std::endl; }


    printBreak();
    std::sort(
        vec.begin(),
        vec.end(),
        [](const int& a, const int& b) { return a>b; } // lambda-function (fonction anonyme)
    );
    for (auto x: vec) { std::cout << x << std::endl; }



    // THIS DOESN'T WORK FOR SOME REASON
    /* std::vector<Integer> intVec(10);
    for (int i=0; i<10; i++) { intVec[i].set( Integer(i) ); } // !!! doesn't seem to work
    printBreak();
    for (auto x: intVec) { x.print(); }
    std::sort(
        intVec.begin(),
        intVec.end(),
        [](const Integer& a, const Integer& b ) { return a.get() < b.get(); } // define a sorting relation to avoid having to define the operator in the Integer class
    );
    printBreak();
    for (auto x: intVec) { x.print(); } */




    int sum = 0;
    std::for_each(
        vec.begin(),
        vec.end(),
        [&sum](int& x) { sum += x; } // passage de sum par référence dans la fonction anonyme (global variable)
    );
    std::cout << sum << std::endl;




    return 0;
}