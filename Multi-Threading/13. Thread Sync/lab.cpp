#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for synchronization

void criticalFunction(int id)
{
    mtx.lock(); // Lock the mutex before entering the critical section
    std::cout << "Thread " << id << " is entering the critical section.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Thread " << id << " is leaving the critical section.\n";
    mtx.unlock(); // Unlock the mutex after leaving the critical section
}

int main()
{
    std::thread t1(criticalFunction, 1);
    std::thread t2(criticalFunction, 2);

    t1.join();
    t2.join();

    return 0;
}