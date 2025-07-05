# C++ Casting — Types, Conversions & C‑Style Casts
## Table Of Content
- [Introduction](#introduction)


### 🚀 Introduction

In C++, **type casting** is the process of converting a variable from one type to another. 

Example:
```cpp
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << 7 / 5 << std::endl;        // Output: 1 (integer division)
    std::cout << (float)7 / 5 << std::endl; // Output: 1.400000 (correct floating-point division)
}
```

💡 **Why?**  
In `7 / 5`, both operands are integers → the compiler performs **integer division** → result: `1`.  
In `(float)7 / 5`, **explicit casting** changes the type → compiler performs **floating-point division** → result: `1.4`.

Without casting, you could get **unexpected results** even when you think your logic is correct.

---

## 🔍 Casting Types

### 1. Implicit Casting (Automatic)
- Done by the `compiler` automatically.
- Can happen in mixed-type expressions.
- Can **lose precision** without warning.

Example:
```cpp
int a = 5;
double b = 2.3;
double c = a + b; // 'a' is implicitly cast to double
```

### 2. Explicit Casting (C-Style)
- **Forces** the conversion to the desired type.
- Syntax: `(type)value`
- Should be used carefully.

Example:
```cpp
int a = 7, b = 5;
std::cout << (float)a / b << std::endl; // Forces floating-point division
```

---

This Readme Flow based on [C++ Casting - Part 1 | Modern Cpp Series Ep. 91 - YouTube](https://www.youtube.com/watch?v=jbmvSBHe9hA&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=92)