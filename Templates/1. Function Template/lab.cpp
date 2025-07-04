#include <iostream>
#include <string>

using namespace std;

template <typename T>
void Swap_Values(T &arg1, T &arg2)
{
    T temp;
    temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

template <typename U>
U Add(U a, U b)
{
    return a + b;
}

template <typename U>
U Add1(U a, U b)
{
    return a + b;
}

// solve this issue by create auto return function
template <typename T1, typename T2>
auto Add2(T1 a, T2 b)
{
    return a + b;
}

template <typename T3>
void printname(T3 name)
{
    cout << "generic type\n";
}

template <>
void printname(string name)
{
    cout << "string type\n";
}

int main()
{
    string str1 = "shehab", str2 = "aldeen";
    Swap_Values(str1, str2);
    cout << "str1: " << str1 << ", str2: " << str2 << "\n";

    double d1 = 2.588, d2 = 8.54;
    Swap_Values(d1, d2);
    cout << "d1: " << d1 << ", d2: " << d2 << "\n";

    char ch1 = 'a', ch2 = 'b';
    Swap_Values<char>(ch1, ch2); // deduction in calling
    cout << "ch1: " << ch1 << ", ch2: " << ch2 << "\n";

    cout << Add(2.5, 4.5) << endl; // OK: Both double
    // cout << Add(3, 4.5) << endl;   // ❌ Error: Argument types are int and double, no common deduced type T

    printname(55);

    printname<string>("shehab");
}