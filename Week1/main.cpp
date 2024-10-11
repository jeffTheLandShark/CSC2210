#include <iostream>
using namespace std;

int main() {
    cout << "Enter an integer: ";
    int number;
    cin >> number;
    int cube = number * number * number;
    cout << "The cube of " << number << " is " << cube;
}
