## Understanding `std::try_lock()` in C++11 Threading

In this section, we will learn how to use `std::try_lock()` to manage multiple mutexes efficiently.

---

### Key Points About `std::try_lock()`

1. `std::try_lock()` tries to lock all the mutexes passed to it one by one, in the given order.
2. **Return Values**:
   - On success, it returns `-1`, indicating all mutexes were successfully locked.
   - On failure, it returns the 0-based index of the mutex it could not lock.
        ex: std::try_lock(m1,m2,m3) and m3 is locked before so will lead to return (2)
3. If `std::try_lock()` fails to lock any of the mutexes:
   - It automatically releases all previously locked mutexes.
4. If a call to `std::try_lock()` throws an exception:
   - `unlock()` is called on any locked objects before the exception is re-thrown, ensuring no locks are left dangling.
