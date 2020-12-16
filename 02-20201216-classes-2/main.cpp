// g++ -std=c++11 class_2.cpp -o c2
// ./c2

#include <iostream>


class Integer {
	private:
		int _value;
		int _min;
		int _max;

	public:
        // Constructeurs
        Integer(): _value(0) {}; // constructeur sans argument: pécifie l'élément NULL de la classe (élément par défaut)
		Integer(const int& x): _value(x) {};
		Integer(const int& x, const int& a, const int& b): _value(x), _min(a), _max(b) {
		};

        void set(const int& x) {
            this->_value = x;
        }

        int get() const {
            return this->_value;
        }


		void print() const { // const dit au compilateur que les attributs de la classe ne sont pas modifiés lors de l'appel
		    std::cout << "Value = " << this->_value << std::endl;
		}

        static void coucou() {
            std::cout << "Une méthode statique" << std::endl;
        }

        bool operator<(const Integer& other) const { // déclaration de la méthode comme const (ne modifiera pas les objets qui sont en input)
            return this->_value < other._value; // other is private but still accessible by another Integer instance
        }
};



int main() {


    // Print a line
    std::cout << "Hello World" << std::endl;

    // Create a class instance of Integer
    Integer a(10, 0, 1000);
    a.print();

    return 0;
}





// g++ main.cpp -o main
// ./main






