
#include <iostream>



class IntStack {
    public:

        // Class constructor
        IntStack (int s): size (s), top (0), tab (new int [size]) {};

        // Class copy constructor
        IntStack (const IntStack& other) {
            this->size = other.size;
            this->top = other.top;
            this->tab = new int[size];
            for (int i=0; i<other.top; i++) { this->tab[i] = other.tab[i]; };
        };

        //--Class destructor--
        ~IntStack () { this->delete_stack(); };
        // ~IntStack () = delete; // Prevent the compiler from creating a destructor (else it will automatically try to destroy the object)
        // ~IntStack () = default; // Ask the compiler to create the destructor here (else will be public)



        void push (int e) {
            tab[top] = e;
            top = top+1;
        }

        int pop () {
            top = top-1;
            return tab[top];
        }

        void print () {
            std :: cout << "[";
            for (int i=0; i<top; i++) { std::cout << tab[i] << ' '; };
            std::cout << '[' << std::endl;
        }

        void delete_stack () { delete [] tab; }


    private:
        int size;
        int top;
        int* tab;
};




int main() {

    IntStack stack (12); // create a stack of size 12
    stack.push(1); stack.push(2); stack.push(3);

    IntStack st_copy = stack; // will use the copy constructor

    return 0;
}


// En sortant d'une fonction, les variables locales (sans new) sont détruites.
// (int& a) passage par référence (gives address)
// (int a) passage par copie (appelle le constructeur de copie)