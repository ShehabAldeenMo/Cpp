
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <thread>

using namespace std;

// class Rectangular
// {
// private:
//     // case 2: could be work without default constructor.
//     // int length = 0;
//     // int width = 0;

//     int length;
//     int width;

// public:
//     // case1: the next are default constructor so can't be work.
//     Rectangular() {}
//     Rectangular(int length = 0, int width = 0) : length(length), width(width) {}

//     // not regarded as default constructor.
//     // Rectangular(int length, int width = 0) : length(length), width(width) {}

//     // caes 3: you need to define empty constructor in this case to can create object from class.
//     // because now this constuctor could replace the default constructor
//     Rectangular(int length, int width) : length(0), width(0) {}
// };

// // case 4
// void cleanup(int *ptr)
// {
//     delete ptr; // ❌ If it was allocated with new[]
// }

// int main()
// {
//     // case1,case2,case3
//     // Rectangular rect(3);

//     // new → allocates a single object
//     // new[] → allocates an array of objects

//     // case 4
//     // int *arr = new int[10];
//     // cleanup(arr);

//     // case 5
//     // int *arr = (int *)malloc(10 * sizeof(int));
//     // delete[] arr; // ❌ Wrong, should use free()
// }

/*===================================================================*/
// case 5: Which order does the constructor initialize member variables in?
// class Test
// {
// public:
//     Test(int val) { cout << "Test(" << val << ")\n"; }
// };

// class MyClass
// {
//     Test t1;
//     Test t2;

// public:
//     MyClass() : t2(2), t1(1)
//     {
//         cout << "Constructor body\n";
//     }
// };

// int main()
// {
//     MyClass obj;
// }

/*===================================================================*/
// // case 6: The destructors for class member variables are called in the reverse order of construction.
// class A
// {
// public:
//     A() { cout << "A constructed\n"; }
//     ~A() { cout << "A destroyed\n"; }
// };

// class B
// {
// public:
//     B() { cout << "B constructed\n"; }
//     ~B() { cout << "B destroyed\n"; }
// };

// class MyClass
// {
//     A a;
//     B b;

// public:
//     MyClass() { cout << "MyClass constructed\n"; }
//     ~MyClass() { cout << "MyClass destroyed\n"; }
// };

// int main()
// {
//     MyClass object;
// }

/*===================================================================*/
// class ClassA
// {
// public:
//     ClassA() { cout << "ClassA Constructor... \n"; }
//     ~ClassA() { cout << "ClassA Destructor... \n"; }
// };

// class ClassB
// {
// private:
//     ClassA aa; // will be called first with each creation from ClassB
//     int x;

// public:
//     ClassB() { cout << "ClassB Destructor... \n"; }

//     ClassB(int x)
//     {
//         cout << "ClassB Constructor...\n";
//         this->aa = ClassA(); // so creation from ClassB will lead to create two objects from ClassA
//         this->x = x;
//     }

//     ~ClassB() { cout << "ClassB Destructor...\n"; }
// };

// class ClassC
// {
// private:
//     int &y;

//     // 1. it's not by reference so will be create new object from ClassB.
//     // 2. But the question now "Will lead to construct new object from ClassA?"
//     // No won't be made that. Will lead to create new objet and use default copy constructor and make bitwise copying from the passing
//     // argument to this object in private section.
//     // and will be destruct already with going out of scoop.
// ClassB bb; // there's no default constructor to call for ClassB so will give you compilar error if isn't init with "initializer list"

// public:
// note each coming constructor is testcase individual.

// // will call default constructor for ClassB so will lead to call ClassA constructor one more time.
// ClassC(int &y) : y(y) {}

// when create object from ClassC will make:
// 1. argument passing by reference so won't be create object for argument.
// 2. will lead to create object for private section if isn't with reference and make bitwise copying using default copy constructor.
//    if ClassB object in private section was with reference will lead to no creation for it and use only reference.
// ClassC(int &y, const ClassB &bb) : y(y), bb(bb)
// {
//     // ClassB won't be created for this constructor call because of reference calling for argument passing but may lead to private section
//     // object creation if isn't with reference.
// }

// // compilar issue because of y reference isn't initialized yet in "initializer list".
// ClassC(const ClassB bb) : bb(bb)
// {
// }

// // 1. will create new object from ClassB to this argument and use bitwise copying for copy constructor and will be destruct after the list line
// //    in this constructor scoop..
// // 2. will lead to another object from ClassB in private section if isn't with reference.
// ClassC(int &y, const ClassB bb) : y(y), bb(bb)
// {
//     cout << "ClassC Constructor\n";
// }
// };

// int main()
// {
//     int hello = 10;
//     ClassB b(5); // will construct object from B.

//     {
//         cout << "enter new scoope...\n";
//         ClassC cc(hello, b);
//         cout << "exit scoope...\n";
//     }

//     cout << "before exit main...\n";
// }

/*===================================================================*/
// // example on method chaining.
// #include <iostream>
// using namespace std;

// class Time
// {
// private:
//     int hours;
//     int minutes;
//     int seconds;

// public:
//     // Constructor
//     Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

//     // Method chaining: setters return reference to *this
//     Time &SetHours(int h)
//     {
//         hours = h;
//         return *this;
//     }

//     Time &SetMinutes(int m)
//     {
//         minutes = m;
//         return *this;
//     }

//     Time &SetSeconds(int s)
//     {
//         seconds = s;
//         return *this;
//     }

//     // Print function to check result
//     void Print() const
//     {
//         cout << "Time: "
//              << (hours < 10 ? "0" : "") << hours << ":"
//              << (minutes < 10 ? "0" : "") << minutes << ":"
//              << (seconds < 10 ? "0" : "") << seconds << endl;
//     }
// };

// int main()
// {
//     Time t;

//     // Method chaining
//     t.SetHours(9).SetMinutes(5).SetSeconds(30);

//     // Print final result
//     t.Print(); // Output: Time: 09:05:30

//     return 0;
// }

/*===================================================================*/
// // case: say what's the output?
// class A
// {
// private:
//     int *x;

// public:
//     A()
//     {
//         cout << "A Constructor ...\n";
//         x = new int;
//         *x = 10;
//     }

//     ~A()
//     {
//         cout << "A Destructor ...\n";
//     }
// };

// int main()
// {
//     A *a = new A();
// }

// /*===================================================================*/
// class MyClass
// {
// private:
//     int *value1;
//     int value2;

// public:
//     MyClass(int val1 = 3, int val2 = 8)
//     {
//         value1 = new int;
//         *value1 = val1;
//         value2 = val2;
//     }

//     // Copy Constructor (Deep Copy)
//     MyClass(const MyClass &other)
//     {
//         value1 = new int(*(other.value1)); // allocate new memory and copy value
//         value2 = other.value2;
//         cout << "Copy constructor called\n";
//     }

//     // Assignment-like operator (not conventional, better use operator=)
//     MyClass operator()(MyClass &other)
//     {
//         if (this != &other)
//         {
//             delete value1;                     // Free old memory
//             value1 = new int(*(other.value1)); // Deep copy
//             value2 = other.value2;
//         }
//         return *this;
//     }

//     // Assignment-like operator (not conventional, better use operator=)
//     MyClass operator=(MyClass &other)
//     {
//         if (this != &other)
//         {
//             delete value1;                     // Free old memory
//             value1 = new int(*(other.value1)); // Deep copy
//             value2 = other.value2;
//         }
//         return *this;
//     }

//     ~MyClass()
//     {
//         delete (value1);
//     }

//     void PrintValueAndAdress()
//     {
//         cout << "val1: " << *value1 << " address: " << value1 << "\n";
//         cout << "val2: " << value2 << " address: " << &value2 << "\n\n\n";
//     }
// };

// int main()
// {
//     MyClass a;
//     MyClass b(10, 20);

//     cout << "--- Initial Values ---\n";
//     a.PrintValueAndAdress();
//     b.PrintValueAndAdress();

//     cout << "--- Assign b = a using operator() ---\n";
//     b(a); // custom assignment-like call
//     b.PrintValueAndAdress();

//     cout << "--- Assign b = a using operator= ---\n";
//     b = a; // custom assignment-like call
//     b.PrintValueAndAdress();

//     cout << "--- Copy Construct c from a ---\n";
//     MyClass c = a;
//     MyClass d(a);
//     c.PrintValueAndAdress();
//     d.PrintValueAndAdress();
// }

/*===================================================================*/
// // Temporary Object.
// class MyClass
// {
// private:
//     int value2;

// public:
//     // Constructor
//     MyClass(int val1 = 3, int val2 = 8)
//     {
//         cout << "Constructor is called....\n";
//         value2 = val2;
//     }

//     // Copy Constructor
//     MyClass(const MyClass &other)
//     {
//         cout << "Copy constructor is called....\n";
//         value2 = other.value2;
//     }

//     // Destructor
//     ~MyClass()
//     {
//         cout << "Destructor is called\n";
//     }

//     // Set value
//     void SetValue2()
//     {
//         value2 = 10;
//     }

//     // Print value
//     void getValue2() const
//     {
//         cout << "value2 = " << value2 << "\n";
//     }
// };

// // Pass by value → copy constructor will be called
// void player1(MyClass a)
// {
//     cout << "Inside player1 function...\n";
// }

// // Pass by reference → no copy
// void player2(MyClass &a)
// {
//     cout << "Inside player2 function...\n";
//     a.SetValue2(); // modifies original
// }

// // Pass by const reference → safe read-only access
// void player3(const MyClass &a)
// {
//     cout << "Inside player3 function...\n";
//     // a.SetValue2(); // Not allowed because a is const
// }

// // Return by value → copy constructor may be called or optimized (RVO/NRVO)
// MyClass player4()
// {
//     cout << "Inside player4...\n";
//     cout << "Creating x\n";
//     MyClass x;
//     cout << "Created x\n";
//     return x;
// }

// int main()
// {
//     cout << "Create x...\n";
//     MyClass x;

//     cout << "\nCall player1 (by value)...\n";
//     player1(x); // Copy constructor is called, Yes, a temporary object is created here

//     cout << "\nCall player2 (by reference)...\n";
//     player2(x);    // No copy, No temporary object is created here.
//     x.getValue2(); // Shows that it was modified

//     cout << "\nCall player3 (by const reference)...\n";
//     player3(x); // No copy and no modification,  No temporary object is created here.

//     cout << "\nCall player4 (returns by value)...\n";
//     MyClass ret = player4();

//     player3(ret);

//     cout << "before exit main()\n";
// }

/*===================================================================*/
// // what will you see ?
// // and what's the oop violation in this case ?
// class ClassA
// {
// private:
//     int value1;
//     int *val;

// public:
//     ClassA(int v)
//     {
//         val = new int(v);
//     }
//     ~ClassA()
//     {
//         delete val;
//     }

//     void SetVal(int *v)
//     {
//         this->val = v;
//     }

//     int *getVal()
//     {
//         return val;
//     }

//     // Encapsulation voilation becasue of ability to change in private variable directly.
//     // Callers can modify length directly without using a setter or any validation.
//     int &getvalue1()
//     {
//     }

//     // Safer alternative
//     const int &getLength() const
//     {
//     }
// };

// int main()
// {
//     ClassA a1(10);
//     ClassA a2(20);
//     cout << "a1 address: " << a1.getVal() << "\n";
//     cout << "a2 address: " << a2.getVal() << "\n";

//     a2.SetVal(a1.getVal());
//     cout << "a2 address: " << a2.getVal() << "\n";
// }

/*===================================================================*/
// get the bug and RTE
// void print1(string &s)
// {
// }

// void print2(const string &s)
// {
// }

// string msg1()
// {
//     string x = "aa";
//     return x;
// }

// const string &msg2()
// {
//     return "aa";
// }

// const string &msg3()
// {
//     string x = "aa";
//     return x;
// }

// int main()
// {
//     string hello("Hello");

//     print1(hello);
//     // print1(string("World"));
//     // print1("!");

//     print2(hello);
//     print2(string("World"));
//     print2("!");

//     string a1 = msg1();
//     string a2 = msg1();
//     const string a3 = msg1();

//     string a = msg3();
//     string b = msg3();

//     return 0;
// }

// /*===================================================================*/
class Solution
{
private:
    string str;
    int CountPT(int idx, string s)
    {
        // base case
        if (s.size() == 3 && s[0] == s[2])
            return 1;

        if (idx == str.size() || s.size() == 3)
            return 0;

        // transitions
        int take = CountPT(idx + 1, s + str[idx]);
        int leave = CountPT(idx + 1, s);
        return (leave + take);
    }

public:
    int CPT(string s)
    {
        str = s;
        return CountPT(0, "");
    }
};

int main()
{
    Solution sol;
    cout << sol.CPT("abcbac") << "\n";
}