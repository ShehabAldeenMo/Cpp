# lock_guard in C++ Threading

## Overview

`std::lock_guard` is a lightweight wrapper for managing mutex locks in C++. It provides a scoped, automatic mechanism for acquiring and releasing locks, ensuring that a mutex is always unlocked when the scope is exited, even if an exception is thrown.

## Key Points to Remember

1. **Lightweight Wrapper**:
   - `std::lock_guard` is a simple, lightweight wrapper around a mutex. It is designed to manage the locking and unlocking of a mutex automatically within a given scope.

2. **Automatic Locking**:
   - When you create an instance of `std::lock_guard`, it immediately acquires the lock for the associated mutex. This ensures the mutex is locked within the scope of the `lock_guard`.

3. **Automatic Unlocking**:
   - When the `std::lock_guard` object goes out of scope, the destructor is called, which automatically releases the mutex lock. This makes `std::lock_guard` ideal for handling locks in scope-based management, ensuring no lock is left accidentally held.

4. **No Explicit Unlock**:
   - You cannot explicitly unlock the mutex using `std::lock_guard`. The lock is automatically released when the object goes out of scope, simplifying the code and preventing errors such as forgetting to unlock the mutex.

5. **Non-Copyable**:
   - `std::lock_guard` is not copyable, meaning you cannot copy or assign it to another `lock_guard` object. This is to ensure that the lock remains tied to a single `lock_guard` object and is automatically managed in a predictable way.

