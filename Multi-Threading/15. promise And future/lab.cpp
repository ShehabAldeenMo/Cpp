#include <iostream>
#include <thread>
#include <future>

// Function to perform work in a separate thread
void worker(std::promise<int> promiseObj)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    promiseObj.set_value(42);                             // Set result in promise
}

int main()
{
    // Create a promise and its corresponding future
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();

    // Launch a worker thread with the promise
    std::thread t(worker, std::move(promiseObj));

    // Wait for the result in the main thread
    std::cout << "Waiting for result..." << std::endl;
    int result = futureObj.get(); // Retrieve result
    std::cout << "Result received: " << result << std::endl;

    // Join the worker thread
    t.join();

    return 0;
}

/*
Key Points:
1. Data Transfer:
std::promise is used to send data from the worker thread to the calling thread.
std::future retrieves the data in a synchronized manner.

2.Thread Safety:
std::promise and std::future ensure safe communication between threads.

3. Exception Handling:
If an exception is set in the std::promise, it can be retrieved and handled in the std::future.

4. Flexibility:
Enables fine-grained control over thread synchronization and data sharing.
*/