#include<iostream>

/*
INHERITANCE

class Number{
    private: // accessible by the class only
        std::string _name;

    protected: // same as private but accessible by children classes too


    public: // accessible by the outside


};


class Integer: public Number{

};
*/



class Integer{
    protected:


    public:
        Integer(): _value(0){};
        Integer(const int& x): _value(x){};

        void print(){ std::cout << "Integer with value " << this->_value << std::endl; }

};

int main() {
    Integer i(10);
    i.print();

    Integer* pi = new Integer(12);
    pi->print();
    delete pi;

    return 0
};