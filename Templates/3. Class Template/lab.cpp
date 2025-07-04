#include <iostream>
#include <string>

using namespace std;

template <typename T>
class ClassName
{
private:
    T value;

public:
    ClassName(T val) { value = val; }
    void PrintValue()
    {
        cout << "value: " << value << "\n";
    }
};

int main()
{
    ClassName inst1("shehab");
    inst1.PrintValue();
    ClassName inst2(589);
    inst2.PrintValue();
}