## Timed Mutex in C++ Threading (`std::timed_mutex`)

In this section, we will explore `std::timed_mutex`, an advanced type of mutex in C++ that adds the ability to specify a timeout duration when trying to acquire a lock.

---

### Key Points to Remember About `std::timed_mutex`

1. **Blocking Behavior**:
   - `std::timed_mutex` will block a thread until either:
     - The lock is acquired, or
     - The specified timeout period (`timeout_time`) has elapsed.
   - If the lock is acquired before the timeout, it returns `true`; otherwise, it returns `false`.

2. **Member Functions**:
   - **`lock()`**: Acquires the lock and blocks the calling thread indefinitely until the lock is available.
   - **`try_lock()`**: Tries to acquire the lock without blocking; returns `true` on success, `false` if the lock is already held.
   - **`try_lock_for()`**: Tries to acquire the lock for a specified duration (timeout). Returns `true` if successful, `false` if the timeout expires before the lock is acquired. *(This function distinguishes `std::timed_mutex` from `std::mutex`.)*
   - **`try_lock_until()`**: Similar to `try_lock_for()`, but the timeout is specified as a specific time point (e.g., using `std::chrono::steady_clock`).
   - **`unlock()`**: Releases the lock.


### Key Notes

- **Timeout Behavior**:
  - `try_lock_for()` and `try_lock_until()` provide non-blocking behavior, allowing you to set a maximum time a thread should wait for a lock.
  - If the lock cannot be acquired within the specified timeout, these functions return `false`.

- **Avoiding Deadlocks**:
  - `std::timed_mutex` helps prevent deadlocks by limiting the amount of time a thread will wait for a lock.
  - This is particularly beneficial in situations where waiting indefinitely is not an option, such as in real-time or high-performance systems.

- **Real-time Systems**:
  - `std::timed_mutex` is highly useful in real-time systems where responsiveness is crucial, and waiting forever for a lock could cause system failure.
  - By specifying a timeout, threads can quickly move on to other tasks if the lock is unavailable, ensuring that the system remains responsive.

- **Timeout Handling**:
  - `std::timed_mutex` provides an efficient mechanism for handling scenarios where acquiring a lock is uncertain, avoiding indefinite blocking and allowing alternative actions to be taken if the lock cannot be acquired within a reasonable timeframe.
