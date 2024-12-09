/*
// function pointer
#include <iostream>
#include <thread>

void task() {
    std::cout << "Thread is running.\n";
}

int main() {
    std::thread t(task); // Create a thread using a function pointer
    t.join(); // Wait for the thread to finish
    return 0;
}
*/

/*
// lambda function
#include <iostream>
#include <thread>

int main() {
    std::thread t([] {
        std::cout << "Thread running using lambda function.\n";
    });
    t.join(); // Wait for the thread to complete
    return 0;
}
*/

/*
// functor
#include <iostream>
#include <thread>

class Base
{
public:
    void operator()(int x) const
    {
        std::cout << "Thread running using a functor: " << x << "\n";
    }
};

int main()
{
    Base functor;
    std::thread t(Base(), 10); // Create thread using a functor
    t.join();
    return 0;
}*/

/*
// Non static Member Functions
#include <iostream>
#include <thread>

class MyClass {
public:
    void task() {
        std::cout << "Thread running using a member function.\n";
    }
};

int main() {
    MyClass obj;
    std::thread t(&MyClass::task, &obj); // Pass object and member function pointer
    t.join();
    return 0;
}
*/

// Static Member Functions
#include <iostream>
#include <thread>

class MyClass
{
public:
    static void task()
    {
        std::cout << "Thread running using a static member function.\n";
    }
};

int main()
{
    std::thread t(&MyClass::task); // Static member functions can be called directly
    t.join();
    return 0;
}
