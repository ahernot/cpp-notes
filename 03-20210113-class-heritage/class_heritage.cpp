/*
g++ -std=c++11 class_heritage.cpp -o ch
./ch
*/

#include <iostream>
#include <string>
#include <vector>

#include <cmath>




#include <iomanip>
#include <ios>
std::streamsize prec=std::cout.precision();




class Shape {
    protected:
        std::string _type;

    public:
        Shape (): _type("null") {};

        std::string type () {
            return this->_type;
        };

        // Fonction virtual: can potentially be overwritten in a child class
        virtual void info () {
            std::cout << "Shape of type " << this->_type << std::endl;
        };

        // Méthode virtuelle pure (pas définie dans la classe mère)
        // La classe mère devient alors une classe abstraite, et ne peut pas être utilisée pour définir un objet
        virtual double area () = 0;

};



class Circle: public Shape { // Si on met protected: ce qui était public en classe mère passe en protected, et ce qui était protected passe en private
    protected:
        double _radius;
    
    public:
        Circle (): Shape() {
            this->_type = "circle";
            this->_radius = 1;
        };

        Circle (const double& radius): Shape() {
            this->_type = "circle";
            this->_radius = radius;
        };

        void info () {
            Shape::info(); // call Shape.info()
            std::cout << "Rayon = " << this->_radius << std::endl;
        };

        double area () {
            double _area = M_PI * pow((this->_radius), 2);
            std::cout << std::setprecision(16) << "Area = " << _area << std::setprecision(prec) << std::endl;
            return _area;
        };
};



class Rectangle: public Shape { // Si on met protected: ce qui était public en classe mère passe en protected, et ce qui était protected passe en private
    protected:
        double _width;
        double _length;
    
    public:
        Rectangle (): Shape() {
            this->_type = "rectangle";
            this->_width = 1.0;
            this->_length = 1.0;
        };

        Rectangle (const double& width, const double& length): Shape() {
            this->_type = "rectangle";
            this->_width = width;
            this->_length = length;
        };


        void info () {
            Shape::info();
            std::cout << "Dimensions = " << this->_width << " x " << this->_length << std::endl;
        };

        double area () {
            double _area = this->_width * this->_length;
            std::cout << std::setprecision(16) << "Area = " << _area << std::setprecision(prec) << std::endl;
            return _area;
        };

        // Méthode spécifique à rectangle
        void coucou () {
            std::cout << "Coucou depuis Rectangle::coucou" << std::endl;
        };
};



int main () {
    
    // Define a circle of radius 1 (DEFAULT)
    Circle a;
    a.info();

    // Define a rectangle of set size
    Rectangle r(5, 10);
    r.info();
    r.area();

    // Define a circle of radius 10
    Circle c(10.0);
    c.info();
    c.area();


    std::cout << "************************" << std::endl;


    Shape* pa; // pointeur de type Shape
    pa = &a; // spécifie que pa pointe vers l'adresse de a
    pa->info();

    pa = &c; // On peut quand même utiliser un pointeur de type Shape pour définir un Circle (child class of Shape)
    pa->info(); // polymorphisme dynamique (va chercher les bonnes méthodes aussi)

    pa = &r;
    pa->info();



    //-------------------


    std::vector<Shape*> shapes (3, nullptr);
    shapes[0] = new Circle(5.0);
    shapes[1] = new Circle(2.0);
    shapes[2] = new Rectangle(5.0, 3.0);


    //-------------------


    /*
    DOESN'T WORK
    for (std::vector<Shape*>::iterator shapeIterator = shapes.begin(); shapeIterator < shapes.end(); shapeIterator ++) {
        *shapeIterator->info();
    };
    */

    for (auto shapeIterator: shapes) {
        shapeIterator->info(); // ou (*shapeIterator).info()
    }

    if (shapes[2]->type() == "rectangle") {
        // Casting to run a child-specific function
        ((Rectangle*)shapes[2])->coucou(); // on cast shapes[2] en Rectangle* pour que C++ accepte de faire tourner coucou()
        static_cast<Rectangle*>(shapes[2])->coucou();
        dynamic_cast<Rectangle*>(shapes[2])->coucou(); // vérifie que le cast est possible (mais générera toujours une erreur si impossible)
    };

    

    //-------------------


    // std::shared_ptr se détruit tout seul (delete) lorsqu'il n'est plus utilisé
    std::vector<std::shared_ptr<Shape>> shapes2 (3, nullptr);
    shapes2[0] = std::shared_ptr<Shape>(new Circle(5.0));
    shapes2[1] = std::shared_ptr<Shape>(new Circle(2.0));
    shapes2[2] = std::shared_ptr<Shape>(new Rectangle(5.0, 3.0));

    for(int i = 0; i < shapes2.size(); i++) {
        shapes2[i]->info();
    }


    return 0;
};