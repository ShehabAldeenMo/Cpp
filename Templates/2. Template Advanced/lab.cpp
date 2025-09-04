#include <iostream>
#include <string>

using namespace std;

// Empty Pack
void print()
{
    cout << "\n";
}

template <typename T, typename... args>
void print(T first, args... rest)
{
    cout << first << " ";
    print(rest...);
}

// Implementation with Tail Recursion
template <typename T>
void Process(T first)
{
    cout << first << "\n";
}

template <typename T, typename... Args>
void Process(T first, Args... rest)
{
    cout << first << " ";
    Process(rest...);
}

// Left fold
template <typename... Args>
auto Sum(Args... args)
{
    return (args + ...); // Left fold
}

int main()
{
    print("shehab", "aldeen", "mohammed");
    Process("shehab", "aldeen", "mohammed");
    cout << Sum(1, 2, 3, 4, 5) << endl;
}