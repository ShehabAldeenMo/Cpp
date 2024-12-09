#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;

void tryLockExample()
{
    if (mtx.try_lock())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Thread " << std::this_thread::get_id() << " acquired the lock.\n";
        mtx.unlock();
    }
    else
    {
        std::cout << "Thread " << std::this_thread::get_id() << " could not acquire the lock.\n";
    }
}

int main()
{
    std::thread t1(tryLockExample);
    std::thread t2(tryLockExample);

    t1.join();
    t2.join();

    return 0;
}