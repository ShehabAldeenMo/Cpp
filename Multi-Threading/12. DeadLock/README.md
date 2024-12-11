## Deadlock in C++ Threading

Deadlock is a situation in multithreading where two or more threads are waiting for each other to release resources, causing all threads to come to a halt.

---

### What is Deadlock?

- Deadlock occurs when multiple threads are waiting for resources in such a way that none of them can proceed.
- It typically happens when two or more threads acquire locks on shared resources in an inconsistent order.
