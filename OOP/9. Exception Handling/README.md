C++ Exception Types and Examples

1. `std::bad_alloc`

Description: Thrown when a memory allocation request fails, such as when new cannot allocate sufficient memory.
Example:
```cpp
#include <iostream>
#include <new>
int main() {
    try {
        int* ptr = new int[1000000000000]; // Attempting to allocate an enormous array
    } catch (const std::bad_alloc& e) {
        std::cout << "Bad allocation: " << e.what() << std::endl;
    }
    return 0;
}
```


2. `std::bad_cast`

Description: Thrown when a dynamic cast to a reference type fails, typically due to an incompatible type.
Example:
```cpp
#include <iostream>
#include <typeinfo>
class Base { virtual void dummy() {} };
class Derived : public Base {};
int main() {
    try {
        Base* base = new Base;
        Derived& ref = dynamic_cast<Derived&>(*base); // Invalid cast
    } catch (const std::bad_cast& e) {
        std::cout << "Bad cast: " << e.what() << std::endl;
    }
    return 0;
}
```


3. `std::bad_typeid`

Description: Thrown when typeid is applied to a null pointer or an uninitialized object.
Example:
```cpp
#include <iostream>
#include <typeinfo>
class Base { virtual void dummy() {} };
int main() {
    try {
        Base* ptr = nullptr;
        typeid(*ptr); // Using typeid on a null pointer
    } catch (const std::bad_typeid& e) {
        std::cout << "Bad typeid: " << e.what() << std::endl;
    }
    return 0;
}
```


4. `std::bad_exception`

Description: Used as a replacement exception when an unexpected exception is caught by a function-try-block.
Example:
```cpp
#include <iostream>
#include <exception>
void func() throw(std::bad_exception) {
    throw 42; // Unexpected exception
}
int main() {
    try {
        try {
            func();
        } catch (...) {
            throw; // Rethrow to catch as bad_exception
        }
    } catch (const std::bad_exception& e) {
        std::cout << "Bad exception: " << e.what() << std::endl;
    }
    return 0;
}
```


5. `std::logic_error` and Derived Classes

Description: Represents logical errors detectable at compile time.
std::domain_error: Thrown when an argument is outside the function's valid domain.
Example:
```cpp
#include <iostream>
#include <stdexcept>
#include <cmath>
double custom_sqrt(double x) {
    if (x < 0) throw std::domain_error("Cannot compute square root of negative number");
    return std::sqrt(x);
}
int main() {
    try {
        custom_sqrt(-1);
    } catch (const std::domain_error& e) {
        std::cout << "Domain error: " << e.what() << std::endl;
    }
    return 0;
}
```



`std::invalid_argument`: Thrown when an argument is invalid.
Example:
```cpp
#include <iostream>
#include <stdexcept>
#include <string>
int to_int(const std::string& s) {
    if (s.find_first_not_of("0123456789") != std::string::npos)
        throw std::invalid_argument("Invalid number format");
    return std::stoi(s);
}
int main() {
    try {
        to_int("abc");
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
    return 0;
}
```



`std::length_error`: Thrown when an object exceeds its maximum size.
Example:
```cpp
#include <iostream>
#include <stdexcept>
#include <string>
int main() {
    try {
        std::string s;
        s.reserve(s.max_size() + 1); // Exceeds maximum size
    } catch (const std::length_error& e) {
        std::cout << "Length error: " << e.what() << std::endl;
    }
    return 0;
}
```



`std::out_of_range`: Thrown when accessing a container with an invalid index.
Example:
```cpp
#include <iostream>
#include <stdexcept>
#include <vector>
int main() {
    try {
        std::vector<int> v = {1, 2, 3};
        int value = v.at(5); // Index out of range
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << std::endl;
    }
    return 0;
}
```






6. `std::runtime_error` and Derived Classes

Description: Represents errors detectable only at runtime.
std::overflow_error: Thrown when a mathematical operation exceeds the maximum limit.
Example:
```cpp
#include <iostream>
#include <stdexcept>
#include <limits>
long long add(long long a, long long b) {
    if (a > 0 && b > 0 && a > std::numeric_limits<long long>::max() - b)
        throw std::overflow_error("Addition overflow");
    return a + b;
}
int main() {
    try {
        add(std::numeric_limits<long long>::max(), 1);
    } catch (const std::overflow_error& e) {
        std::cout << "Overflow error: " << e.what() << std::endl;
    }
    return 0;
}
```



`std::underflow_error`: Thrown when a mathematical operation results in a value too small to represent.
Example:
```cpp
#include <iostream>
#include <stdexcept>
#include <limits>
double subtract(double a, double b) {
    if (a < 0 && b > 0 && a < std::numeric_limits<double>::lowest() + b)
        throw std::underflow_error("Subtraction underflow");
    return a - b;
}
int main() {
    try {
        subtract(std::numeric_limits<double>::lowest(), 1.0);
    } catch (const std::underflow_error& e) {
        std::cout << "Underflow error: " << e.what() << std::endl;
    }
    return 0;
}
```



`std::range_error`: Thrown when a result is outside a valid range.
Example:
```cpp
#include <iostream>
#include <stdexcept>
int compute(int x) {
    if (x > 100) throw std::range_error("Value out of valid range");
    return x;
}
int main() {
    try {
        compute(150);
    } catch (const std::range_error& e) {
        std::cout << "Range error: " << e.what() << std::endl;
    }
    return 0;
}
```