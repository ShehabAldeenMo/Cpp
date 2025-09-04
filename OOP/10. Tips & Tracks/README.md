### ❓ 1. **Why doesn't C++ allow creating `const static` member functions?**

#### 🔹 Explanation:

* A `const` member function in C++ **promises not to modify the object** it’s called on.

* `const` applies to the **implicit `this` pointer** (which is a pointer to the object instance), like this:

  ```cpp
  void func() const;  // Means: void func(MyClass* const this)
  ```

* But a **`static` member function**:

  * Belongs to the class itself, **not to any object instance**.
  * Therefore, it has **no `this` pointer** at all.

#### 🧠 So:

Declaring a static function as `const` makes no sense, because:

* There is no object instance (`this`) involved.
* There’s **nothing to mark as const**.

#### 🚫 Example (invalid):

```cpp
class A {
public:
    static void func() const;  // ❌ Error: 'static' and 'const' cannot be combined
};
```

---

### ❓ 2. **Why can't we use `this` to access a `static` member?**

#### 🔹 Explanation:

* As mentioned above, `this` is a **pointer to the current instance of a class**.
* But `static` members:

  * Exist independently of any object instance.
  * Are **shared** across all objects of the class.
  * Belong to the **class**, not any one object.

#### 🚫 So, accessing static members using `this` is **not allowed** in standard C++:

```cpp
class MyClass {
    static int count;
public:
    void foo() {
        this->count = 10;  // ❌ Error: invalid use of 'this' for static member
    }
};
```

#### ✅ Correct way:

Use the class name directly:

```cpp
MyClass::count = 10;
```

> ⚠️ Some compilers might *allow* access using `this->count`, but it’s **not recommended** and **not portable**, because it's semantically misleading.

---

### ✅ Summary:

| Feature                               | Reason it's not allowed                                               |
| ------------------------------------- | --------------------------------------------------------------------- |
| `const static` member functions       | `static` has no `this` → `const` is meaningless                       |
| Using `this` to access static members | `this` is for instance data → `static` doesn't belong to any instance |

Let me know if you want visual code examples or compiler error messages!



## Encapsulation
- Encapsulate all the data members & member functions within one single capsule
  - Gives you more control over coupling in your code
  - With data-hiding: Helps hide the implementation details from users
  - Also reduce the complexity

Encapsulation
Class → Methods | Variable


## Abstraction
- Getters & Setters
  - Don’t just generate setters & getters for every field!
    - Think twice what to provide
  - "Don’t ask for the information you need to do the work; ask the object that has the information to do the work for you"
  - Depend on them even inside the class. Is this slower? No, compiler optimization helps
- Separate implementation: What vs How (+ use header files)
- Abstraction is about
  - hiding unwanted details
  - while showing most essential
  - in a given context

# Inheritance and Composition
- Allows building hierarchy of classes and relations
- Composition: **has-a** relationship
  - A building has floors. A floor has apartments.
  - A car **has-an** engine and has 4-wheels
- Inheritance: **is-a** relationship
  - Manager **is-an** employee
  - Student **is-a** person
  
# Inheritence Types
1. Single Inheritance.
2. Multiple Inheritence.
3. Multilevel Inheritence.
4. Hierarical Inheritence.
5. Hybrid Inheritence.
- You can only initialize base class members like name through the base class constructor initializer, not directly from derived class initializer list.
- use **final** to prevent Inheritence from this class.

- Overloading: 2+ methods
  - Same class
  - Same name but different parameters
  - A::f1, f2, f3
- Overriding:
  - Between superclass and subclass
  - Same name and same parameters
  - A::f1 vs B::f1
  - A::f1(int) vs B::f1(int)
  - A::f1(int,int) vs B::f1(int)


- all functions are pure means interfaces and also could fall into diamond problem.

- casting child to parent, the is-a relation, is called Upcasting
- cast down the parent class to a child class

-  a reference cannot be null , A reference in C++ is not like a pointer. Once a reference is bound to an object, it must refer to a valid, existing object. The language guarantees that

- Every class containing abstract method must be declared abstract. (true/false)
If a class has at least one pure virtual function in C++ (or an abstract method in Java), it must be declared abstract

- Abstract class can have static methods. (true/false)
Static methods do not depend on object instances, so they are allowed in abstract classes.

- Abstract class can be initialized. (true/false)
You cannot directly instantiate an abstract class. You can create pointers or references to abstract classes, but not objects.

- Which of the following in Object Oriented Programming is supported by Function overloading and default arguments features of C++.
A) Inheritance
B) Polymorphism  (true)
C) Encapsulation
D) None of the above


- Since count is static, it is not counted in **sizeof** for class.

Great! Let's break this down **step by step** so you understand what's happening **clearly**:

---

### 🧾 Code Overview

```cpp
class Base { };
class Derived : public Base { };

int main() {
    Derived d;
    try {
        throw d; // throw a Derived object
    }
    catch (Base b) {
        cout << "Caught Base Exception";
    }
    catch (Derived d) {
        cout << "Caught Derived Exception";
    }
    return 0;
}
```

---

### 🧠 Key Concepts

#### 1. **Exception Handling in C++** works based on **types**

When you do `throw d;`, the compiler looks for a `catch` block with a **matching or compatible** type.

#### 2. **Object Slicing** occurs when you pass a derived object **by value** to a base class.

Example:

```cpp
Base b = d; // Slicing: Derived part is cut off.
```

#### 3. Catch blocks by **value** cause slicing.

So, in:

```cpp
catch (Base b) { ... }
```

You are **catching by value**, which means:

* `Derived d` is thrown,
* then **sliced down to Base** when matched with `catch (Base b)`

That means:

* The object is caught as a **Base** type,
* So the `catch (Derived d)` **never runs** (because slicing already matched it to the Base version).

---

### ✅ Output:

```
Caught Base Exception
```

---

### 🔍 What if we change it to catch by reference?

```cpp
catch (Base& b) {
    cout << "Caught Base Exception";
}
catch (Derived& d) {
    cout << "Caught Derived Exception";
}
```

Now, the object is not sliced. So `catch (Derived& d)` matches the exception more precisely.

#### Output:

```
Caught Derived Exception
```

---

### 💡 Summary:

| Code                          | Behavior                                 |
| ----------------------------- | ---------------------------------------- |
| `catch(Base b)`               | Causes slicing; only base part is caught |
| `catch(Base& b)`              | No slicing; dynamic type considered      |
| `throw d`                     | Throws a **Derived** object              |
| Matching starts top to bottom | First match is used                      |

---

### ✅ Best Practice:

Always catch polymorphic (inherited) exceptions by **reference** to avoid slicing:

```cpp
catch (const Base& b) { ... }
```