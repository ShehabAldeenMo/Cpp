#include <iostream>

void firstExample()
{
    int *ptr = new int(10); // Dynamically allocate memory
    std::cout << "Value: " << *ptr << std::endl;

    // Forget to free the memory!
    // No "delete ptr;" here

    // Memory is leaked, and it's never freed.
}

void secondExample()
{
    int *ptr = new int(20); // Allocate memory
    std::cout << "Value: " << *ptr << std::endl;

    delete ptr; // First delete (correct)

    // Accessing memory after deleting it (use-after-free)
    std::cout << "Trying to access freed memory: " << *ptr << std::endl; // Undefined behavior

    delete ptr; // Second delete (double-delete)
}

int main()
{
    firstExample();
    // Program will finish without crashing, but memory leak happens silently.
    // In larger programs, continuous memory allocation without deallocation
    // will eventually exhaust available memory.
    secondExample();
    return 0;
}