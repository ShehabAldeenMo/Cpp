/*#include <iostream>
#include <thread>

void task() {
    std::cout << "Thread task is running.\n";
}

int main() {
    std::thread t(task); // Create a thread
    if (t.joinable()) {
        t.join(); // Wait for the thread to complete
    }
    return 0;
}*/

#include <iostream>
#include <thread>
#include <chrono>

void task()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Detached thread task completed.\n";
}

int main()
{
    std::thread t(task); // Create a thread
    if (t.joinable())
    {
        t.detach(); // Detach the thread
    }
    std::cout << "Main thread finished.\n";
    return 0; // Detached thread execution may suspend if main finishes
}