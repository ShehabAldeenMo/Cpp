#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_numbers(int x)
{
    {
        std::lock_guard<std::mutex> lock(mtx); // Locks the mutex
        std::cout << "thread: " << x << "\n";
        for (int i = 1; i <= 5; ++i)
        {
            std::cout << i << " ";
        }
    }
    std::cout << "Mutex will be automatically unlocked when lock goes out of scope \n";
}

int main()
{
    std::thread t1(print_numbers, 1);
    std::thread t2(print_numbers, 2);

    t1.join();
    t2.join();

    return 0;
}
