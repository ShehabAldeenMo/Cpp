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
    stack(int size = 10) : tos(0), size(size)
    {
        NumOfStacks++;
        array = new int[size];
    }

    // copy constructor
    stack(stack &z)
    {
        tos = z.tos;
        size = z.size;
        array = new int[size];
        for (int i = 0; i <= tos; i++)
            array[i] = z.array[i];
        NumOfStacks++;
    }

    ~stack()
    {
        NumOfStacks--;
        delete[] array;
        std::cout << "This is the destructor\n";
    }

    void operator=(stack s);
    void push(int);
    int pop(void);
    int getNumOfStacks();
    friend void viewContent(stack s);
};

void stack::operator=(stack s) // this-> caller S1, that-> argument S2
{
    delete this->array;            // remove the old version of your array
    this->tos = s.tos;             // copy the remaining stacks
    this->array = new int[size];   // create new array
    for (int i = 0; i < size; i++) // coping values
        array[i] = s.array[i];
}

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

/* will lead to bitwise copying and dynamic area memory
    1.call by reference
 */
void viewContent(stack s)
{
    int t = s.tos;
    while (t != 0)
    {
        std::cout << s.array[t] << "\n";
        t--;
    }
}

// Preferred to use with class name rather than object
int stack::NumOfStacks = 0;

int main()
{
    stack S1(20);
    S1.push(5);
    S1.push(8);
    S1.push(14);
    /*
    By tracing you will find that call by value will make a copy object with copy constructor. at the end
    of viewContent function will delete this object ?
    Trace and make case one will find that the destructor is already called because it's just a copied version from object
     */
    viewContent(S1);
    std::cout << "S1 pop : " << S1.pop() << "\n";
    stack S2;
    S2.push(44);
    viewContent(S1);
    S2 = S1;
    viewContent(S2);
    std::cout << "Number Of Stacks are :" << S1.getNumOfStacks() << "\n";
    return 0;
}