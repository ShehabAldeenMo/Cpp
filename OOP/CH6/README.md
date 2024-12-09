# C++ Programming Concepts

## Table of Contents
1. [Inheritance](#1-inheritance)
2. [Access Specifiers](#2-access-specifiers)
3. [Polymorphism (Function Overriding)](#3-polymorphism-function-overriding)
4. [Multi-Level Inheritance](#4-multi-level-inheritance)

---

## 1. Inheritance
Inheritance is a mechanism in object-oriented programming that allows a class to inherit properties and behavior from another class. Key points include:

- **"Is-a" or "Kind-of" Relationship**: Represents a hierarchical relationship where the child class is a specialized version of the base class.
- **Code Reusability**: Inheritance reduces redundancy by reusing existing code and adding new functionality.
- **Constructors and Destructors**:
  - Creating an object of a child class automatically calls the constructor of the base class first, followed by the child class constructor.
  - Similarly, destructors are called in reverse order: the child destructor is executed first, followed by the base class destructor.
- **Accessibility**:
  - The child class inherits all members of the base class but with limited accessibility based on the access specifiers (`private`, `protected`, `public`).
  - **Private Members**: Not accessible directly in the child class.
- Inheritance leverages commonality among objects to simplify and extend functionality.

---

## 2. Access Specifiers
Access specifiers define the level of access control for class members in C++:

- **Private**:
  - Members declared as `private` are accessible only within the class in which they are declared.
  - They are not inherited directly by child classes.
- **Protected**:
  - Members declared as `protected` are accessible within the class and by child classes through inheritance.
- **Public**:
  - Members declared as `public` are accessible anywhere the object is visible, including outside the class.

---

## 3. Polymorphism (Function Overriding)
Polymorphism allows functions to behave differently based on the object that calls them, primarily within an inheritance hierarchy.

### Key Characteristics:
- **Inheritance Tree**: Function overriding occurs among functions in the inheritance tree, not within the same class.
- **Signature**: The derived class must have a function with the same signature as the base class function.
- **Access Specifier Rules**:
  - Accessibility should be increased or maintained in the derived class.
  - For example, a `protected` function in the base class can become `protected` or `public` in the derived class.
- **Function Selection**:
  - The derived function overrides the base function when accessed through an instance of the derived class.
  - Using a base pointer or reference to call the function only invokes the base class implementation unless overridden with `virtual`.

### Special Cases:
- **Base-to-Derived Function Argument**:
  - A function taking a base type can accept both base and derived objects.
  - A function taking a derived type can only accept derived objects.

- **Parent Pointer to Child**:
  - A pointer of the base class type can point to a derived class object, but it only accesses the base class functionality.

---

## 4. Multi-Level Inheritance
Multi-level inheritance refers to a hierarchy where a class is derived from a class that is itself derived from another class.

### Explanation:
- Class A (Base Class) → Class B (Derived from A) → Class C (Derived from B).
- Each level in the inheritance hierarchy adds its own functionality while inheriting features from the previous level.
- **Construction and Destruction**:
  - Constructors are called in order of inheritance: from the base class to the most derived class.
  - Destructors are called in reverse order: from the most derived class back to the base class.

### Benefits:
- Multi-level inheritance allows for progressive specialization and builds complex hierarchies by reusing and extending code at each level.
