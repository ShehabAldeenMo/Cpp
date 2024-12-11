#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2;

void thread1()
{
    std::lock(m1, m2); // Locks both mutexes safely
    std::cout << "Thread 1 has locked both mutexes.\n";
    m1.unlock();
    m2.unlock();
}

void thread2()
{
    std::lock(m2, m1); // Locks both mutexes safely, even in reverse order
    std::cout << "Thread 2 has locked both mutexes.\n";
    m2.unlock();
    m1.unlock();
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
