#include <stdio.h>
#include <iostream>
#include <string>

// object
class complex
{
    int real;
    int img;

public:
    complex() : real(0), img(0) {}
    float getReal();        // get real part
    float getImg();         // get imaginary part
    void setReal(float r);  // set value of real part
    void setImg(float i);   // set value of imaginary part
    void print();           // print number in complex format
    complex add(complex c); // make add operations on complex numbers
    complex sub(complex c); // make sub operations on complex numbers
};

float complex::getReal() { return real; }

float complex::getImg() { return img; }

void complex::setReal(float r) { real = r; }

void complex::setImg(float i) { img = i; }

void complex::print()
{
    if (img > 0)
    {
        std::cout << real << "+" << img << "i\n";
    }
    else
    {
        std::cout << real << img << "i\n";
    }
}

complex complex::add(complex c)
{
    complex temp;
    temp.real += c.getReal();
    temp.img += c.getImg();
    return temp;
}

complex complex::sub(complex c)
{
    complex temp;
    temp.real -= c.getReal();
    temp.img -= c.getImg();
    return temp;
}

int main()
{
    complex c1, c2, c3;
    c1.setReal(5);
    c2.setReal(8);
    c1.setImg(2);
    c2.setImg(2);
    c3 = c1.sub(c2);
    c3.print();
    return 0;
}