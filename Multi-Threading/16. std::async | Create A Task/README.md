## Understanding `std::async` and Task Creation in C++ 

### Overview:
`std::async` is a powerful utility in C++ that simplifies asynchronous task execution by creating tasks with customizable launch policies. It is used to run functions concurrently and retrieve results once they are ready.

---

### Launch Policies:
`std::async` offers three different launch policies that dictate whether tasks are executed asynchronously or synchronously:

1. **`std::launch::async`:**
   - Forces asynchronous execution.
   - The task runs in a separate thread **immediately**.

2. **`std::launch::deferred`:**
   - Forces synchronous execution.
   - The task is deferred until the result is **explicitly needed** (e.g., via `.get()`).

3. **`std::launch::async | std::launch::deferred`:**
   - The OS decides between **asynchronous** and **deferred execution** based on available resources and optimization needs.
