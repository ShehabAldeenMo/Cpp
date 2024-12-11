## Understanding `std::promise` and `std::future` in C++ Thread Synchronisation

### Overview:
The `std::promise` and `std::future` objects work together to enable communication and synchronization between threads. 

---

### Key Concepts:
1. **`std::promise`:**
   - Used to set a value or signal an exception that can be retrieved by a corresponding `std::future`.
   - Typically sent to the worker thread, where the value is set once ready.

2. **`std::future`:**
   - Retrieves the value or exception from the associated `std::promise`.
   - Allows the main thread to synchronise and fetch results from the worker thread.

3. **Synchronization Process:**
   - The calling thread creates a `std::promise` and uses it to generate a `std::future`.
   - The `std::promise` is passed to the worker thread.
   - The worker thread sets a value or exception in the `std::promise`.
   - The calling thread retrieves the value using the `std::future`.

---

### Example Workflow:
1. Create a `std::promise` object in the calling thread.
2. Generate a `std::future` from the `std::promise`.
3. Pass the `std::promise` to the worker thread.
4. In the worker thread:
   - Perform computations.
   - Set the result in the `std::promise`.
5. In the calling thread:
   - Wait for and retrieve the result using the `std::future`.

---

### Usage 
It's used to syncrnounize  between main-thread or any other thread with another thread. main thread will be operate normally till reach to future point then will be hault till the child thread set its promise value.