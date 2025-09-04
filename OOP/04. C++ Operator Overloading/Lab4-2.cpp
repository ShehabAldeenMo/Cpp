#include <stdio.h>
#include <iostream>
#include <string>

class complex
{
    int real;
    int img;

public:
    complex(int real = 0, int img = 0) : real(real), img(img) {}
    ~complex() { std::cout << "Destructor called\n"; }
    complex operator+(complex c) const { return complex(c.getReal() + real, c.img + img); }
    complex operator+(float f) const { return complex(f + real, img); }
    complex operator-(complex c) const { return complex(real - c.getReal(), img - c.img); }
    complex operator-(float f) const { return complex(real - f, img); }
    bool operator==(complex c) const { return (this->real == c.real && this->img == c.img) ? true : false; }
    void operator+=(complex c);
    void operator+=(float f) { this->real += f; }
    complex operator++();    // prefix
    complex operator++(int); // postfix
    operator float() const { return this->real; }
    void print() { (img > 0) ? std::cout << real << "+" << img << "i\n" : std::cout << real << "-" << img << "i\n"; }
    complex add(complex c) { return complex(real + c.getReal(), img + c.getImg()); }
    complex sub(complex c) { return complex(real - c.getReal(), img - c.getImg()); }
    float getReal() const { return real; }
    float getImg() const { return img; }
    void setReal(float r) { real = r; }
    void setImg(float i) { img = i; }
    friend complex operator+(float f, complex c) { return complex(c.getReal() + f, c.img); }
    friend complex operator-(float f, complex c) { return complex(f - c.getReal(), c.img); }
};

void complex::operator+=(complex c)
{
    this->real += c.real;
    this->img += c.img;
}

complex complex::operator++()
{
    ++real;
    return *this;
}

complex complex::operator++(int)
{
    complex temp = *this; // save current state
    ++real;               // increment current object
    return temp;          // return old value
}

int main()
{
    complex c1(8, 5), c2(3, 2), c3;
    c3 = c1 + c2;
    c3.print();
    c3 = c1 - c2;
    if (c1 == c2)
    {
        std::cout << "Equal\n";
    }
    c2 += c1;
    c2.print();
    c2++;
    ++c2;
    float f = (float)c2;
    std::cout << f << "\n";
    return 0;
}