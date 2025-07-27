#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate area of an isosceles triangle
double getArea(double base, double equalSides) {
    double height = sqrt((equalSides * equalSides) - (base * base / 4.0));
    return (base * height) / 2.0;
}

// Function to calculate perimeter
double getPerimeter(double base, double equalSides) {
    return base + 2 * equalSides;
}

int main() {
    double base1 = 60, side1 = 50;
    cout << base1 << endl;
    cout << side1 << endl;
    cout << getArea(base1, side1) << endl;
    cout << getPerimeter(base1, side1) << endl;
    cout << endl;

    double base2 = 80, side2 = 60;
    cout << base2 << endl;
    cout << side2 << endl;
    cout << getArea(base2, side2) << endl;
    cout << getPerimeter(base2, side2) << endl;
    cout << endl;

    base1 = 10.0;
    side1 = 8.0;
    cout << base1 << endl;
    cout << side1 << endl;
    cout << getArea(base1, side1) << endl;
    cout << getPerimeter(base1, side1) << endl;

    return 0;
}
