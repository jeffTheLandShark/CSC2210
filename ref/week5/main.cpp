
#include <iostream>
#include "rectangle.h"

using namespace std;

int main() {
    Rectangle r1(3, 4);
    cout << "Area of r1: " << r1.area() << endl;
    cout << "Perimeter of r1: " << r1.perimeter() << endl;
    
    Rectangle r2(5, 6);
    cout << "Area of r2: " << r2.area() << endl;
    cout << "Perimeter of r2: " << r2.perimeter() << endl;
    
    return 0;
}
