
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Function to simulate work
int performTask(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate workload
    return a + b;
}

int main()
{
    // Using std::launch::async
    auto asyncTask = std::async(std::launch::async, performTask, 10, 20);
    std::cout << "Asynchronous task launched.\n";

    // Using std::launch::deferred
    auto deferredTask = std::async(std::launch::deferred, performTask, 30, 40);
    std::cout << "Deferred task created.\n";

    // Access the results
    std::cout << "Waiting for async task result...\n";
    std::cout << "Async Task Result: " << asyncTask.get() << "\n";

    std::cout << "Waiting for deferred task result...\n";
    std::cout << "Deferred Task Result: " << deferredTask.get() << "\n";

    return 0;
}

/*
Key Points:
1. Asynchronous vs. Synchronous:
With std::launch::async, the task runs in parallel.
With std::launch::deferred, the task executes only when the result is explicitly requested.

2. Control Over Task Execution:
You can specify the launch policy to optimize resource utilization and execution behavior.

3. Thread Safety and Synchronization:
std::async ensures that results are safely retrieved using the associated std::future object.

4. Automatic Thread Management:
With std::async, you don’t need to explicitly manage threads, simplifying concurrent programming.
*/