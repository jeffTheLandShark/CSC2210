//
// Created by goetschm on 10/21/2024.
//

#include "bonus.h"

/* Starting code for bonus activity
 * the goal is to implement virtual destructors and override them
 * and to make the get_type() and print_area() functions pure virtual
 */

#include <iostream>
using namespace std;

class Polygon {
protected:
    /*declared protected because making them private will
    not allow child classes to access them
    */
    int width, height;
public:
    Polygon() {
        width = height = 0;
        cout << "I'm a Polygon" << endl;
    }
    Polygon(int width, int height) {
        this->width = width;
        this->height = height;
        cout << "I'm an initialized Polygon" << endl;
    }
    Polygon(int side) {
        this->width = side;
        this->height = side;
        cout << "I'm a Square Polygon" << endl;
    }
    void set_values (int width, int height) {
        this->width=width;
        this->height=height;
    }

   void print_area() const {cout << "I have no area"<< endl;}
   string get_type() const  {
        return "Poly gone!";
    }

};

/*Rectangle extends Polygon
//Notice the public after the colon. Removing the word public will make it
//private by default. If we do that, then function area will lose access to the
//member variables because they are protected, not public
//try removing the public keyword
*/
class Rectangle: public Polygon {
    string type;
public:
/*note that his class has no constructor. The default constructor will also call
//the default constructor of the parent class.
*/
    void print_area () const  {
        int area = width * height;
        cout << "Area of rectangle is " << area << endl;
    }
    string get_type() const  {
        return type;
    }
};

class Triangle: public Polygon {
    string type;
    public:
    Triangle(): Polygon(0,0) {
        type = "Triangle";
    }
    void print_area () const {
        int area = width * height / 2;
        cout << "Area of triangle is " << area << endl;
    }
    string get_type() const {
        return type;
    }
};

class Square: public Polygon {
    string type;
    public:
    Square(int a) : Polygon(a) {
        //instead of calling a delegated constructor, the line below creates a Polygon
        //Polygon(a); The correct way of calling the parent constructor is :Polygon(a) before {
        type = "square";
    }
    void print_area () const {
        int area = width * height;
        cout << "Area of square is " << area << endl;
    }

    string get_type() const {
        return type;
    }

};

void print_type(const Polygon * poly) {
    cout << poly->get_type() << endl;
}
int main()
{
    Rectangle rect;
    Triangle trgl;

    rect.set_values (4,5);
    trgl.set_values (2,5);
    rect.print_area();
    trgl.print_area();

    //Now let's do some polymorphism
    Polygon *polygon = new Square(10);
    Square *square = new Square(20);

    polygon->print_area();
    square->print_area();

    print_type(polygon);
    print_type(square);

    delete polygon;
    delete square;

    return 0;
}