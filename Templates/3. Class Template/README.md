# 📘 Class Templates and Programming by Contract in C++

## 📚 Overview

This document introduces:

* Class Templates: Writing generic classes that work with any data type.
* Programming by Contract: Writing code with preconditions, postconditions, and invariants to enforce correct behavior.

---

## 🏷️ Class Templates

### ✅ What is a Class Template?

A class template allows you to write a **generic class** that can operate with any data type without rewriting the class.

### 📦 Syntax:

```cpp
template <typename T>
class ClassName {
    T data;
public:
    ClassName(T value) : data(value) {}
    T getData() { return data; }
};
```

---

### 🚀 Example 1: Simple Class Template

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void display() { cout << "Value: " << value << endl; }
};

int main() {
    Box<int> intBox(10);
    Box<string> strBox("Hello");

    intBox.display();  // Output: Value: 10
    strBox.display();  // Output: Value: Hello

    return 0;
}
```

---

### 🚀 Example 2: Class Template with Multiple Types

```cpp
template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void show() { cout << "First: " << first << ", Second: " << second << endl; }
};

int main() {
    Pair<int, string> p(1, "One");
    p.show();  // Output: First: 1, Second: One
}
```

---

## 🔒 Programming by Contract

### ✅ Concept

Programming by Contract (PBC) is a design methodology where:

* **Preconditions**: What must be true before a function runs.
* **Postconditions**: What must be true after a function runs.
* **Invariants**: Conditions that must always hold for the object.

---

### 📦 Enforcing Contracts in C++:

* Use `assert()` to enforce preconditions and postconditions.
* Ensure class invariants inside constructors and public methods.

---

### 🚀 Example: Class Template with Contract Checks

```cpp
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class SafeBox {
    T value;
public:
    SafeBox(T v) {
        assert(v >= 0 && "Precondition: Value must be non-negative.");
        value = v;
        assert(value >= 0 && "Invariant: Value must remain non-negative.");
    }

    void setValue(T v) {
        assert(v >= 0 && "Precondition: Value must be non-negative.");
        value = v;
    }

    T getValue() const {
        assert(value >= 0 && "Invariant: Value must remain non-negative.");
        return value;
    }
};

int main() {
    SafeBox<int> box(5);
    cout << box.getValue() << endl;

    // Uncommenting below will violate contract
    // box.setValue(-1);

    return 0;
}
```

---

## ✅ 1. Using `typeid` with `type_info`

You can get the **run-time type information** using `typeid`.

```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
void checkType(T arg) {
    cout << "Type: " << typeid(arg).name() << endl;
}

int main() {
    checkType(5);          // int
    checkType(5.5);        // double
    checkType("Hello");    // const char*
}
```

> 🔹 Note: `typeid(arg).name()` returns the **mangled name** (depends on the compiler). You can demangle using compiler-specific tools.

---

## ✅ 2. Using `std::is_same` with `if constexpr` (Compile-Time Check)

Modern, clean, **compile-time type check**.

```cpp
#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void checkType(T arg) {
    if constexpr (std::is_same<T, int>::value)
        cout << "Type is int\n";
    else if constexpr (std::is_same<T, double>::value)
        cout << "Type is double\n";
    else
        cout << "Unknown type\n";
}

int main() {
    checkType(10);      // int
    checkType(3.14);    // double
    checkType('A');     // Unknown
}
```

> 🔸 `if constexpr` is evaluated at **compile time**, so no unnecessary code is generated.

---

## ✅ 3. Using Template Specialization

You can specialize a function or class template based on the type.

```cpp
#include <iostream>
using namespace std;

template <typename T>
void checkType(T arg) {
    cout << "Unknown type\n";
}

template <>
void checkType<int>(int arg) {
    cout << "Type is int\n";
}

template <>
void checkType<double>(double arg) {
    cout << "Type is double\n";
}

int main() {
    checkType(42);     // int
    checkType(3.14);   // double
    checkType('A');    // Unknown
}
```