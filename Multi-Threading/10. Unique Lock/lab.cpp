/*
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx;

void print_numbers(int x)
{
    std::unique_lock<std::mutex> obj(mtx, std::defer_lock); // No lock acquired yet: just make obj owns mtx
    std::cout << "thread " << x << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate some processing time
    obj.lock();                                           // Manually acquire the lock after some processing
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "thread " << x << " Finished\n";
}

int main()
{
    std::thread t1(print_numbers, 1);
    std::thread t2(print_numbers, 2);

    t1.join();
    t2.join();

    return 0;
}
*/

#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_numbers()
{
    // Lock the mutex explicitly in the first scope
    mtx.lock();

    // Now, in another scope, we use std::unique_lock with adopt_lock
    std::unique_lock<std::mutex> obj(mtx, std::adopt_lock);

    // This thread already holds the lock, so no need to lock it again.
    // Perform some operations
    std::cout << "Thread: " << std::this_thread::get_id() << " is printing numbers.\n";
    for (int i = 1; i <= 5; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // The lock will be released automatically when obj goes out of scope.
}

int main()
{
    std::thread t1(print_numbers);
    std::thread t2(print_numbers);

    t1.join();
    t2.join();

    return 0;
}
