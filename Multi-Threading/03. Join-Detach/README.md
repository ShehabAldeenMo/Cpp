# **Use of `join()`, `detach()`, and `joinable()` in Threads (C++11)**

This document explains the purpose and usage of `join()`, `detach()`, and `joinable()` functions when working with threads in C++11, along with key points and examples.

---

## **1. join()**

### **Purpose**
- Waits for a thread to complete its execution before proceeding.
- Ensures that the parent thread synchronizes with the child thread.

### **Notes**
1. Once a thread is started, calling `join()` blocks the calling thread until the associated thread finishes execution.
2. **Double Join**: Attempting to call `join()` more than once on the same thread object results in program termination.
3. Before calling `join()`, it's a good practice to check if the thread is joinable using the `joinable()` function.

### **Example**
```cpp
#include <iostream>
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
}
```

## **2. detach()**

### **Purpose**
- Detaches the thread from the parent thread, allowing it to run independently.
- The detached thread continues execution even if the main thread terminates.

### **Notes**
1. Always ensure a thread is joinable before detaching it to avoid double detachment, which results in program termination.
2. If a thread is detached and the main thread finishes, the detached thread is suspended and may not complete execution.

```cpp
#include <iostream>
#include <thread>
#include <chrono>

void task() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Detached thread task completed.\n";
}

int main() {
    std::thread t(task); // Create a thread
    if (t.joinable()) {
        t.detach(); // Detach the thread
    }
    std::cout << "Main thread finished.\n";
    return 0; // Detached thread execution may suspend if main finishes
}
```

## 3. joinable()

### Purpose
- Checks whether a thread is joinable (i.e., eligible for join() or detach()).

### Notes
1. A thread is joinable if it has been started and not yet joined or detached.
2. Always check if a thread is joinable before calling join() or detach() to prevent program errors.

## Important Notes
- Call `join()` or `detach()` : It is mandatory to call either `join()` or `detach()` on a thread object.
    - Failing to do so results in program termination during the thread object's destructor.
    - Example of problematic code:
```cpp
void task() { /* Do something */ }
std::thread t(task); // If neither t.join() nor t.detach() is called, program terminates.
```

# **Comparison of `join()` and `detach()`**

| **Feature**         | **`join()`**                                   | **`detach()`**                                |
|----------------------|-----------------------------------------------|-----------------------------------------------|
| **Purpose**          | Synchronize with thread execution            | Let thread run independently                 |
| **Blocking**         | Yes                                           | No                                            |
| **Ownership**        | Thread object retains ownership               | Thread is disassociated from thread object    |
| **Destruction**      | Safe to destroy thread object after join      | Safe, but detached thread is suspended if main exits |


