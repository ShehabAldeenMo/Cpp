#include <iostream>
#include <string>

using namespace std;

void printname()
{
    cout << "\n";
}

template <typename T, typename... args>
void printname(T first, args... names)
{
    cout << first << "\n";
    cout << "Number of arguments: " << sizeof...(names) << " ";
    printname(names...);
}

template <typename... Args>
auto Sum(Args... args)
{
    return (args + ...); // Left fold
}

int main()
{
    printname("shehab", "aldeen", "mohammed");
    cout << Sum(1, 2, 3, 4, 5) << endl;
}