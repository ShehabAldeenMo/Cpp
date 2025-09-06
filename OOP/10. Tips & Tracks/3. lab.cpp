#include <iostream>
using namespace std;

// int &fun()
// {
//     static int x = 10;
//     return x;
// }
// int main()
// {
//     fun() = 30;
//     cout << fun();
//     return 0;
// }

/*===================================================================*/
// class Test
// {
//     static int x;
//     int *ptr;
//     int y;
// };

// int main()
// {
//     Test t;
//     /*
//         For a compiler where pointers take 4 bytes, the statement "sizeof(Test *)" returns 4
//         (size of the pointer ptr). The statement "sizeof(t)" returns 8. Since static is not
//         associated with each object of the class, we get (8 not 12)
//     */
//     cout << sizeof(t) << " ";
//     cout << sizeof(Test *);

//     int cin;
//     cin >> cin;
//     cout << "\n"
//          << cin << "\n";
// }
/*===================================================================*/

// int i;

// class A
// {
// public:
//     ~A()
//     {
//         i = 10;
//         cout << "ok\n";
//     }
// };

// int foo()
// {
//     i = 3;
//     A ob;
//     return i;
// }

// int main()
// {
//     /*
//         Output of the above program is "i = 3". Why the output is i= 3 and not 10? While returning
//         from a function, destructor is the last method to be executed. The destructor for the object
//         "ob" is called after the value of i is copied to the return value of the function. So,
//         before destructor could change the value of i to 10, the current value of i gets copied & hence
//         the output is i = 3. How to make the program to output "i = 10" ? Following are two ways of
//         returning updated value: 1) Return by Reference: Since reference gives the l-value of the
//         variable,by using return by reference the program will output "i = 10".
//     */
//     cout << foo() << endl;
//     return 0;
// }

/*===================================================================*/

// int i;

// class A
// {
// public:
//     ~A()
//     {
//         i = 10;
//     }
// };

// int &foo()
// {
//     i = 3;
//     A ob;
//     return i;
// }

// int main()
// {
//     /*
//         The function foo() returns the l-value of the variable i. So, the address of i will be copied in the return
//         value. Since, the references are automatically dereferened. It will output "i = 10".
//     */
//     cout << "i = " << foo() << endl;
//     return 0;
// }

/*===================================================================*/

// int i;

// class A
// {
// public:
//     ~A()
//     {
//         i = 10;
//     }
// };

// int foo()
// {
//     i = 3;
//     {
//         // 2. Create the object ob in a block scope
//         A ob;
//     }
//     return i;
// }

// int main()
// {
//     cout << "i = " << foo() << endl;
//     return 0;
// }

/*===================================================================*/
// class Test
// {
//     int x;

// public:
//     void *operator new(size_t size);
//     void operator delete(void *);
//     Test(int i)
//     {
//         x = i;
//         cout << "Constructor called \n";
//     }
//     ~Test() { cout << "Destructor called \n"; }
// };

// void *Test::operator new(size_t size)
// {
//     void *storage = malloc(size);
//     cout << "new called \n";
//     return storage;
// }

// void Test::operator delete(void *p)
// {
//     cout << "delete called \n";
//     free(p);
// }

// int main()
// {
//     Test *m = new Test(5);
//     delete m;
//     return 0;
// }

/*
Why This Order?
Because:
    - The destructor needs access to the object’s memory to destroy its members properly.
    - If memory were freed before the destructor ran, the object would be in an invalid state (use-after-free bug).
    - Therefore, the language ensures:
        1. Run destructor
        2. Then free memory
*/

/*===================================================================*/
// class Test
// {
// private:
//     int x;

// public:
//     Test(int x = 0) { this->x = x; }
//     void change(Test *t) { this = t; } // this is a const pointer, so there is an error in line "this = t;"
//     void print() { cout << "x = " << x << endl; }
// };

// int main()
// {
//     Test obj(5);
//     Test *ptr = new Test(10);
//     obj.change(ptr);
//     obj.print();
//     return 0;
// }

/*===================================================================*/

// class Test
// {
// private:
//     int x;

// public:
//     Test() { x = 0; }
//     void destroy() { delete this; } // undefined behaviour not complair error
//     void print() { cout << "x = " << x; }
// };

// int main()
// {
//     Test obj;
//     obj.destroy();
//     obj.print();
//     return 0;
// }

/*===================================================================*/

// int fun(int x = 0, int y = 0, int z) // All default arguments must be the rightmost arguments.
// {
//     cout << "x = " << x << " y = " << y << " z = " << z << "\n";
//     return (x + y + z);
// }

// int main()
// {
//     cout << fun(10);
//     return 0;
// }

/*===================================================================*/
// 1) Function declarations that differ only in the return type.
// int foo()
// {
//     return 10;
// }

// // char foo() // fails in compilation.
// // {
// //     return 'a';
// // }

// int main()
// {
//     char x = foo();
//     getchar();
//     return 0;
// }

/*===================================================================*/
// 2) Member function declarations with the same name and the name parameter-type-list
// cannot be overloaded if any of them is a static member function declaration. For example,
// following program fails in compilation.
// class Test
// {
//     static void fun(int i) {}
//     void fun(int i) {} // compilation error.
// };

// int main()
// {
//     Test t;
//     getchar();
//     return 0;
// }

/*===================================================================*/
// 3) Parameter declarations that differ only in a pointer * versus an array [] are equivalent.
// int fun(int *ptr);
// int fun(int ptr[]); // redeclaration of fun(int *ptr)

// 4) Two parameter declarations that differ only in their default arguments
/*
In C++, function overloading is based on the function signature, which includes:
    - Function name
    - Number and types of parameters (NOT their names)
    - const qualifiers only for pointer or reference parameters
    - Whether it's a member or non-member function
    - Reference qualifiers (for member functions)

    - ❗ Default arguments are not part of the function signature.
*/
// void fun(int x, int y)
// {
//     cout << "fun(int x, int y) \n";
// }
// void fun(int x = 10, int y = 10)
// {
//     cout << "fun(int x = 10, int y = 10) \n";
// }

// int f(int x)
// {
//     return x + 10;
// }

// int f(const int x)
// {
//     return x + 10;
// }

// int main()
// {
//     const int x = 5;
//     f(x);
// }

/*===================================================================*/
// class base
// {
//     int arr[10];
// };

// class b1 : public base
// {
// };

// class b2 : public base
// {
// };

// class derived : public b1, public b2
// {
// };

// int main(void)
// {
//     cout << sizeof(derived);
//     return 0;
// }

/*===================================================================*/
// class base
// {
//     int arr[10];
// };

// class b1 : virtual public base
// {
// };

// class b2 : virtual public base
// {
// };

// class derived : public b1, public b2
// {
// };

// int main(void)
// {
//     cout << sizeof(derived);
//     return 0;
// }

/*===================================================================*/
// class Base
// {
// };

// class Derived : public Base
// {
// };

// int main()
// {
//     Base *bp = new Derived;
//     // Derived *dp = new Base; // complair error
// }

/*===================================================================*/
// class Base
// {
// };

// class Derived : public Base
// {
// };

// int main()
// {
//     Base *bp = new Derived;
//     Base b;
//     Derived *dp = static_cast<Derived *>(&b); // unexpected behaviour - down-casting
// }

/*===================================================================*/
// class Base
// {
// public:
//     virtual void show()
//     {
//         cout << " In Base \n";
//     }

//     void show2()
//     {
//         cout << "Base : show2 \n";
//     }
// };

// class Derived : public Base
// {
// public:
//     int x;
//     void show() override
//     {
//         cout << "In Derived \n";
//     }
//     Derived()
//     {
//         x = 10;
//     }
// };

// int main(void)
// {
//     Base *bp, b;
//     Derived d;
//     bp = &d;
//     bp->show();
//     bp->show2();
//     // cout << bp->x; // complair error
//     return 0;
// }

/*===================================================================*/
// class Base
// {
// public:
//     virtual void show() { cout << " In Base \n"; }
// };

// class Derived : public Base
// {
// public:
//     void show() override { cout << "In Derived \n"; }
// };

// int main(void)
// {
//     Base *bp = new Derived;
//     bp->show();

//     // Since show() is virtual in base class, it is called according to the type of object being referred
//     // or pointed, rather than the type of pointer or reference.
//     Base &br = *bp;
//     br.show();

//     return 0;
// }

/*===================================================================*/
// template <int i>
// void fun()
// {
//     i = 20; // passing argument is const.
//     cout << i;
// }

// int main()
// {
//     fun<10>();
//     return 0;
// }

/*===================================================================*/
// class Base
// {
// };

// class Derived : public Base
// {
// };

// void show(int x)
// {
//     cout << "\nshow\n";
// }

// int main()
// {
//     Derived d;
//     try
//     {
//         throw d;
//     }
//     catch (Base b)
//     {
//         cout << "Caught Base Exception";
//     }
//     catch (Derived d)
//     {
//         cout << "Caught Derived Exception";
//     }

//     char c = 'a';
//     show(c);
//     return 0;
// }
