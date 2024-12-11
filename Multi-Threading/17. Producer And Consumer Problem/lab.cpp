#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

const int BUFFER_SIZE = 50;
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;

void producer()
{
    int value = 0;
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
                { return buffer.size() < BUFFER_SIZE; }); // Wait if buffer is full

        buffer.push(value++);
        std::cout << "Produced: " << value - 1 << "\n";

        lock.unlock();
        cv.notify_one(); // Notify consumer
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
                { return !buffer.empty(); }); // Wait if buffer is empty

        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << item << "\n";

        lock.unlock();
        cv.notify_one(); // Notify producer
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main()
{
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
