# 📄 Function Templates in C++

## 📚 Overview

Templates in C++ allow you to write **generic and reusable functions** that work with different data types without rewriting the function logic.

A **function template** defines a blueprint for functions that can handle various types.

---

## 🛠️ Syntax of a Function Template

```cpp
template <typename T>
ReturnType FunctionName(Parameters of type T)
{
    // Function logic
}
```

* `template <typename T>` or `template <class T>` tells the compiler this is a template.
* `T` is a placeholder for a type that will be provided when the function is called.

---

## 🚀 Basic Example: Swapping Two Values

```cpp
#include <iostream>
using namespace std;

template <typename T>
void SwapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5, y = 10;
    SwapValues(x, y);
    cout << "Swapped int: " << x << " " << y << endl;

    double d1 = 3.14, d2 = 2.71;
    SwapValues(d1, d2);
    cout << "Swapped double: " << d1 << " " << d2 << endl;

    string s1 = "Hello", s2 = "World";
    SwapValues(s1, s2);
    cout << "Swapped string: " << s1 << " " << s2 << endl;

    return 0;
}
```

---

## 📂 Example: Finding the Maximum of Two Values

```cpp
template <typename T>
T GetMax(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << "Max of 3 and 7: " << GetMax(3, 7) << endl;
    cout << "Max of 2.5 and 5.1: " << GetMax(2.5, 5.1) << endl;
    cout << "Max of 'a' and 'z': " << GetMax('a', 'z') << endl;

    return 0;
}
```

---

## 📌 Example: Template with Multiple Types

```cpp
template <typename T1, typename T2>
void DisplayTypes(T1 a, T2 b)
{
    cout << "First: " << a << " | Second: " << b << endl;
}

int main()
{
    DisplayTypes(5, 3.14);
    DisplayTypes("Age", 25);
    DisplayTypes('X', " is a character");

    return 0;
}
```

---

## ⚙️ Example: Specifying Template Type Explicitly

```cpp
template <typename T>
void ShowValue(T a)
{
    cout << "Value: " << a << endl;
}

int main()
{
    ShowValue<int>(100);     // Explicit type
    ShowValue<double>(3.14); // Explicit type
    ShowValue("Hello");      // Type deduced automatically

    return 0;
}
```
---

## 🧐 Template Argument Deduction

### What is it?

Template argument deduction is when **the compiler automatically figures out the template type** based on the function arguments, without requiring you to specify the type explicitly.

### Example 1: Automatic Deduction

```cpp
template <typename T>
void PrintType(T a)
{
    cout << "Type value: " << a << endl;
}

int main()
{
    PrintType(5);       // T is deduced as int
    PrintType(3.14);    // T is deduced as double
    PrintType("Hello"); // T is deduced as const char*

    return 0;
}
```

### Example 2: Deduction with Multiple Parameters

```cpp
template <typename T1, typename T2>
void Add(T1 a, T2 b)
{
    cout << "Sum: " << a + b << endl;
}

int main()
{
    Add(3, 4);         // T1 = int, T2 = int
    Add(2.5, 4);       // T1 = double, T2 = int
    Add(3, 4.5f);      // T1 = int, T2 = float

    return 0;
}
```

Here’s a **clear example (Example 3)** that will produce a **compiler error due to template argument deduction failure** when mixing `int` and `double` while the function is returning `T`:

---

## ❌ Example 3: Template Argument Deduction Failure (Return Type Mismatch)

```cpp
#include <iostream>
using namespace std;

template <typename T>
T Add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << Add(3, 4) << endl;       // OK: Both int
    cout << Add(2.5, 4.5) << endl;   // OK: Both double
    cout << Add(3, 4.5) << endl;     // ❌ Error: Argument types are int and double, no common deduced type T
    return 0;
}
```

---

### 📛 Why This Fails:

When you call:

```cpp
Add(3, 4.5);
```

* The compiler tries to **deduce a single type T** that can match both `int` and `double`.
* But:

  * `3` is an `int` → Suggests `T = int`
  * `4.5` is a `double` → Suggests `T = double`
* The compiler **cannot resolve a common type T automatically in this case.**

### 🔎 Compiler Message:

Typical error message would say:

```
no matching function for call to 'Add(int, double)'
```

---

## ✅ How to Fix (Conceptually)

You would need to:

* **Provide a function template with two separate type parameters.**
* OR
* **Explicitly cast the parameters to the same type.**

```cpp
#include <iostream>
using namespace std;

template <typename T1, typename T2>
T1 Add(T1 a, T2 b)
{
    return a + b;
}

int main()
{
    cout << Add(3, 4) << endl;              // OK: Both int
    cout << Add(2.5, 4.5) << endl;          // OK: Both double
    cout << Add(3, 4.5) << endl;            // OK: solution1
    cout << Add<double> (5.6,8.8) << endl;  // OK: solution2
    return 0;
}
```

---

## 5️⃣ Using `auto` as Return Type (C++14 and Above)

With `auto`, the compiler can deduce the return type even for mixed arguments.

```cpp
template <typename T1, typename T2>
auto Multiply(T1 a, T2 b)
{
    return a * b;
}

int main()
{
    cout << Multiply(2, 3.5) << endl;  // ✅ Output: 7.0
    return 0;
}
```

---

## 6️⃣ Template Specialization

When you want a **special case** for a specific type.

```cpp
#include <iostream>
using namespace std;

template <typename T>
void PrintType(T value)
{
    cout << "Generic type: " << value << endl;
}

// Specialization for string
template <>
void PrintType<string>(string value)
{
    cout << "This is a string: " << value << endl;
}

int main()
{
    PrintType(5);           // Generic type: 5
    PrintType(3.14);        // Generic type: 3.14
    PrintType("Hello");     // This is a string: Hello
    return 0;
}
```

