# 🚀 Advanced C++ Templates: Variadic Templates, Tail Recursion, Folding Expressions, and Performance Insights

This guide covers **advanced topics in C++ templates** with practical examples.

---

## 📂 Table of Contents

1. [Variadic Templates](#1️⃣-variadic-templates)
2. [Tail Recursion in Variadic Templates](#2️⃣-implementation-with-tail-recursion)
3. [Variadic Templates Corner Cases](#3️⃣-variadic-templates-corner-cases)
4. [Folding Expressions](#4️⃣-implementing-using-folding-expression)

---

## 1️⃣ Variadic Templates

Variadic templates allow **an arbitrary number of template arguments**.

### Example: Printing all arguments

```cpp
#include <iostream>
using namespace std;

void Print() { cout << endl; }  // Base case

template<typename T, typename... Args>
void Print(T first, Args... rest)
{
    cout << first << " ";
    Print(rest...);
}

int main()
{
    Print(1, 2.5, "Hello", 'A'); // Output: 1 2.5 Hello A 
    return 0;
}
```

---

## 2️⃣ Implementation with Tail Recursion

Tail recursion processes one argument per function call and passes the remaining to the next call.

```cpp
template<typename T>
void Process(T value)
{
    cout << "Processing: " << value << endl;
}

template<typename T, typename... Args>
void Process(T first, Args... rest)
{
    cout << "Processing: " << first << endl;
    Process(rest...);  // Tail recursion
}

int main()
{
    Process(1, "Test", 3.14, 'X');
    return 0;
}
```

✔️ **Key Concept:** Each call reduces the argument pack by one.

---

## 3️⃣ Variadic Templates Corner Cases

### Corner Case 1: Empty Pack

You must always provide a base case to stop recursion.

```cpp
void Print() { cout << "Done!" << endl; }
```

### Corner Case 2: Type Mismatch in Recursive Call

Incorrectly passing packs can lead to compilation errors.

```cpp
// Example of misuse:
// template<typename T, typename... Args>
// void Print(Args... rest) { /* Wrong: drops the first argument */ }
```

### Corner Case 3: Pack Expansion without Separator

Incorrect folding without a neutral element can cause issues.

```cpp
// Example of invalid: return (args + ...); // Missing identity for empty pack
```

---

## 4️⃣ Implementing Using Folding Expression (C++17)

Folding expressions simplify variadic template operations.

### Example: Sum all arguments

```cpp
template<typename... Args>
auto Sum(Args... args)
{
    return (args + ...);  // Left fold
}

int main()
{
    cout << Sum(1, 2, 3, 4, 5) << endl; // Output: 15
    return 0;
}
```

---

## 📘 Example: Counting Number of Parameters in Variadic Template

```cpp
#include <iostream>
using namespace std;

// Variadic template function to print the count of passed arguments
template<typename... Args>
void CountArguments(Args... args)
{
    cout << "Number of arguments: " << sizeof...(args) << endl;

    // You can also print them
    ((cout << args << " "), ...);
    cout << endl;
}

int main()
{
    CountArguments(1, 2, 3);              // Number of arguments: 3
    CountArguments("Hello", 3.14, 'A');   // Number of arguments: 3
    CountArguments();                     // Number of arguments: 0
    return 0;
}
```
