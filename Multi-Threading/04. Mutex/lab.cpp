#include <iostream>
#include <thread>
#include <mutex>

int sharedCounter = 0; // Shared resource
std::mutex mtx;        // Mutex to protect sharedCounter

void increment(int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        // mtx.lock();      // Lock the mutex
        ++sharedCounter; // Critical section
        // mtx.unlock();    // Unlock the mutex
    }
}

int main()
{
    const int iterations = 100000;

    std::thread t1(increment, iterations);
    std::thread t2(increment, iterations);

    if (t1.joinable())
    {
        t1.join();
    }

    if (t2.joinable())
    {
        t2.join();
    }

    std::cout << "Final value of sharedCounter: " << sharedCounter << std::endl;
    return 0;
}