/*
g++ -std=c++11 arithmetics.cpp -o a
./a
*/

#include <iostream>
#include <string>
#include <vector>

#include <cmath>




#include <iomanip>
#include <ios>
std::streamsize prec=std::cout.precision();




// Define global variables
const std::string ADD = "__ADD__";
const std::string SUBTRACT = "__SUBTRACT__";
const std::string MULTIPLY = "__MULTIPLY__";
const std::string DIVIDE = "__DIVIDE__";

/**
 * Need an object with a value, a repr(), and a way to calculate using other similar objects
 * and there can be nesting to chain-calculate
 */


class cCalculation {

    protected:
        std::vector<cOperation> operationsVector;


    public:

        /**
         * Add an operation to the chain
         */
        void add(const cOperation& operation) {
            this->operationsVector.push_back(operation);
        };

        void print()

};


class cOperation {

    protected:
        int _value;
        cOperation _valueLeft;
        cOperation _valueRight;

        std::string _operatorType;
        std::string _symbol;
    

    public:

        cOperation () {};
        cOperation (std::string operatorType, const int& valueLeft, const int& valueRight): _valueLeft(valueLeft), _valueRight(valueRight), _operatorType(operatorType) {}; // Main constructor
        cOperation (const int& valueLeft, std::string operatorType, const int& valueRight): _valueLeft(valueLeft), _valueRight(valueRight), _operatorType(operatorType) {};
        cOperation (const int& valueLeft, const int& valueRight, std::string operatorType): _valueLeft(valueLeft), _valueRight(valueRight), _operatorType(operatorType) {};

        /**
         * Evaluate expression
         */
        int eval () {

            int result;
            
            if (this->_operatorType == ADD) {
                result = _valueLeft + _valueRight;
            }
            else if (this->_operatorType == SUBTRACT) {
                result = _valueLeft - _valueRight;
            }
            else if (this->_operatorType == MULTIPLY) {
                result = _valueLeft * _valueRight;
            }
            else if (this->_operatorType == DIVIDE) {
                result = _valueLeft / _valueRight;
            };

            this->_value = result;

            return result;

        };
        

        void print() {
            std::cout << "(" << this->_valueLeft << this->_symbol << this->_valueRight << ")" << std::endl;
        };

};


// type is int for now, will be <T> later
class cConstant: public cOperation {
    protected:    
    public:
        cConstant (): cOperation() {
            this->_value = 0;
        };
        cConstant (const int& value): cOperation() {
            this->_value = value;
        };

    void print () { std::cout << this->_value << std::endl; };

};

class cAdd: public cOperation {
    protected:
    public:
        cAdd (const cOperation& valueLeft, const cOperation& valueRight): cOperation(ADD, valueLeft, valueRight) {
            this->_symbol = "+";
        };
};

class cSubtract: public cOperation {
    protected:
    public:
        cSubtract (const cOperation& valueLeft, const cOperation& valueRight): cOperation(SUBTRACT, valueLeft, valueRight) {
            this->_symbol = "-";
        };
};

class cMultiply: public cOperation {
    protected:
    public:
        cMultiply (const cOperation& valueLeft, const cOperation& valueRight): cOperation(MULTIPLY, valueLeft, valueRight) {
            this->_symbol = "✖️";
        };
};

class cDivide: public cOperation {
    protected:
    public:
        cDivide (const cOperation& valueLeft, const cOperation& valueRight): cOperation(DIVIDE, valueLeft, valueRight) {
            this->_symbol = "÷";
        };
};






class Expression {
    protected:

    public:

};



int main () {

    cConstant c1 {12};
    c1.print();



    return 0;
};




/*
int main () {
my_constant c1 {12};
c1 . print ( std :: cout ); // 12
c1 . eval ();
my_constant c2 {13};
c2 . print ( std :: cout ); // 13
c2 . eval ();
my_plus p1 { c1 , c2 };
p1 . print ( std :: cout );
// (12+13)
p1 . eval ();
my_mult m1 { c1 , c2 };
m1 . print ( std :: cout );
Valérie Roy & Basile Marchand
// (12*13)
m1 . eval ();
my_constant c3 {156};
c3 . print ( std :: cout ); // 156
c3 . eval ();
my_unary_minus u1 { c3 };
u1 . print ( std :: cout ); // -156
u1 . eval ();
my_plus p2 { m1 , u1 };
p2 . print ( std :: cout ); // ((12*13)+ -156)
p2 . eval ();
my_divide d1 { c1 , p2 };
d1 . print ( std :: cout ); // (12/((12*13)+ -156))
d1 . eval ();
// terminate called after throwing an instance o
// what (): zero divide
// 12 13(12+13)(12...12/((12*13)+ - 156)) Aborted ( c
return 0;
};
*/