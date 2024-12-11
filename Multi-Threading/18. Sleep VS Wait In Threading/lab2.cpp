#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void waitExample()
{
    std::unique_lock<std::mutex> lock(mtx); // Lock mutex
    while (!ready)
    { // Loop to avoid spurious wakeups
        std::cout << "Thread is waiting...\n";
        cv.wait(lock); // Wait and release lock
    }
    std::cout << "Thread resumed after being notified.\n";
}

void notifyExample()
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    std::cout << "Notifying waiting thread...\n";
    cv.notify_one(); // Notify one waiting thread
}

int main()
{
    std::thread t1(waitExample);   // Wait thread
    std::thread t2(notifyExample); // Notify thread

    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish
    return 0;
}
