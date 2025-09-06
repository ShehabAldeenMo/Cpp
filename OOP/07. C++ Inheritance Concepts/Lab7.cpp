#include <stdio.h>
#include <iostream>
#include <string>

class GeoShape
{
protected:
    int Dim1, Dim2;

public:
    GeoShape(int a = 0, int b = 0) : Dim1(a), Dim2(b) {}
    void SetDim1(int a) { this->Dim1 = a; }
    void SetDim2(int b) { this->Dim2 = b; }
    int GetDim1() { return Dim1; }
    int GetDim2() { return Dim2; }
};

class Triangle : virtual public GeoShape
{
public:
    Triangle(int a = 0, int b = 0) : GeoShape(a, b) {}
    void SetDim1(int a) { this->Dim1 = a; }
    void SetDim2(int b) { this->Dim2 = b; }
    int GetDim1() { return Dim1; }
    int GetDim2() { return Dim2; }
    float CalculateArea() { return (0.5 * Dim1 * Dim2); }
};

class Rect : virtual public GeoShape
{
public:
    Rect(int a = 0, int b = 0) : GeoShape(a, b) {}
    void SetDim1(int a) { this->Dim1 = a; }
    void SetDim2(int b) { this->Dim2 = b; }
    int GetDim1() { return Dim1; }
    int GetDim2() { return Dim2; }
    float CalculateArea() { return (Dim1 * Dim2); }
};

class Circle : private GeoShape
{
    int radius;

public:
    Circle(int r = 0) : GeoShape(r, r) {}
    void SetRadius(int r = 0) { Dim1 = Dim2 = r; }
    float CalculateArea() { return (22.0 / 7 * Dim2 * Dim1); }
};

class Square : private Rect
{
public:
    Square(int side = 0) : Rect(side, side) {}
    void SetSide(int side) { Dim1 = Dim2 = side; }
    int GetSide() { return Rect::GetDim1(); } // Since both dimensions are equal, returning one is sufficient.
    float CalculateArea() { return Rect::CalculateArea(); }
};

int main()
{
    Triangle t(5, 4);
    std::cout << "Triangle Area: " << t.CalculateArea() << std::endl;

    // Using setter to change dimensions for Triangle
    t.SetDim1(6);
    t.SetDim2(8);
    std::cout << "Updated Triangle Area: " << t.CalculateArea() << std::endl;

    Rect r(5, 4);
    std::cout << "Rectangle Area: " << r.CalculateArea() << std::endl;

    // Using setter to change dimensions for Rectangle
    r.SetDim1(10);
    r.SetDim2(12);
    std::cout << "Updated Rectangle Area: " << r.CalculateArea() << std::endl;

    Square sq(5);
    std::cout << "Square Side: " << sq.GetSide() << std::endl;
    std::cout << "Square Area: " << sq.CalculateArea() << std::endl;

    // Update the side
    sq.SetSide(10);
    std::cout << "Updated Square Side: " << sq.GetSide() << std::endl;
    std::cout << "Updated Square Area: " << sq.CalculateArea() << std::endl;

    return 0;
}
