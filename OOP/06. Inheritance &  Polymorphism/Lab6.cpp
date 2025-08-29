#include <stdio.h>
#include <iostream>
#include <string>

class Base
{
    int a;

protected:
    int b;

public:
    Base(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }
    void SetA(int a)
    {
        this->a = a;
    }
    void SetB(int b)
    {
        this->b = b;
    }
    int GetA()
    {
        return a;
    }
    int GetB()
    {
        return b;
    }
    int product()
    {
        return a * b;
    }
};

class Derived : public Base
{
    int c;

public:
    Derived(int a = 0, int b = 0, int c = 0) : Base(a, b)
    {
        this->c = c;
    }
    void SetC(int c = 0)
    {
        this->c = c;
    }
    int GetC()
    {
        return c;
    }
    // function overriding
    int product()
    {
        return Base::product() * c;
    }
};

class Derived : public Base
{
    int c;

public:
    Derived(int a = 0, int b = 0, int c = 0) : Base(a, b)
    {
        this->c = c;
    }
    void SetC(int c = 0)
    {
        this->c = c;
    }
    int GetC()
    {
        return c;
    }
    // function overriding
    int product()
    {
        return Base::product() * c;
    }
};

class SecondDerived : public Derived
{
    int d;

public:
    SecondDerived(int a = 0, int b = 0, int d = 0) : Derived(a, b)
    {
        this->d = d;
    }
    void SetD(int d = 0)
    {
        this->d = d;
    }
    int GetD()
    {
        return d;
    }
    // function overriding
    int product()
    {
        return b * Base::product() * d; // it could be acceptable because b is alreaduy protected so could be shared with childern
    }
};

/*
Example about inhertance with compositing

Manager:: Manager(): Base() a(3),b(2,3){
    // without thinking, by see this line you will understand that Manager is class and Manager() is construcor
    // inherit from Base class
    // and Manager class is in compostion relation with another class and a,b its instances
    // and order of executation for this line is Base->Compostion relation -> Manager.

    // Destructor will be in opposite order.
}
*/

// Function that takes a Base type object as an argument
void someFunction(Base t)
{
    t.product(); // Calls the public member function of the Base class
}

// Function that specifically takes a Derived type object as an argument only and if parameter is pass in base will
// be regarded as error. But we can solve it be function overloading
void someFunction(Derived t)
{
    t.product(); // Calls the public member function of the Derived class
}

int main()
{
    Base bo(5, 4); // Create an object of the Base class
    Derived obj;   // Create an object of the Derived class

    std::cout << bo.product() << "\n";        // will call product function in base class
    std::cout << obj.product() << "\n";       // will call product function in nearest class which is Derived class
    std::cout << obj.Base::product() << "\n"; // will call the base class function from derived instnce

    /*===============================================*/

    // This works because the Base class object is passed to the function
    someFunction(bo);

    // This also works because a Derived object can be passed as Base
    // due to implicit upcasting
    someFunction(obj);

    /*===============================================*/
    Base *opt = &obj;                    // will point to base section only.
    std::cout << opt->product() << "\n"; // will call the base class function from base pointer instnce
}