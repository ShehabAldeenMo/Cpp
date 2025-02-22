## Condition Variables in C++ Threading

Condition variables are a powerful synchronization mechanism in C++ for managing thread communication. They allow running threads to wait for specific conditions or signal other threads when certain criteria are met.

---

### Key Points to Remember

1. **Synchronization via Notifications**  
   Condition variables allow running threads to synchronize using notifications:
   - **`notify_one()`**: Wakes up one thread waiting on the condition variable.
   - **`notify_all()`**: Wakes up all threads waiting on the condition variable.

2. **Mutex Dependency**  
   A mutex is required to use a condition variable, ensuring thread-safe access to shared resources.

3. **Thread Synchronization**  
   Condition variables are ideal for synchronizing two or more threads efficiently. If some thread wants to wait on some condition then it has to do these things:<br />
   3.1 Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);<br />
   3.2 Execute wait(), wait_for(), or wait_until(). The wait operations atomically **release** the mutex and **suspend** the execution of the thread.<br />
   3.3 condition variable is notified, the thread is **awakened**, and the mutex is atomically **reacquired**. The thread should then check the condition and may resume waiting if the wake up was spurious (fake wake up).<br />

4. **Best Use Case**  
   The producer-consumer problem is a common scenario where condition variables are used to manage shared resources and ensure proper synchronization.

5. **Two Main Purposes**  
   - **Notify other threads**: Signal threads when a condition is met.
   - **Wait for some condition**: Block threads until the condition becomes true.

---
