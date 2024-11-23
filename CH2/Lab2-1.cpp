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

    float getReal();
    float getImg();
    void setReal(float r);
    void setImg(float i);
    void print();
    complex add(complex c);
    complex sub(complex c);
};

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
    complex c1, c2, c3;
    c1.setReal(5);
    c2.setReal(8);
    c1.setImg(2);
    c2.setImg(2);
    c3 = c1.sub(c2);
    c3.print();
    return 0;
}