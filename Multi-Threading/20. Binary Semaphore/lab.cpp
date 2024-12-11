#include <iostream>
#include <thread>
#include <semaphore>

std::binary_semaphore semaphore1{0}, semaphore2{0}; // Initial state: Locked (0)

void producer()
{
    std::cout << "Producer: Preparing resource...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulating work
    std::cout << "Producer: Resource ready!\n";
    semaphore1.release(); // Signal (unlock)
    std::cout << "Producer: Waiting signaling for refilling resource...\n";
    semaphore1.acquire(); // Wait (lock)
    std::cout << "Producer: Preparing resource...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulating work
    std::cout << "Producer: Resource ready!\n";
}

void consumer()
{
    std::cout << "Consumer: Waiting for resource...\n";
    semaphore1.acquire(); // Wait (lock)
    std::cout << "Consumer: Resource acquired!\n";
    std::cout << "Consumer: Signaling Producer to resume working\n";
    semaphore2.release();
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}