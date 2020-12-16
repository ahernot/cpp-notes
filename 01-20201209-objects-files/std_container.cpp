/* STL (Standard Templates Library)
template: code qui marche regardless of the types

To run:
    g++ -std=c++11 std_container.cpp -o stdc
    ./stdc
*/


#include <iostream>

#include <array>
#include <vector>
#include <set>
#include <map>

#include <algorithm>



void printBreak() {
    std::cout << std::endl;
    // std::cout << "----------" << std::endl;
}


int main() {

    // Array (equivalent to Python tuple — fixed list with no appending/popping possible)
    std::array<int, 10> array1 = {1, 2, 3, 4, 5}; // array of size 10, filled with the given sequence and 0 (NULL) to complete
    
    // printBreak();
    // for (int i=0; i<array1.size(); i++) { std::cout << "array1[" << i << "] = " << array1[i] << std::endl; };




    // Vector (equivalent to Python list)
    std::vector<int> vector1 = {1, 2, 3, 4, 5}; // vector of size 5 (automatically determined), filled with the given sequence
    std::vector<int> vector2( 10 ); // vector of size 10, filled with 0 (NULL)
    std::vector<int> vector3( 10, 1 ); // vector of size 10, filled with 1

    // printBreak();
    // for (int i=0; i<vector1.size(); i++) { std::cout << "vector1[" << i << "] = " << vector1[i] << std::endl; };

    vector1.push_back( 1 ); // append an element to the end of the vector
    vector1.pop_back(); // remove the last element of the vector
    vector1.resize( 2 ); // resize the vector (will truncate if needed, will fill with 0 (NULL) if needed)

    // Iterator
    printBreak();
    std::vector<int>::iterator it;
    for (it=vector1.begin(); it!=vector1.end(); it++) { std::cout << *it << std::endl; }

    // Syntaxes de parcours
    // printBreak();
    // for (auto x: vector1) { std::cout << x << std::endl; }
    // printBreak();
    // for (int& x: vector1) { std::cout << x << std::endl; }
    




    // Set (équivalent du set Python)
    std::vector<int> vec = {2, 4, 1, 2, 3, 10, 8, 7, 8, 1};
    std::set<int> vec2set;
    for (auto x: vec) { vec2set.insert( x ); }

    printBreak();
    std::cout << vec2set.size() << " valeur(s) unique(s)" << std::endl;
    for (auto x: vec2set) { std::cout << x << std::endl; }







    // Map (equivalent to Python dictionary)
    std::map<int, double> map1; // <key type, value type>
    map1[10] = 10.0; map1[2] = 3.0;

    // Access a value of the map using a key
    printBreak();
    std::cout << map1[10] << std::endl;
    
    // Iterate through the map to read the keys and values
    printBreak();
    std::map<int, double>::iterator itm;
    std::vector<int> keys;
    for (itm=map1.begin(); itm!=map1.end(); itm++) {
        std::cout << itm->first <<  ": " << itm->second << std::endl;
        keys.push_back(itm->first);
    }

    // Finding a key in the map
    printBreak();
    if (map1.find(10) != map1.end()) { // iterator which stops once the key is found or at the end of the map
        std::cout << "10 is a key" << std::endl;
    }
    else { std::cout << "10 isn't a key" << std::endl; }


    



    // Stack (pile)



    // Queue






}