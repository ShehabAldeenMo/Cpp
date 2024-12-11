# Thread Synchronization Example

This example demonstrates thread synchronization in C++ using a multi-threaded approach. The program receives input parameters, including a string of characters, the number of characters to print per thread, and the number of threads. Each thread prints characters from the string in a synchronized and circular manner.

## Problem Definition

Given an input:
- A string of characters (`abcdefg`)
- A number (`4`), representing the number of characters each thread should print
- A number (`5`), representing the total number of threads

The program should:
1. Use threads to print the characters from the string in a circular and synchronized order.
2. Ensure no thread prints out of turn.
3. Repeat the sequence until all threads complete their task.

### Input Format

`<characters>,<chars_per_thread>,<num_threads>`

- **characters**: A string containing the characters to be printed (e.g., `abcdefg`)
- **chars_per_thread**: The number of characters each thread should print in its turn (e.g., `4`)
- **num_threads**: The number of threads participating in printing (e.g., `5`)

### Output Format

Each thread prints its thread ID and the characters it processes in order.

```
T1: a b c d
T2: e f g a
T3: b c d e
...
```

## Example

### Input

```
abcdefg,4,5
```

### Output

```
T1: a b c d
T2: e f g a
T3: b c d e
T4: f g a b
T5: c d e f
T1: g a b c
T2: d e f g
...
```

## Implementation Details

The program uses:
- **Threads**: To handle concurrent printing tasks.
- **Mutex and Condition Variable**: To synchronize the threads and prevent race conditions.
- **Circular Buffer Logic**: To ensure characters wrap around to the beginning when the end of the string is reached.

### Handling Edge Cases
1. **Insufficient Characters**:
   - If the string has fewer characters than `chars_per_thread * num_threads`, the sequence wraps around.
2. **Excessive Threads**:
   - Threads print characters in cycles, even if the number of threads exceeds the string length.
3. **Empty Input**:
   - The program exits with a message indicating invalid input.