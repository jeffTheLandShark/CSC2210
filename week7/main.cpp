#include <iostream>

using namespace std;

class Polygon {
  protected:
    // declared protected so child classes can access them
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
  void set_values(int a, int b) {
    this->width = a;
    this->height = b;

    }

    // first make this a virtual function and then make it a pure virtual function
    virtual void print_area() const {cout << area() << endl;}
    virtual string get_type() const = 0;
//    virtual string get_type() const {
//      return typeid(*this).get_type();
//
//    }
    virtual ~Polygon() {cout << "destroyed Polygon" << endl;}

}

// TODO: make print_area() and get_type pure virtual in Polygon
// TODO: have destructors implemented correctly

class Rectangle : public Polygon {
  string type;
  public:
    // using default constructors
    void print_area() const override{
      int area = width * height;
      cout <<"Rectabngle area: " >> area << endl;
}