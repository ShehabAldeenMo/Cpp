#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex1, mutex2;

void threadFunction()
{
    auto ret = std::try_lock(mutex1, mutex2);
    if (ret == -1)
    {
        std::cout << "Thread" << std::this_thread::get_id() << "\n";
        std::cout << "Successfully locked both mutexes.\n";
        // Perform critical section tasks.
        mutex1.unlock();
        mutex2.unlock();
    }
    else
    {
        std::cout << "Thread" << std::this_thread::get_id() << "\n";
        std::cout << "Failed to lock one or more mutexes." << ret << "\n";
    }
}

int main()
{
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);

    t1.join();
    t2.join();

    return 0;
}