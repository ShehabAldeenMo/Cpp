#include <iostream>

class Base
{
public:
    virtual void print() const { std::cout << "Base class" << std::endl; }
    void print2() const { std::cout << "Base class without virtual keyword" << std::endl; }
};

class Derived : public Base
{
public:
    void print() const override { std::cout << "Derived class" << std::endl; }
    void print2() const { std::cout << "Derived class without virtual keyword" << std::endl; }
    void derivedOnly() const { std::cout << "Derived-only function" << std::endl; }
};

int main()
{
    // Upcasting (Derived* to Base*)
    Derived d;
    Base *b = static_cast<Base *>(&d); // Safe, no runtime check needed
    b->print();
    b->print2();

    Base base;
    b = static_cast<Base *>(&base); // Safe, no runtime check needed
    b->print();
    std::cout << "==================================================================================\n";

    Base base2;
    Derived *derivedPtr = static_cast<Derived *>(&base2); // Correct here, but no runtime check
    derivedPtr->print();
    derivedPtr->print2();
    derivedPtr->derivedOnly();

    std::cout << "==================================================================================\n";
    Base *baseptr = new Base; // down casting
    Derived *derivedptr = new Derived;
    if (dynamic_cast<Derived *>(baseptr))
        std::cout << "huh?\n";

    return 0;
}