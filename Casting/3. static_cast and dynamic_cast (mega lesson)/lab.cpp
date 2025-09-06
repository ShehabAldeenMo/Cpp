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

void printInt(void *ptr)
{
    int *intPtr = static_cast<int *>(ptr);
    // int *intPtr = dynamic_cast<int *>(ptr); // lead to error case
    std::cout << "void* casting with static_cast , Value: " << *intPtr << std::endl;
}

void ProcessCall(Base b)
{
    try
    {
        Derived &d = dynamic_cast<Derived &>(b);
        d.print2();
    }
    catch (const std::bad_cast &e)
    {
        std::cout << "Bad Casting....\n";
    }
}

int main()
{
    Derived d;
    Base *b = static_cast<Base *>(&d);
    b->print();
    b->print2();

    Base base;
    b = static_cast<Base *>(&base);
    b->print();
    std::cout << "==================================================================================\n";

    Base base2;
    Derived *derivedPtr = static_cast<Derived *>(&base2);
    derivedPtr->print();
    derivedPtr->print2();
    derivedPtr->derivedOnly();

    std::cout << "==================================================================================\n";
    Base *baseptr = new Base; // down-casting
    Derived *derivedptr = new Derived;
    if (dynamic_cast<Derived *>(baseptr))
        std::cout << "huh?\n";

    int x = 42;
    printInt(&x);

    std::cout << "==================================================================================\n";
    Base obj;
    ProcessCall(obj);

    return 0;
}