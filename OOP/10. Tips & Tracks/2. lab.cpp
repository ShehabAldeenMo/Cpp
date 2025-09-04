
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <thread>
#include <cassert>
using namespace std;

// class A
// {
// public:
//     A() {} // user-provided constructor
//     int i;
//     string s;
// };

// class B
// {
// public:
//     // NOT user-provided constructor
//     // implicit generated default constructor
//     int i;
//     string s;
// };

// class C
// {
// public:
//     // NOT user-provided constructor
//     C() = default; // assign default values
//     int i;
//     string s;
// };

// class D
// {
// public:
//     int i;
//     string s;

//     // user-provided constructor ... OOPS
//     D();
// };
// D::D() = default;

// int main()
// {
//     for (int i = 0; i < 3; ++i)
//     {
//         // Default-initialization - undetermined value
//         A a1;
//         B b1;
//         C c1;
//         D d1;
//         cout << a1.i << "\n"; // typically garbage
//         cout << b1.i << "\n"; // typically garbage
//         cout << c1.i << "\n"; // typically garbage
//         cout << d1.i << "\n"; // typically garbage
//     }

//     cout << "now with value initialization\n\n";
//     // Value-initialization triggered by {}
//     A a2{};
//     B b2{};
//     C c2{};
//     D d2{};
//     cout << a2.i << "\n"; // still garbage
//     cout << b2.i << "\n"; // always 0
//     cout << c2.i << "\n"; // always 0
//     cout << d2.i << "\n"; // still garbage

//     // s ALWAYS = "" as its default constructor is called
// }

/*===================================================================*/
// /* 1. const member functions classes couldn't change in member variables.
//  * 2. const member functions classes could change in mutable member variables.
//  * 3. const instances objects could use const member functions only.
//  * 4. const pointers for object could use both but couldn't change which object are point after decleration.
//  */
// class Rectangle
// {
// private:
//     double width;
//     double height;
//     mutable bool flag;

// public:
//     Rectangle(double width = 0.0, double height = 0.0) : width(width), height(height) {}

//     // width = 1; // CE: function is const, can't change member variables
//     double ComputeArea() const
//     {
//         flag = true;
//         return width * height;
//     }

//     // Setters & Getters
//     double GetHeight() const { return height; }
//     void SetHeight(double height) { this->height = height; }
//     double GetWidth() const { return width; }
//     void SetWidth(double width) { this->width = width; }
// };

// int main()
// {
//     /*objects*/
//     Rectangle r(2, 3);
//     r.ComputeArea();
//     r.SetWidth(10);

//     const Rectangle r_(4, 5);
//     r_.ComputeArea();
//     // r_.SetWidth(10); // CE: const object can't call non-const member function

//     /*pointers*/
//     Rectangle r1(2, 3);
//     const Rectangle *r2 = new Rectangle(4, 5); // const methods, const data
//     // r2->SetWidth(10.2);                        // Not ok,  const data
//     r2 = &r1; // OK, not const pointer

//     Rectangle *const r3 = new Rectangle(1, 2);
//     r3->SetWidth(10.2); // OK, non-const data
//     // r3 = &r1;           // Can't const pointer

//     const Rectangle *const r4 = new Rectangle(1, 2);
//     // r4->SetWidth(10.2); // Can't, const data
//     // r4 = &r1;           // Can't const pointer

//     const Rectangle *const r5 = &r1; // The opposite is not ok

//     return 0;
// }

/*===================================================================*/
// friend keyword usage.
// class A; // Define early to break cycle

// class B
// {
// public:
//     void AcessA1(A &x);
//     void AcessA2(A &x);
// };

// class A
// {
// private:
//     int a1_private = 10;
//     int a2_private = 20;

//     void HiddenA()
//     {
//         std::cout << "I am hidden\n";
//     }

// public:
//     // Friend function only access my private data
//     friend void B::AcessA1(A &x);
// };

// void B::AcessA1(A &x)
// {
//     std::cout << x.a1_private << "\n";
//     x.HiddenA();
// }

// void B::AcessA2(A &x)
// {
//     // Syntax error: can't access these private data
//     // std::cout << x.a2_private << "\n";
//     // x.HiddenA();
// }

// int main()
// {
//     return 0;
// }

/*===================================================================*/
// Destructors run in reverse order of construction (for locals and statics separately)
// class Empolyee
// {
// private:
//     string name;

// public:
//     Empolyee(string name) : name(name)
//     {
//         cout << "Constructor " << name << "\n";
//     }
//     ~Empolyee()
//     {
//         cout << "Destructor " << name << "\n";
//     }
// };

// int main()
// {
//     static Empolyee shehab("shehab");
//     Empolyee most("most");

//     {
//         Empolyee("asmaa");
//     }

//     static Empolyee Mona("Mona");
// }

// /*
// Constructor shehab
// Constructor most
// Constructor asmaa
// Destructor asmaa
// Constructor Mona
// Destructor most
// Destructor Mona
// Destructor shehab
// */

/*===================================================================*/
// protected variables
// class Person
// {
// protected:
//     string name;

// public:
//     Person() : name("most") { cout << "Person Default Constructor\n"; }
//     Person(string name) : name(name) { cout << "Person 2nd Constructor\n"; }
//     ~Person() { cout << "Person Destructor\n"; }
// };

// class Student : public Person
// {
// private:
//     double gpa;

// public:
//     Student()
//     {
//         cout << "Student Default Constructor\n";
//         gpa = 0;
//         name = "hani";
//     }
//     Student(double gpa) : Person("Ali"), gpa(gpa) { cout << "Student 2nd Constructor\n"; }
//     ~Student() { cout << "Student Destructor\n"; }
// };

// int main()
// {
//     return 0;
// }

/*===================================================================*/
// types of inheritance.
// class Base
// {
// protected:
//     int x;
//     int y;

// public:
//     Base();
//     ~Base();
// };

// class Derived : protected Base
// {
// public:
//     Derived();
//     ~Derived();
// };

// class Derived2 : private Base
// {
// public:
//     Derived2();
//     ~Derived2();
// };

// class Derived3 : public Derived
// {
// public:
//     Derived3()
//     {
//         Base::x = 10;
//     }
//     ~Derived3();
// };

// class Derived4 : public Derived2
// {
// public:
//     Derived4()
//     {
//         Base::x = 10;
//     }
//     ~Derived4();
// };

// int main()
// {
//     return 0;
// }

/*===================================================================*/
// virtual destructors
// class A
// {
// public:
//     ~A() { cout << "~A\n"; }
// };

// class B : public A
// {
// public:
//     ~B() { cout << "~B\n"; }
// };

// int main()
// {
//     // in objects already calls destructors in reverse order of constructors
//     B b;

//     // in pointers with polymfirism should make virtual destructors for destruct base pointers in right order.
//     A *a = new B();
//     delete a; // Since A’s destructor is not virtual, only ~A() is called — not ~B().
//               // when delete pointer without virtual destructor may lead to destruct only its class object and remain
//               // the inherited class still alive unfortunately.
//     return 0;
// }

/*===================================================================*/
// choose
// class A
// {
// public:
//     A() {}
//     virtual A *what() const
//     {
//         throw logic_error("Not implemented");
//     }
// };

// class B : public A
// {
// public:
//     int c;

//     B(int c) : A(), c(c) {}
//     virtual A *what() const
//     {
//         return new B(this->c);
//     }
// };

// int main()
// {
//     A *a1 = new B(11);
//     A *a2 = a1->what();

//     /*
//         (Choose) The previous was:
//         - nothing useful.
//         - reference to itself
//         - return a child copy of this using normal constructor call and passing needed parameter. (true)
//         - return a child copy of this using copy constructor.
//     */
//     return 0;
// }

/*===================================================================*/
// Choose
// class A
// {
// public:
//     A() {}
//     virtual A *what() const
//     {
//         throw logic_error("Not implemented");
//     }
// };

// class B : public A
// {
// public:
//     int c;

//     B(int c) : A(), c(c) {}
//     virtual A *what() const
//     {
//         return new B(*this);
//     }
// };

// int main()
// {
//     A *a1 = new B(11);
//     A *a2 = a1->what();

//     /*
//         The previous was:
//         - nothing useful.
//         - reference to itself
//         - return a child copy of this using normal constructor call and passing needed parameter.
//         - return a child copy of this using copy constructor.   (true)
//     */
//     return 0;
// }

/*===================================================================*/
// Choose
// class A
// {
// public:
//     A() {}
//     virtual int value1()
//     {
//         throw logic_error("Not implemented");
//     }

//     int value2()
//     {
//         return 5;
//     }
// };

// class B : public A
// {
// public:
//     int c;

//     B(int c) : A(), c(c) {}
//     int value1() override
//     {
//         return c * value2();
//     }
// };

// int main()
// {
//     A *a = new B(10);
//     cout << a->value1();

//     /*
//     1. the child class will call parent class to compute the result.     (true)
//     2. the parent class will call the child class to compute the result.
//     */
//     return 0;
// }

/*===================================================================*/
// Choose
// class A
// {
// public:
//     A() {}
//     virtual int value1()
//     {
//         throw logic_error("Not implemented");
//     }

//     int value2()
//     {
//         return 1 + value1();
//     }
// };

// class B : public A
// {
// public:
//     int c;

//     B(int c) : A(), c(c) {}
//     int value1() override
//     {
//         return c;
//     }
// };

// int main()
// {
//     A *a = new B(10);
//     cout << a->value2();
//     /*
//         1. the child class will call parent class to compute the result.
//         2. the parent class will call the child class to compute the result.     (true)
//     */
//     return 0;
// }

/*===================================================================*/
// override
// class Vehicle
// {
// public:
//     virtual int y()
//     {
//         return 11;
//     }
// };

// class Car : public Vehicle
// {
// public:
//     int y() override
//     {
//         return 21;
//     }
// };

// class Honda : public Car
// {
// public:
//     int y() override
//     {
//         return 31;
//     }
// };

// int main()
// {
//     cout << (new Honda())->y() << "\n";

//     Car *p1 = new Honda();
//     cout << p1->y() << "\n";

//     Vehicle *p2 = new Honda();
//     cout << p2->y() << "\n";

//     /*
//         31
//         31
//         31
//     */
//     return 0;
// }

// /*===================================================================*/
// override on default constructors
// class A
// {
// public:
//     virtual void f1(int x = 1)
//     {
//         cout << "A " << x << "\n";
//     }
// };

// class B : public A
// {
// public:
//     // don't override function with default parameters because alwasys lead to use default parameter of base class.
//     virtual void f1(int x = 2) override
//     {
//         cout << "B " << x << "\n";
//     }
// };

// int main()
// {
//     A *a = new B();
//     a->f1();
// }

// /*===================================================================*/
// casting with inherited classes
// class A
// {
// public:
//     ~A() {}
// };

// class B : public A
// {
// };
// class C : public A
// {
// };
// class D
// {
// };

// void static_cast_test()
// {
//     // Compile time check/cast
//     A *a_from_b = new B();

//     // No problem. Valid conversion
//     B *b = static_cast<B *>(a_from_b);
//     cout << b << "\n";

//     // Wrong conversion, but no runtime check
//     C *c = static_cast<C *>(a_from_b);
//     cout << c << "\n";

//     // Compilation error can be caught for such clear case
//     // D *d = static_cast<D *>(a_from_b);
// }

// int main()
// {
//     static_cast_test();
// }

/*===================================================================*/
// virtaul destructors.
// class base
// {
// public:
//     base() { cout << "Constructing base\n"; }
//     // A destructor can be virtual. We may want to call appropriate destructor when a base class pointer
//     // points to a derived class object and we delete the object. If destructor is not virtual, then only
//     // the base class destructor may be called.
//     // virtual ~base()
//     // {
//     //     cout << "Destructing base\n";
//     // }

//     // Deleting a derived class object using a
//     // pointer of base class type that has a non-virtual destructor results in undefined behavior
//     // and lead to memory leak.
//     ~base()
//     {
//         cout << "Destructing base\n";
//     }
// };

// class derived : public base
// {
// public:
//     derived()
//     {
//         cout << "Constructing derived\n";
//     }
//     ~derived()
//     {
//         cout << "Destructing derived\n";
//     }
// };

// int main()
// {
//     // derived *d = new derived();
//     base *b = new derived();
//     delete b;
//     return 0;
// }

/*===================================================================*/
// Say the output
// class Boolean
// {
// private:
//     bool is_true;

// public:
//     Boolean(bool is_true) : is_true(is_true) {}
//     bool operator&&(const Boolean &other) const
//     {
//         return this->is_true && other.is_true;
//     }
// };

// bool T()
// {
//     cout << "T\n";
//     return true;
// }
// bool F()
// {
//     cout << "F\n";
//     return false;
// }

// Boolean TC()
// {
//     cout << "TC\n";
//     return Boolean(true);
// }
// Boolean FC()
// {
//     cout << "FC\n";
//     return Boolean(false);
// }

// int main()
// {
//     F() && T();
//     FC() && TC();

//     return 0;
// }

/*===================================================================*/
// Say the output
// class Test
// {
// public:
//     Test() { cout << "Hello from Test() "; }
// } a;

// int main()
// {
//     cout << "Main Started ";
//     return 0;
// }

/*===================================================================*/
// class Point
// {
//     int x;

// public:
//     Point(int x) : x(x) {}
//     /*
//     But when you pass p by value, C++ needs to copy p — and to do that,
//     it needs the copy constructor... which is the one you're writing...
//     which leads to infinite recursion.
//     */
//     Point(Point p) { x = p.x; } // complair checks that and refuse. needs const and also by reference.
//     int getX() { return x; }
// };

// int main()
// {
//     Point p1(10);
//     Point p2 = p1;
//     cout << p2.getX();
//     return 0;
// }

/*===================================================================*/
// class MyPair
// {
// private:
//     int first;
//     int second;

// public:
//     // Single-argument constructors
//     // If constructor can be called with a single param it can be used to convert a datatype and there is a need = conversion
//     MyPair(int x) : MyPair(x, x) {}
//     MyPair(int first, int second) : first(first), second(second) {}
//     int getFirst() const { return first; }
//     int getSecond() const { return second; }
//     friend MyPair operator+(const MyPair &c1, const MyPair &c2);
// };

// MyPair operator+(const MyPair &c1, const MyPair &c2)
// {
//     return MyPair(c1.getFirst() + c2.getFirst(),
//                   c1.getSecond() + c2.getSecond());
// }

// int main()
// {
//     MyPair x(1, 2);
//     MyPair y(3);
//     MyPair w = 5;        // Converting constructor MyPair(int x)
//     MyPair z1 = x + 5.3; // implicit conversions

//     // 3 + x --> End up MyPair(3) + x
//     MyPair z2 = 3 + x + 5; // implicit conversions
// }

/*===================================================================*/
// forbiden to make two following implicit casting
// class MyPair
// {
// private:
//     int first;
//     int second;

// public:
//     // Single-argument constructors
//     // If constructor can be called with a single param it can be used to convert a datatype and there is a need = conversion
//     MyPair(int x) : MyPair(x, x) {}
//     MyPair(int first, int second) : first(first), second(second) {}
//     int getFirst() const { return first; }
//     int getSecond() const { return second; }
//     MyPair operator+(const MyPair &c2)
//     {
//         first += c2.first;
//         second += c2.second;
//         return *this;
//     }
// };

// int main()
// {
//     MyPair x(1, 2);
//     MyPair y(3);
//     MyPair w = 5;        // Converting constructor MyPair(int x)
//     MyPair z1 = x + 5.3; // one implicit conversions

//     // 3 + x --> End up MyPair(3) + x
//     // MyPair z2 = 3 + x + 5; // two implicit conversions is prohibited by complair
// }

/*===================================================================*/
// class MyPair
// {
// private:
//     int first;
//     int second;

// public:
//     // Single-argument constructors
//     // If constructor can be called with a single param it can be used to convert a datatype and there is a need = conversion
//     explicit MyPair(int x) : MyPair(x, x) {}
//     MyPair(int first, int second) : first(first), second(second) {}
//     int getFirst() const { return first; }
//     int getSecond() const { return second; }
//     MyPair operator+(const MyPair &c2)
//     {
//         first += c2.first;
//         second += c2.second;
//         return *this;
//     }
// };

// int main()
// {
//     MyPair x(1, 2);
//     MyPair y(3); // explicit
//     // MyPair w = 5;        // implicit
//     // MyPair z1 = x + 5.3; // implicit

//     // 3 + x --> End up MyPair(3) + x
//     // MyPair z2 = 3 + x + 5; // implicit
// }

/*===================================================================*/
// class MyNumber
// {
// public:
//     int num;
//     MyNumber(int num) : num(num) {}
// };

// MyNumber operator^(const MyNumber &c1, int pow)
// {
//     int res = 1;
//     while (pow--)
//         res *= c1.num;
//     return MyNumber(res);
// }

// MyNumber operator+(const MyNumber &c1, const MyNumber &c2)
// {
//     return MyNumber(c1.num + c2.num);
// }

// int main()
// {
//     MyNumber x(2);
//     MyNumber res1 = x ^ 3;
//     MyNumber res2 = 1 + x ^ 3;
//     cout << res1.num << " " << res2.num; // 8 27
//     return 0;
// }
