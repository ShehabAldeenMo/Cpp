# Table of Contents

1. **[Introduction to Smart Pointers](#introduction-to-smart-pointers)**  
   - [What are Smart Pointers?](#what-are-smart-pointers)  
   - [Why Use Smart Pointers?](#why-use-smart-pointers)  

2. **[Types of Smart Pointers](#types-of-smart-pointers)**  
   - [`std::unique_ptr`](#stdunique_ptr)  
   - [`std::shared_ptr`](#stdshared_ptr)  
   - [`std::weak_ptr`](#stdweak_ptr)  

3. **[Features and Benefits](#features-and-benefits)**  
   - [Automatic Resource Management](#automatic-resource-management)  
   - [Exception Safety](#exception-safety)  
   - [Ownership Semantics](#ownership-semantics)  

4. **[Detailed Explanation of Smart Pointer Types](#detailed-explanation-of-smart-pointer-types)**  
   - **[`std::unique_ptr`](#stdunique_ptr-1)**  
     - [Definition and Purpose](#definition-and-purpose)  
     - [Declaration & Initialization](#declaration--initialization)  
     - [Operations and Methods (`release`, `reset`, `get`)](#operations-and-methods)  
     - [Example Usage](#example-usage)  
   - **[`std::shared_ptr`](#stdshared_ptr-1)**  
     - [Definition and Purpose](#definition-and-purpose-1)  
     - [Declaration & Initialization](#declaration--initialization-1)  
     - [Reference Counting Mechanism](#reference-counting-mechanism)  
     - [Operations and Methods (`use_count`, `reset`, `get`)](#operations-and-methods-1)  
     - [Example Usage](#example-usage-1)  
   - **[`std::weak_ptr`](#stdweak_ptr-1)**  
     - [Definition and Purpose](#definition-and-purpose-2)  
     - [Solving Cyclic References](#solving-cyclic-references)  
     - [Operations and Methods (`lock`, `expired`)](#operations-and-methods-2)  
     - [Example Usage](#example-usage-2)  

5. **[Common Use Cases](#common-use-cases)**  
   - [Managing Dynamic Memory](#managing-dynamic-memory)  
   - [Resource Sharing](#resource-sharing)  
   - [Avoiding Cyclic Dependencies](#avoiding-cyclic-dependencies)  

6. **[Advanced Topics](#advanced-topics)**  
   - [Custom Deleters](#custom-deleters)  
   - [`std::enable_shared_from_this`](#stdenable_shared_from_this)  


# Introduction to Smart Pointers

## What are Smart Pointers?

Smart pointers are a feature in C++ that manage the lifetime of dynamically allocated objects. Unlike raw pointers, smart pointers automatically handle memory deallocation when the object is no longer needed. They are part of the C++ Standard Library and help prevent common memory management issues, such as memory leaks and dangling pointers.

## Why Use Smart Pointers?

- **Automatic Resource Management**: Smart pointers automatically free the allocated memory when the pointer goes out of scope, reducing the need for manual `delete` operations.
  
- **Exception Safety**: By handling resource cleanup automatically, smart pointers prevent memory leaks even when exceptions occur.

- **Improved Code Readability**: They clearly indicate ownership semantics and make the code easier to understand.

- **Prevention of Common Errors**: Smart pointers help avoid errors like double deletion, memory leaks, and use-after-free.

- **Efficient Resource Sharing**: Some smart pointers, like `std::shared_ptr`, allow multiple owners for a single resource, ensuring proper cleanup only when the last owner is destroyed.

# Types of Smart Pointers

### `std::unique_ptr`

- **Definition**:  
  A smart pointer that owns and manages a dynamically allocated object through a pointer. It ensures that the object is automatically deleted when the `std::unique_ptr` goes out of scope. 

- **Key Properties**:  
  - Ensures sole ownership of the object.
  - Non-copyable to prevent multiple ownership, but movable.

---

### `std::shared_ptr`

- **Definition**:  
  A smart pointer that allows multiple `std::shared_ptr` instances to share ownership of the same dynamically allocated object, managing its lifetime through reference counting.

- **Key Properties**:  
  - Uses reference counting to track the number of owners.
  - The object is destroyed when the last `std::shared_ptr` is destroyed or reset.
  - Supports copy and move operations.

---

### `std::weak_ptr`

- **Definition**:  
  A smart pointer that provides a non-owning reference to an object managed by `std::shared_ptr`. It does not contribute to the reference count. But could observable.

- **Key Properties**:  
  - Does not affect the reference count of the shared object.
  - Prevents cyclic references by providing a temporary access mechanism.
  - Can be converted to `std::shared_ptr` using `lock()` if the object still exists.


## Features and Benefits

### Automatic Resource Management

- **Definition**:  
  Smart pointers automatically manage the lifetime of dynamically allocated objects, ensuring resources are released when no longer needed.

- **Key Benefits**:  
  - Eliminates the need for explicit `delete` calls.
  - Reduces the risk of memory leaks and dangling pointers.
  - Ensures proper cleanup, even in complex scenarios.

---

### Exception Safety

- **Definition**:  
  Smart pointers provide strong exception safety guarantees by automatically releasing resources when exceptions are thrown.

- **Key Benefits**:  
  - Prevents resource leaks in case of exceptions.
  - Simplifies error handling by ensuring resources are correctly managed.

---

### Ownership Semantics

- **Definition**:  
  Smart pointers provide clear and flexible ownership models, ensuring objects are owned and shared as intended.

- **Key Benefits**:  
  - **`std::unique_ptr`**: Sole ownership of a resource.
  - **`std::shared_ptr`**: Shared ownership with reference counting.
  - **`std::weak_ptr`**: Non-owning reference for temporary access.
  - Improves code readability and maintainability by clarifying ownership responsibilities.

# Detailed Explanation of Smart Pointer Types

## [`std::unique_ptr`](#stdunique_ptr-1)

### [Definition and Purpose](#definition-and-purpose)
- **Definition**:  
  `std::unique_ptr` is a smart pointer that exclusively owns a dynamically allocated object. It guarantees that the resource it points to is automatically freed when the `unique_ptr` is destroyed, ensuring no resource leaks.

- **Purpose**:  
  It is used when the ownership of a resource should be unique, meaning only one `std::unique_ptr` can manage the resource at a time. This pointer is non-copyable, but it can be moved, ensuring that the ownership is transferred from one `unique_ptr` to another.

#### [Declaration & Initialization](#declaration--initialization)
- **Declaration**:  
  To declare a `std::unique_ptr`, you specify the type of the resource being managed, followed by `std::unique_ptr<type>`. Here's an example:

```cpp
std::unique_ptr<int> ptr;  // Declare a unique_ptr managing an integer
```

- **Initialization**:
You can initialize a `unique_ptr` using `std::make_unique` or directly assign it a dynamically allocated object.

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(10);  // Initializes with a value 10
std::unique_ptr<int> ptr = new ObjectClass;
```

- `Operations` and `Methods` (`release`, `reset`, `get`)
`release()`: Releases the ownership of the resource, returning a raw pointer. The unique_ptr will no longer own the resource after calling release().

```cpp
int* rawPtr = ptr.release();  // Releases ownership, ptr is now null
```

`reset()`: Resets the unique_ptr, optionally taking a new resource or nullptr. The old resource will be deleted if it exists.

```cpp
ptr.reset();  // Deletes the current resource and sets ptr to nullptr
ptr.reset(new int(20));  // Resets to a new resource
```

`get()`: Returns the raw pointer that the unique_ptr is managing.

```cpp
int* rawPtr = ptr.get();  // Accesses the raw pointer
```

**Example Usage**
Example 1: Basic Usage
Here's a simple example demonstrating how to use std::unique_ptr for dynamic memory management.

```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(100);  // Create a unique_ptr
    std::cout << "Value: " << *ptr << std::endl;  // Access value
    // No need to manually delete, it's automatically cleaned up
    return 0;
}
```

```Output
Value: 100
```

Example 2: Ownership Transfer Since `std::unique_ptr` cannot be copied, it can only be moved to transfer ownership:

```cpp
std::unique_ptr<int> ptr1 = std::make_unique<int>(50);
std::unique_ptr<int> ptr2 = std::move(ptr1);  // Ownership transferred to ptr2

if (!ptr1) {
    std::cout << "ptr1 is now empty" << std::endl;  // ptr1 is null
}
```

- To demonstrate how a `std::unique_ptr` can be moved, we can use the move semantics that `std::unique_ptr` provides. Since `std::unique_ptr` is designed to have exclusive ownership of the resource it points to, the ownership of the resource can be transferred (moved) from one `std::unique_ptr` to another. After the move, the original `std::unique_ptr` is null, and the new `std::unique_ptr` has the ownership of the resource.

Here's an example that demonstrates moving a `std::unique_ptr`:
```Cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }
    void sayHello() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    // Create a unique_ptr and manage an instance of MyClass
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();

    // Use the object through ptr1
    ptr1->sayHello();

    // Move ownership of the object from ptr1 to ptr2
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);

    // After move, ptr1 no longer owns the object and is null
    if (ptr1) {
        ptr1->sayHello(); // This won't be called
    } else {
        std::cout << "ptr1 is now null" << std::endl;
    }

    // Now ptr2 owns the object
    ptr2->sayHello(); // This will be called

    return 0;
}
```

```Output
MyClass constructor
Hello from MyClass!
ptr1 is now null
Hello from MyClass!
MyClass destructor
```

## [`std::shared_ptr`](#stdshared_ptr-1)

### [Definition and Purpose](#definition-and-purpose-1)
- **Definition**:  
  `std::shared_ptr` is a smart pointer that manages a dynamically allocated object with shared ownership. Multiple `shared_ptr`s can share ownership of the same resource, and the resource is automatically deallocated when the last `shared_ptr` managing it is destroyed.

- **Purpose**:  
  It is used when multiple parts of a program need to share ownership of a resource. The resource will not be freed until all `shared_ptr` instances that point to it have been destroyed or reset.

### [Declaration & Initialization](#declaration--initialization-1)
- **Declaration**:  
  To declare a `std::shared_ptr`, you specify the type of the resource being managed, followed by `std::shared_ptr<type>`. Here’s an example:

```cpp
std::shared_ptr<int> ptr;  // Declare a shared_ptr managing an integer
```

- **Initialization**:
You can initialize a shared_ptr using std::make_shared or by directly assigning it a dynamically allocated object.

```cpp
std::shared_ptr<int> ptr = std::make_shared<int>(10);  // Initializes with a value 10
```

**Reference Counting Mechanism**
- **Reference Counting**:
`std::shared_ptr` keeps track of how many `shared_ptr` objects point to the same resource via a reference count. Each time a new shared_ptr is created from another, the reference count is incremented. When a `shared_ptr` goes out of scope or is reset, the reference count is decremented. When the reference count reaches zero, the resource is automatically deallocated.

Example:

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(100);  // ref count = 1
std::shared_ptr<int> ptr2 = ptr1;  // ref count = 2
// When ptr2 goes out of scope, ref count = 1
```

**Operations and Methods (use_count, reset, get)**
- `use_count()`:
Returns the number of shared_ptr instances that share ownership of the same resource.

```cpp
std::cout << "Use count: " << ptr1.use_count() << std::endl;
```

- `reset()`:
Resets the `shared_ptr`, optionally taking a new resource or nullptr. The old resource will be deleted if it exists.

```cpp
ptr1.reset();  // Releases ownership and resets to nullptr
ptr1.reset(new int(200));  // Resets to a new resource
````

- `get()`:
Returns the raw pointer that the shared_ptr is managing.

```cpp
int* rawPtr = ptr1.get();  // Accesses the raw pointer
```

**Example Usage**
- Example 1: Basic Usage
Here's a simple example demonstrating how to use std::shared_ptr for dynamic memory management with shared ownership:

```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);  // Create shared_ptr
    std::shared_ptr<int> ptr2 = ptr1;  // ptr2 shares ownership with ptr1
    std::cout << "Value: " << *ptr1 << std::endl;  // Access value
    std::cout << "Use count: " << ptr1.use_count() << std::endl;  // 2
    return 0;
}
```

```Output:
Value: 100
Use count: 2
```

- Example 2: Shared Ownership Multiple shared_ptr instances can share ownership of the same resource:

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(50);
std::shared_ptr<int> ptr2 = ptr1;  // Both ptr1 and ptr2 share ownership

std::cout << "Use count: " << ptr1.use_count() << std::endl;  // 2
```

## [`std::weak_ptr`](#stdweak_ptr-1)

### [Definition and Purpose](#definition-and-purpose-2)
- **Definition**:  
  `std::weak_ptr` is a smart pointer that provides a non-owning, weak reference to an object managed by `std::shared_ptr`. It does not affect the reference count, meaning it doesn’t contribute to the lifetime of the object. It allows access to the managed object if it still exists but doesn’t prevent its deallocation when all `shared_ptr` instances are destroyed.

- **Purpose**:  
  The primary purpose of `std::weak_ptr` is to break circular references that can occur with `std::shared_ptr` by allowing objects to refer to each other without extending their lifetime. This is especially useful in cache management or observer patterns.

### [Solving Cyclic References](#solving-cyclic-references)
- **Cyclic References**:  
  A cyclic reference occurs when two or more objects hold `shared_ptr` references to each other, causing their reference count to never reach zero. As a result, the objects are never deallocated, leading to a memory leak.

- **How `std::weak_ptr` Helps**:  
  By using `std::weak_ptr`, one of the objects in a cycle can be prevented from increasing the reference count, thus allowing proper deallocation once all `shared_ptr` references are destroyed. This helps avoid memory leaks caused by circular references.

**Example**:
```cpp
  class Node {
  public:
      std::shared_ptr<Node> next;
      std::weak_ptr<Node> prev;  // Prevent cyclic reference
  };

  // Two nodes referencing each other but avoiding a memory leak
  std::shared_ptr<Node> node1 = std::make_shared<Node>();
  std::shared_ptr<Node> node2 = std::make_shared<Node>();
  
  node1->next = node2;
  node2->prev = node1;  // Avoid cyclic reference with weak_ptr
```

**Operations and Methods (lock, expired)**
- `lock()`:
Returns a `std::shared_ptr` to the managed object if it still exists (i.e., if the object has not been deallocated). If the object has been destroyed, lock() returns an empty shared_ptr.

```cpp
std::shared_ptr<int> lockedPtr = weakPtr.lock();  // Returns shared_ptr if object still exists
```

- `expired()`:
Checks if the object managed by the `std::weak_ptr` has already been deallocated. It returns true if the managed object is no longer available (i.e., all shared_ptr references to it have been destroyed).

```cpp
if (weakPtr.expired()) {
    std::cout << "The object has been destroyed." << std::endl;
}
```

**Example Usage**
- Example 1: Basic Usage
Here's an example showing how std::weak_ptr is used in conjunction with std::shared_ptr to avoid circular references:

```cpp
#include <iostream>
#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // weak reference to avoid cyclic dependency
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->prev = node1;  // weak_ptr used here to avoid cyclic reference

    std::cout << "Node1 and Node2 created without circular reference." << std::endl;
    return 0;
}
```

- Example 2: Checking Object Lifetime
You can use `std::weak_ptr` to check if an object managed by `shared_ptr` still exists without affecting its lifetime:

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(100);
    std::weak_ptr<int> weakPtr = sharedPtr;

    std::cout << "Before resetting sharedPtr:" << std::endl;
    if (auto locked = weakPtr.lock()) {
        std::cout << "Object exists: " << *locked << std::endl;
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }

    sharedPtr.reset();  // Destroy the shared_ptr

    std::cout << "After resetting sharedPtr:" << std::endl;
    if (auto locked = weakPtr.lock()) {
        std::cout << "Object exists: " << *locked << std::endl;
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }

    return 0;
}
```

```Output
Before resetting sharedPtr:
Object exists: 100
After resetting sharedPtr:
Object has been destroyed.
```

**Explain**
The `lock()` method of `std::weak_ptr` returns a `std::shared_ptr` (which owns the object), but the original `std::weak_ptr` (weakPtr in your example) remains a `std::weak_ptr` and once `locked` exit our scoop lead to destroy it.


# Common Use Cases

## [Managing Dynamic Memory](#managing-dynamic-memory)
Smart pointers, especially `std::unique_ptr` and `std::shared_ptr`, provide an easy and safe way to manage dynamic memory. They ensure that the allocated memory is automatically deallocated when it's no longer needed, preventing memory leaks and dangling pointers.

#### Example:
```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

int main() {
    // Unique pointer automatically manages dynamic memory
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    return 0;
}
```

**Resource Sharing**
- `std::shared_ptr` is useful when you need to share ownership of a resource across multiple parts of your program. It allows multiple owners to hold the pointer and automatically cleans up the resource when the last shared_ptr goes out of scope.

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> ptr2 = ptr1;  // Shared ownership

    std::cout << "ptr1 and ptr2 share ownership of MyClass\n";
    return 0;
}
```

**Avoiding Cyclic Dependencies**
One common problem when using `std::shared_ptr` is cyclic dependencies, where two or more objects hold shared_ptr references to each other, preventing the objects from being deleted. This can lead to memory leaks. `std::weak_ptr` helps solve this problem by allowing you to reference an object without affecting its reference count, thus breaking the cycle.

Example:
```cpp
#include <iostream>
#include <memory>

class A;

class B {
public:
    std::shared_ptr<A> a;
};

class A {
public:
    std::shared_ptr<B> b;
};

int main() {
    // This will lead to a cyclic dependency problem
    // std::shared_ptr<A> a = std::make_shared<A>();
    // std::shared_ptr<B> b = std::make_shared<B>();
    // a->b = b;
    // b->a = a; // Memory leak!

    // Solution: Use weak_ptr to avoid the cyclic dependency
    std::shared_ptr<A> a = std::make_shared<A>();
    std::weak_ptr<B> b;  // weak_ptr does not increase reference count

    std::cout << "Cyclic dependency avoided\n";
    return 0;
}
```

**Note**
You're right in noting the difference between how destructors are called for objects on the stack and dynamically allocated objects (using pointers) on the heap. Let's break it down:

**1. Stack Allocation (Automatic Storage Duration)**
When an object is created on the stack (e.g.,` Smart_Pointer_b obj;`), its lifetime is automatically managed by the compiler. The destructor is automatically called when the scope of the object ends (i.e., when the function or block containing the object exits). This is because the object is destroyed as soon as the scope in which it was declared goes out of scope.

Example:
```cpp
void function() {
    Smart_Pointer_b obj;  // Object on the stack
    obj.print();
}  // Destructor for obj is automatically called here when function scope ends
```

**Why the Destructor is Called Automatically:**
The object is automatically destroyed when it goes out of scope, and its destructor is called as part of the stack unwinding process. This ensures that any resources (e.g., memory, file handles, etc.) the object holds are cleaned up before the object is removed from memory.

**2. Heap Allocation (Dynamic Storage Duration)**
When you use `new` to allocate memory (e.g., `Smart_Pointer_b *x = new Smart_Pointer_b();`), the object is created on the heap. This means that the object’s lifetime is not automatically tied to the scope in which it was created. You are responsible for freeing the memory used by the object, typically by calling `delete`.

Example:
```cpp
void function() {
    Smart_Pointer_b *x = new Smart_Pointer_b();  // Object on the heap
    x->print();
}  // Destructor is not called automatically; memory is not freed
```

**Why the Destructor is Not Called Automatically:** The `delete` operator is required to explicitly call the destructor and free the memory that was dynamically allocated on the heap. If you don't use `delete`, the object’s destructor is never invoked, leading to a **memory leak** because the memory used by the object is never released.
