#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;

void sleepExample()
{
    std::lock_guard<std::mutex> lock(mtx); // Locking mutex
    std::cout << "Thread starting sleep...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Sleep for 2 seconds
    std::cout << "Thread woke up after sleep.\n";
}

int main()
{
    std::thread t(sleepExample);
    t.join(); // Wait for the thread to finish
    return 0;
}
