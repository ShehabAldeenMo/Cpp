#include <iostream>
#include <string>
#include <assert.h>
#include <type_traits>

using namespace std;

template <typename T>
class Box
{
private:
    T first;

public:
    void print()
    {
        cout << "T is: " << typeid(first).name() << "\n";
    }
};

template <typename T>
class SafeBox
{
    T value;

public:
    SafeBox(T v)
    {
        assert(v >= 0 && "Precondition: Value must be non-negative.");
        value = v;
        assert(value >= 0 && "Invariant: Value must remain non-negative.");
    }

    void setValue(T v)
    {
        assert(v >= 0 && "Precondition: Value must be non-negative.");
        value = v;
    }

    T getValue() const
    {
        assert(value >= 0 && "Invariant: Value must remain non-negative.");
        return value;
    }
};

template <typename T>
void checkType(T arg)
{
    if constexpr (std::is_same<T, int>::value)
        cout << "Type is int\n";
    else if constexpr (std::is_same<T, double>::value)
        cout << "Type is double\n";
    else
        cout << "Unknown type\n";
}

int main()
{
    Box<int> b;
    b.print();

    SafeBox<int> box(5);
    cout << box.getValue() << endl;

    // Uncommenting below will violate contract
    // box.setValue(-1);

    checkType(10);   // int
    checkType(3.14); // double
    checkType('A');  // Unknown
}