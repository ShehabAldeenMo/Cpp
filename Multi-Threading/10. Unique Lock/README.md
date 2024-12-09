# unique_lock in C++ Threading

## Overview

`std::unique_lock` is a more flexible wrapper for managing mutex ownership compared to `std::lock_guard`. It provides various strategies for acquiring and managing a mutex, supports more advanced operations like time-constrained locking, recursive locking, and transferring lock ownership.

## Key Points to Remember

1. **Mutex Ownership Wrapper**:
   - `std::unique_lock` wraps a mutex and provides exclusive ownership of it. It is similar to `std::lock_guard` but offers more control and flexibility.

2. **Locking Strategies**:
   `std::unique_lock` allows for different locking strategies based on the specific needs of the program. These strategies are defined at the time of creating a `std::unique_lock` object.

   ### Locking Strategies
   | **Type**       | **Effect(s)**                                                                 |
   |----------------|-------------------------------------------------------------------------------|
   | `defer_lock`   | Does not acquire ownership of the mutex immediately. The lock must be manually acquired later. |
   | `try_to_lock`  | Attempts to acquire ownership of the mutex without blocking. If the lock cannot be acquired, it returns immediately. |
   | `adopt_lock`   | Assumes the calling thread already has ownership of the mutex. Does not attempt to acquire it again. |

3. **Time-Constrained Locking**:
   - `std::unique_lock` supports time-constrained locking methods like `try_lock_for` and `try_lock_until`, which allow for attempts to acquire a lock within a specified duration or until a specific time point.

4. **Recursive Locking**:
   - While `std::unique_lock` itself does not inherently support recursive locking, it can be used with `std::recursive_mutex` to allow the same thread to acquire the lock multiple times.

5. **Transfer of Lock Ownership**:
   - One of the key features of `std::unique_lock` is the ability to transfer lock ownership from one object to another. However, this is done by **move** semantics, not copy semantics. This allows for greater flexibility, such as passing the lock ownership between different scopes.

6. **Condition Variables**:
   - `std::unique_lock` is often used in conjunction with condition variables (`std::condition_variable`) for synchronizing threads. Condition variables require a `std::unique_lock` to safely manage the lock during waits and notifications. "will be illustrate next..." 

