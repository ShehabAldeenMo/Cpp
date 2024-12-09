// Example Usage of `try_lock_for()` with `std::timed_mutex`

/*#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::timed_mutex timedMutex;

void threadFunction(int i)
{
    // Try to lock for 1 second and 2 seconds
    // in case of 1 second leads thread 2 to enter if
    // but in case of 2 seconds leads thread 2 to enter else
    if (timedMutex.try_lock_for(std::chrono::seconds(2)))
    {
        std::cout << "Lock acquired by thread " << i << "\n";

        // Try to lock for 2 second and 1 seconds
        // in case of 2 second leads thread 1 to operate much time and prevent thread 2 from entering
        // but in case of 1 seconds leads thread 2 to enter the same part of if condition
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulating work
        timedMutex.unlock();
    }
    else
    {
        std::cout << "Failed to acquire lock, timed out in thread " << i << "\n";
    }
}

int main()
{
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);

    t1.join();
    t2.join();

    return 0;
}*/

// Example Usage of `try_lock_until()` with `std::timed_mutex`
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::timed_mutex myMutex;

void attempt_lock_until(int x)
{
    using namespace std::chrono;

    // Get the current time and add 2 seconds to it
    auto timeout = steady_clock::now() + seconds(2);

    // Try to lock until the specified time point
    if (myMutex.try_lock_until(timeout))
    {
        std::cout << "Thread successfully acquired the lock.\n";
        // Simulate some work
        std::this_thread::sleep_for(seconds(1));
        myMutex.unlock(); // Unlock the mutex after work is done
        std::cout << "Thread " << x << " released the lock.\n";
    }
    else
    {
        std::cout << "Thread " << x << " could not acquire the lock before timeout.\n";
    }
}

int main()
{
    std::thread t1(attempt_lock_until, 1);
    std::thread t2(attempt_lock_until, 2);

    t1.join();
    t2.join();

    return 0;
}
