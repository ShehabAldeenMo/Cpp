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

![image](https://github.com/user-attachments/assets/8e0fc903-8fb0-40e2-8f42-e37482c96521)

  - Similarly, destructors are called in reverse order: the child destructor is executed first, followed by the base class destructor.

![image](https://github.com/user-attachments/assets/8c2f8c42-1cf7-4bc9-b9e8-4a6e6c9a79ea)

### Eaxmple
- Dog is **kind of** animals.

![image](https://github.com/user-attachments/assets/a61a1ea2-71c6-4d31-bf68-90f0f2988b91)

- Car **is-a** a vehicle   
- Company positions

![image](https://github.com/user-attachments/assets/24d89f51-64d7-434a-ad54-475ebb5f0d0f)

- **Notes**
  - You can ask you some question to helps you to define the direction of inheritence, Which have the bigger size + which contain the another + which is **is-a** relation ? all of theses questions will help you to define the inheritence directoin.

- **Accessibility**:
  - The child class inherits all members of the base class but with limited accessibility based on the access specifiers (`private`, `protected`, `public`).

![image](https://github.com/user-attachments/assets/4e292f55-e685-49b5-a78c-5bd885d54795)
![image](https://github.com/user-attachments/assets/a28bc51a-7ed2-4617-b868-fc8f49db6f0c)
![image](https://github.com/user-attachments/assets/8999c3f8-1005-4e11-bf6f-3f49a656b314)
    
- **Private Members**: Not accessible directly in the child class.

- **Notes**
  - Object from derived class can access methods of base class
    
![image](https://github.com/user-attachments/assets/9fc02762-26f5-4f8f-8dd2-4a11e7ee2426)

---

## 2. Access Specifiers
Access specifiers define the level of access control for class members in C++:

- **Private**:
  - Members declared as `private` are accessible only within the class in which they are declared.
  - They are not inherited directly by child classes.
- **Protected**:
  - Members declared as `protected` are accessible **within the class** and **by child** classes through **inheritance**.
- **Public**:
  - Members declared as `public` are accessible anywhere the object is visible, including outside the class.

---

## 3. Polymorphism (Function Overriding)
Polymorphism allows functions to behave differently based on the object that calls them, primarily within an **inheritance hierarchy**.

### Key Characteristics:
- **Inheritance Tree**: Function overriding occurs among functions in the **inheritance tree**, not within the same class.
- **Signature**: The derived class must have a function with the same signature as the base class function.
- **Access Specifier Rules**:
  - Accessibility should be **increased or maintained** in the derived class. **For example**, a `protected` function in the base class can become `protected` or `public` in the derived class.
    
 ![image](https://github.com/user-attachments/assets/d70a6bee-3989-46c9-ac27-9b8328a24851)

### Special Cases:
- **Base-to-Derived Function Argument**:
  - It's a great method in independent functions calls to have the flexbility to use base or dervied instance accroding to what you pass to it, How ?
  - A function taking a base type can accept both base and derived objects.
  - A function taking a derived type can only accept derived objects.

![image](https://github.com/user-attachments/assets/fea5f6c2-81c2-48b0-84ba-51d40ff336d7)
![image](https://github.com/user-attachments/assets/206bd956-09d0-41d3-99a7-26f3a2094cc8)
  
- **Parent Pointer to Child**:
  - A pointer of the base class type can point to a derived class object, but it only accesses the base class functionality.

![image](https://github.com/user-attachments/assets/624c8ea6-fe8c-4886-86fe-4f7d4ad93d1e)

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
