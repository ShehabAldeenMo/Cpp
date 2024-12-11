## Producer-Consumer Problem in C++

### Problem Statement:
The goal is to implement synchronization between producer and consumer threads sharing a common buffer. The producer generates data, and the consumer processes it. Synchronization is managed using a `std::condition_variable` and `std::mutex`.

---

### Key Requirements:
1. **Producer Thread:**
   - Produces data and notifies the consumer when new data is available.
   - Waits if the buffer is full.

2. **Consumer Thread:**
   - Consumes data from the buffer and notifies the producer when space becomes available.
   - Waits if the buffer is empty.

3. **Synchronization Tools:**
   - `std::condition_variable`: Used for thread notifications.
   - `std::mutex`: Ensures mutual exclusion for buffer access.

---

### Implementation Details:

#### **Producer Thread Steps:**
1. Lock the mutex. Wait if the mutex is unavailable.
2. Check if the buffer is full:
   - If full, unlock the mutex and wait for notification.
   - Otherwise, produce an item.
3. Add the item to the buffer.
4. Unlock the mutex.
5. Notify the consumer thread.

#### **Consumer Thread Steps:**
1. Lock the mutex. Wait if the mutex is unavailable.
2. Check if the buffer is empty:
   - If empty, unlock the mutex and wait for notification.
   - Otherwise, consume an item.
3. Remove the item from the buffer.
4. Unlock the mutex.
5. Notify the producer thread.

---