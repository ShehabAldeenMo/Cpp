#include <stdio.h>
#include <iostream>
#include <string>

#define CALL_BY_REFERENCE 1
#define CALL_BY_VALUE 0

#define METHOD CALL_BY_REFERENCE

class stack
{
    int size;
    int *array;
    int tos;
    static int NumOfStacks;

public:
    stack(int size = 10) : size(size), tos(0) // default argument
    {
        NumOfStacks++;
        array = new int[size];
    }
#if METHOD == CALL_BY_VALUE
    stack(stack &z) // passing two parameters this:new one, z:old one
    {
        tos = z.tos;
        size = z.size;
        array = new int[size];
        for (int i = 0; i <= tos; i++)
        {
            array[i] = z.array[i];
        }
        NumOfStacks++;
    }
#endif
    ~stack()
    {
        NumOfStacks--;
        delete[] array;
        std::cout << "This is the destructor\n";
    }
    void push(int);
    int pop(void);
    int getNumOfStacks();
#if METHOD == CALL_BY_REFERENCE
    friend void viewContent(stack &s);
#endif

#if METHOD == CALL_BY_VALUE
    friend void viewContent(stack s);
#endif
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

#if METHOD == CALL_BY_REFERENCE
/* will lead to bitwise copying and dynamic area memory
    1.call by reference
 */
void viewContent(stack &s)
{
    int t = s.tos;
    while (t != 0)
    {
        std::cout << s.array[t] << "\n";
        t--;
    }
}
#endif

#if METHOD == CALL_BY_VALUE
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
#endif

// Preferred to use with class name rather than object
int stack::NumOfStacks = 0;

int main()
{
    stack S1(20);
    S1.push(5);
    S1.push(8);
    S1.push(14);
#if METHOD == CALL_BY_REFERENCE
    /*
    By tracing you will find that call by reference make only pointer to this object and at the end
    of viewContent function will delete this refernce only not the object ?
    Trace and make case one will find that the destructor isn't called already because it's just a reference
    */
    viewContent(S1);
#endif

#if METHOD == CALL_BY_VALUE
    /*
    By tracing you will find that call by value will make a copy object with copy constructor. at the end
    of viewContent function will delete this object ?
    Trace and make case one will find that the destructor is already called because it's just a copyed version from object
     */
    viewContent(S1);
#endif

    std::cout << "S1 pop : " << S1.pop() << "\n";
    stack S2;
    S2.push(85);
    std::cout << "Number Of Stacks are :" << S1.getNumOfStacks() << "\n";
    return 0;
}