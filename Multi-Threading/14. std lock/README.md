## Avoiding Deadlocks in C++ Programming

### Understanding Deadlocks
Deadlocks occur when two or more threads are waiting for each other to release resources, leading to a state where no thread can proceed.

---

### Using `std::lock` to Avoid Deadlocks
- The `std::lock` function in C++11 helps avoid deadlocks by locking multiple mutexes simultaneously in an undefined order. It ensures no deadlocks occur, regardless of the order in which mutexes are specified. 

- All arguments are locked via a sequence of calls to lock(), try_lock(), or unlock() on each argument.
    - How will it be accured ?<br/>
        std::lock(m1,m2,m3,m4); <br/>
        - at call 0 will be :  m1  m2  m3  m4 will be locked in the same order. <br/>
        if m4 isn't available, will lead to release other keys and the next locking order will be m4->m1->m2->m3 
        - at call 1 will be :  m4  m1   m2  m3 will be locked in the same order. <br/>
        if m2 isn't available, will lead to release other keys and the next locking order will be m2->m4->m1->m3 
        - and so on .....


- Examples of Deadlock Avoidance
1. Example 0: No Deadlock
    - Two threads lock mutexes in the same order:
```
    Thread 1: std::lock(m1, m2);        Thread 2: std::lock(m1, m2);
```

2. Example 1: No Deadlock
    - Two threads lock the same mutexes but in reverse order:
```
    Thread 1: std::lock(m1, m2);        Thread 2: std::lock(m2, m1);
```

3. Example 2: No Deadlock
    - Complex locking order across threads:
```
    Thread 1: std::lock(m1, m2, m3, m4);        Thread 2: std::lock(m3, m4); 
                                                          std::lock(m1, m2);
```

#### Syntax:
```cpp
std::lock(m1, m2, m3, ...);
```
