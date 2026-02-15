# Singleton Design Pattern

---

## Q1: What is the Singleton pattern?

Its main goal is to guarantee that:

* Only one object instance exists
* All users of that class access the same instance

---

## Q23: What are common use cases for Singleton?

Singleton is commonly used for:

* Configuration managers
* Logging systems
* Routing or middleware managers
* Hardware or device controllers
* Service registries

In these cases, having multiple instances does not make sense.

---

## Q3: Why is the constructor private?

This ensures that Object creation is fully controlled by the class itself

---

## Q4: If the constructor is private, how is the object created?

Object creation is done through a **public function**, usually called `getInstance()` or `instance()`.

This function:

* Has access to the private constructor
* Is responsible for creating and returning the single instance

---

## Q6: Why must `getInstance()` be static?

`getInstance()` must be static because:

* It needs to be callable **without an existing object**
* There is no instance available before the first creation

Making it static guarantees that:

* The same access point is used everywhere
* No different objects can call it

---

## Q7: What types of `getInstance()`?

### Lazy Initialization

* The instance is created **only when `getInstance()` is called**
* If the function is never called, the object is never created

### Eager Initialization

* The instance is created **globally before `main()` starts**
* The object exists even if it is never used

The difference is **when** the instance is created, not where it is stored.

---

## Q8: How is lazy Singleton implemented?

Lazy Singleton can be implemented in two ways:

* Using a **static local object** and returning it by reference

```cpp
class Singleton {
public:
    static Singleton& instance() {
        static Singleton instance;   // function-local static
        return instance;
    }

private:
    Singleton() {}
    ~Singleton() {}   // can be private
};
```

* Using a **pointer** and allocating the object dynamically with `new`

The static-local-object approach is preferred in modern C++.

---

## Q9: How is the Singleton object destroyed?

It depends on how the instance is created:

* If the Singleton is a **static object**, destruction happens **automatically at program termination**

  * The destructor can safely be private

* If the Singleton is created using a **pointer**, then:

  * The destructor must be accessible
  * The object must be manually deleted
  * The pointer should be set to `nullptr` after deletion
  * A smart pointer (such as `unique_ptr`) can be used to manage destruction

---

## Q10: Is there any real benefit from this pattern?

Yes.
The Singleton pattern provides:

* Controlled object creation
* A single global access point
* Consistent shared state
* Reduced resource duplication

When used correctly, it simplifies design and improves maintainability.

---

## Q11: What happens in multithreaded environments?

If lazy initialization is used and **multiple threads call `getInstance()` at the same time**, multiple instances could be created.

To prevent this:

* A mutex or synchronization mechanism must be used
* Or a thread-safe initialization technique must be chosen

Modern C++ static local initialization is thread-safe by default.