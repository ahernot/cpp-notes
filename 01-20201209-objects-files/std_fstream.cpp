/* STL (Standard Templates Library)
To run:
    g++ -std=c++11 std_fstream.cpp -o stdf
    ./stdf
*/

#include <iostream>
#include <fstream>



int main() {

    // Create output file stream
    std::ofstream file_out;
    // Write to file in ASCII mode
    file_out.open("output.txt");
    file_out << "Hello World" << std::endl;
    file_out.close();

    // DOESN'T WORK
    /*
    // Create binary output file stream
    std::ofstream file_bin_out;
    // Write to file in BINARY mode
    file_bin_out.open("output.bin", std::ios::binary);
    file_bin_out.write((char*)"Hello World");
    file_bin_out.close();
    */


    // Create input file stream
    std::ifstream file_in;

    // Read word by word (space as separator) - uses pointer
    file_in.open("output.txt");
    std::string word;
    file_in >> word; std::cout << word << std::endl; // word 1
    file_in >> word; std::cout << word << std::endl; // word 2
    std::cout << file_in.eof() << std::endl; // end of file (bool)
    file_in.close();

    // Read line by line (line break as separator) - uses pointer
    file_in.open("output.txt");
    std::string line;
    std::getline(file_in, line); std::cout << line << std::endl; // line 1
    std::getline(file_in, line); std::cout << line << std::endl; // line 2
    std::cout << file_in.eof() << std::endl; // end of file (bool)
    file_in.close();

    /*
    // Read line by line (line break as separator) - uses pointer
    file_in.open("output.bin");
    std::string line;
    std::getline(file_in, line); std::cout << line << std::endl; // line 1
    std::getline(file_in, line); std::cout << line << std::endl; // line 2
    std::cout << file_in.eof() << std::endl; // end of file (bool)
    file_in.close();
    */



    return 0;
}