#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex mtx;

void recursive_lock(int depth)
{
    if (depth <= 0)
        return;

    // Lock the mutex at each level of recursion
    mtx.lock();
    std::cout << "Locking level " << depth << std::endl;

    // Recurse deeper
    recursive_lock(depth - 1);
    mtx.unlock();
    std::cout << "unlock: " << depth << "\n";
}

int main()
{
    std::thread t1(recursive_lock, 5);
    t1.join();
    return 0;
}
