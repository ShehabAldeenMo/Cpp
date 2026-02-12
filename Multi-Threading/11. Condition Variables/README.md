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

# Why `unique_lock` in `withdrowMoney()`?

Because of this line:

```cpp
cv.wait(ul, [] { return (balance != 0); });
```

### Important:

`std::condition_variable::wait()` **requires a `std::unique_lock<std::mutex>`**.

Why?

Because `wait()` must:

1. **Unlock the mutex**
2. Put the thread to sleep
3. When notified → wake up
4. **Re-lock the mutex before returning**

That means the lock must support:

* manual unlock
* manual relock

* `std::lock_guard` **cannot do that**
* `std::unique_lock` **can do that**

That’s the key reason.

---

### What actually happens inside `wait()`?

Conceptually:

```cpp
while (!predicate()) {
    ul.unlock();
    sleep();
    ul.lock();
}
```

Only `unique_lock` supports `unlock()` and `lock()` operations.

---

# Why `lock_guard` in `addMoney()`?

In `addMoney()`:

```cpp
std::lock_guard<std::mutex> lg(n);
balance += money;
cv.notify_one();
```

We:

* Lock
* Modify shared data
* Notify
* Automatically unlock at scope end

We **never need to manually unlock and relock**, so:

   `lock_guard` is perfect
   It's simpler
   Slightly faster
   Cannot be misused

---

# 🔹 So what is the difference?

| Feature                        | lock_guard | unique_lock      |
| ------------------------------ | ---------- | ---------------- |
| RAII locking                   | ✅          | ✅                |
| Manual unlock                  | ❌          | ✅                |
| Manual relock                  | ❌          | ✅                |
| Required by condition_variable | ❌          | ✅                |
| Lightweight                    | ✅          | Slightly heavier |

---

# Could we use `unique_lock` in both?

Yes

This would also work:

```cpp
std::unique_lock<std::mutex> ul(n);
```

But it’s unnecessary in `addMoney()` since we don’t need the extra features.

Best practice:

* Use **lock_guard** when simple locking is enough
* Use **unique_lock** when:

  * Using condition_variable
  * Need manual unlock/relock
  * Need deferred locking
  * Need try_lock
