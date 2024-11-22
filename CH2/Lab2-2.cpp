#include <stdio.h>
#include <iostream>
#include <string>

class stack
{
    int size;
    int *array;
    int tos;
    static int NumOfStacks;

public:
    stack(int size = 10)
    {
        NumOfStacks++;
        this->size = size;
        tos = 0;
        array = new int[size];
    }

    ~stack()
    {
        NumOfStacks--;
        delete[] array;
        std::cout << "This is the destructor\n";
    }
    void push(int);
    int pop(void);
    int getNumOfStacks();
};

void stack::push(int ele)
{
    if (tos == size - 1)
    {
        std::cout << "the array is full";
    }
    else
    {
        tos++;
        array[tos] = ele;
    }
}

int stack::pop(void)
{
    int ele = -1;

    if (tos == 0)
    {
        std::cout << "stack is empty";
    }
    else
    {
        ele = array[tos];
        tos--;
    }

    return ele;
}

int stack::getNumOfStacks()
{
    return NumOfStacks;
}

// Preferred to use with class name rather than object
int stack::NumOfStacks = 0;

int main()
{
    stack S1(20);
    S1.push(5);
    S1.push(8);
    S1.push(14);
    std::cout << "S1 pop : " << S1.pop() << "\n";
    stack S2;
    S2.push(85);
    std::cout << "Number Of Stacks are :" << S1.getNumOfStacks() << "\n";
    return 0;
}