#include <iostream>
#include <cmath>
using namespace std;

struct IsoscelesTriangle {
    double base;
    double equalSides;
    
    IsoscelesTriangle(double b, double s) {
        base = b;
        equalSides = s;
    }
    
    double getArea() {
        double height = sqrt((equalSides * equalSides) - (base * base / 4));
        return (base * height) / 2;
    }
    
    double getPerimeter() {
        return base + 2 * equalSides;
    }
};

int main() {
   
    // An isosceles triangle 1
    
    IsoscelesTriangle triangle1(60, 50);
    
    cout << "Triangle 1:" << endl;
    cout << "Base: " << triangle1.base << endl;
    cout << "Equal sides: " << triangle1.equalSides << endl;
    cout << "Area: " << triangle1.getArea() << endl;
    cout << "Perimeter: " << triangle1.getPerimeter() << endl;
    cout << endl;
    
    // An isosceles triangle 2

    IsoscelesTriangle triangle2(80, 60);
    
    cout << "Triangle 2:" << endl;
    cout << "Base: " << triangle2.base << endl;
    cout << "Equal sides: " << triangle2.equalSides << endl;
    cout << "Area: " << triangle2.getArea() << endl;
    cout << "Perimeter: " << triangle2.getPerimeter() << endl;
    cout << endl;
    
    // To modify the values directly

    triangle1.base = 10.0;
    triangle1.equalSides = 8.0;
    
    cout << "Triangle 1 (modified):" << endl;
    cout << "Modified area: " << triangle1.getArea() << endl;
    cout << "Modified perimeter: " << triangle1.getPerimeter() << endl;
    
    return 0;

}