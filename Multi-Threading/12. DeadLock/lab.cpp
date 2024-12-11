#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;

void thread1()
{
    mutex1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    mutex2.lock();
    std::cout << "Thread 1 is executed\n";
    mutex2.unlock();
    mutex1.unlock();
}

void thread2()
{
    mutex2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    mutex1.lock();
    std::cout << "Thread 2 is executed\n";
    mutex1.unlock();
    mutex2.unlock();
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
