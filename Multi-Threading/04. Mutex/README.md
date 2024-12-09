# **Understanding Mutex in C++ Threading**

This document provides an overview of the concepts of **Mutex**, **Race Condition**, and **Critical Section** in C++ threading, along with practical examples.

---

## **1. Race Condition**

### **Definition**
- A race condition occurs when two or more threads/processes access and modify a shared resource simultaneously, leading to unpredictable results.

### **Key Notes**
1. Race conditions can cause data corruption or unexpected behavior in multi-threaded programs.
2. To resolve a race condition, the shared resource must be protected.
3. The protected area where the shared resource is accessed is referred to as the **Critical Section**.
---

## **2. Mutex (Mutual Exclusion)**

### **Definition**
- A **Mutex** is a synchronization mechanism used to protect shared resources from being simultaneously accessed by multiple threads.

### **How It Works**
1. The `lock()` function acquires a lock on the mutex, granting thread-exclusive access to the critical section.
2. The `unlock()` function releases the lock, allowing other threads to access the critical section.

---

## **3. Example: Solving Race Condition with Mutex**

Here’s an example illustrating how to use a mutex to protect shared resources and prevent a race condition:

### **Code Example**
```cpp
#include <iostream>
#include <thread>
#include <mutex>

int sharedCounter = 0;  // Shared resource
std::mutex mtx;         // Mutex to protect sharedCounter

void increment(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        mtx.lock(); // Lock the mutex
        ++sharedCounter; // Critical section
        mtx.unlock(); // Unlock the mutex
    }
}

int main() {
    const int iterations = 100000;

    std::thread t1(increment, iterations);
    std::thread t2(increment, iterations);

    t1.join();
    t2.join();

    std::cout << "Final value of sharedCounter: " << sharedCounter << std::endl;
    return 0;
}
```

### Output Without Mutex
Without a mutex, the output may vary due to race conditions, for example:
```sql
Final value of sharedCounter: 157834
```

### Output With Mutex
```sql
Final value of sharedCounter: 200000
```

## **4. Key Notes**
- The **Critical Section** refers to the part of the program where shared resources are accessed.
- A Mutex ensures that only one thread can access the critical section at any given time.
- Improper use of lock() and unlock() can lead to deadlocks, where threads wait indefinitely for a resource to be released.

## **5. When to Use Mutex**
- Use mutexes whenever there are shared resources in a multi-threaded program.
- Mutexes are essential in applications where data consistency is critical, such as financial transactions or multi-threaded data processing.