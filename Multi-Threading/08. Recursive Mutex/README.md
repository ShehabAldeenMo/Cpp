# Recursive Mutex in C++ (std::recursive_mutex)

## Overview

`std::recursive_mutex` is a variant of the standard mutex, which allows the same thread to lock the mutex multiple times. It is particularly useful when you need to place locks in recursive function calls.

## Key Points to Remember

1. **Recursive Locking**:
   - Unlike a regular mutex, a `std::recursive_mutex` allows the same thread to lock it multiple times. The same thread can lock the mutex recursively without causing a deadlock.

2. **Lock Count**:
   - When a thread locks a recursive mutex (e.g., `m1`), it increases an internal counter. For each lock, the counter increments. When the thread unlocks the mutex, the counter decrements. The thread must unlock the mutex as many times as it locked it to release the lock completely.

3. **Unlock Requirement**:
   - If thread T1 locks a `recursive_mutex` 10 times, it must unlock it 10 times. If it fails to do so, other threads won't be able to acquire the mutex.
   - If T1 tries to lock more times than the mutex can handle, a `std::system_error` will be thrown if using `lock()`. If using `try_lock()`, it will return `false`.

4. **Usage in Recursion**:
   - `std::recursive_mutex` is particularly helpful in recursive functions, where the same thread needs to lock the mutex multiple times as it enters deeper levels of recursion.
