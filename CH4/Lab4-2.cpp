#include <stdio.h>
#include <iostream>
#include <string>

class complex
{
    int real;
    int img;

public:
    complex(int real = 0, int img = 0)
    {
        this->real = real;
        this->img = img;
    }

    ~complex()
    {
        std::cout << "Destructor called\n";
    }
    complex operator+(complex x);
    complex operator+(float f);
    complex operator-(complex x);
    complex operator-(float f);
    bool operator==(complex c);
    void operator+=(complex c);
    void operator+=(float f);
    complex operator++();    // prefix
    complex operator++(int); // postfix
    operator float() const;  // castinf operator
    float getReal();
    float getImg();
    void setReal(float r);
    void setImg(float i);
    void print();
    complex add(complex c);
    complex sub(complex c);
    friend complex operator+(float x, complex c);
    friend complex operator-(float x, complex c);
};

complex complex::operator+(complex x)
{
    complex b;
    b.real = this->real + x.real;
    b.img = this->img + x.img;
    return b;
}

complex complex::operator+(float f)
{
    complex b;
    b.real = this->real + f;
    b.img = this->img;
    return b;
}

complex complex::operator-(complex x)
{
    complex b;
    b.real = this->real - x.real;
    b.img = this->img - x.img;
    return b;
}

complex complex::operator-(float f)
{
    complex b;
    b.real = this->real - f;
    b.img = this->img;
    return b;
}

bool complex::operator==(complex c)
{
    bool statue = false;
    if (this->real == c.real && this->img == c.img)
    {
        statue = true;
    }
    else
    {
        statue = false;
    }
    return statue;
}

void complex::operator+=(complex c)
{
    this->real += c.real;
    this->img += c.img;
}

void complex::operator+=(float f)
{
    this->real += f;
}

complex complex::operator++()
{
    complex c;
    c.real++;
    return c;
}

complex complex::operator++(int)
{
    complex c;
    ++c.real;
    return c;
}

complex::operator float() const
{
    return this->real;
}

// stand alone function if caller is float
complex operator+(float x, complex c)
{
    complex cur;
    cur.real = x + c.real;
    cur.img = c.img;
    return cur;
}

// stand alone function if caller is float
complex operator-(float x, complex c)
{
    complex cur;
    cur.real = x - c.real;
    cur.img = c.img;
    return cur;
}

float complex::getReal()
{
    return real;
}

float complex::getImg()
{
    return img;
}

void complex::setReal(float r)
{
    real = r;
}

void complex::setImg(float i)
{
    img = i;
}

void complex::print()
{
    if (img > 0)
    {
        std::cout << real << "+" << img << "i\n";
    }
    else
    {
        std::cout << real << "-" << img << "i\n";
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