# **Introduction to Threads in C++ (C++11)**

This document covers the fundamental concepts of threading in C++ (introduced in C++11). It explains what threads are, provides practical examples, and explores the various ways to create threads in C++.

---

## **1. What is a Thread?**

- **Definition**: A thread is a lightweight process, and the primary idea behind threads is to achieve parallelism by dividing a program into smaller, concurrently running parts.
- **Default Thread**: In every C++ application, the `main()` function represents the default thread. From this thread, additional threads can be created.
- **Real-world Examples**:
  - **Browsers**: Different tabs run as separate threads.
  - **MS Word**: Threads handle text formatting, spell checking, and input processing.
  - **Code Editors**: Threads assist with tasks like code auto-completion (IntelliSense).

---

## **2. Ways to Create Threads in C++11**
- 2.1 Function Pointers: Threads can be created using regular functions.
- 2.2 Lambda Functions: Lambda expressions provide a convenient way to create inline threads.
- 2.3 Functors: Use a callable object (functor) to create threads.
- 2.4 Non static Member Functions: Threads can be created using member functions of a class.
- 2.5 Static Member Functions:Static member functions don't require an object instance to be passed to the thread.

---

## **3. Key Points**
- Threads in C++ allow for concurrent execution of code, improving application responsiveness and performance.
- Proper synchronization is crucial to avoid race conditions when accessing shared data.

## **4. Questions**
- What do you understand by a thread?

1. A thread is a lightweight process, enabling parallelism. In every application, main() is the default thread, and additional threads can be created as needed.

2. Give an example of using threads in C++.
See examples in the sections above.