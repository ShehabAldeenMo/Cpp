# **Understanding Object-Oriented Programming (OOP) in C++**

## 1. **Cons of Function-Oriented Code**
- Lack of data security due to reliance on global data.
- Limited reusability leads to code duplication.
- Challenging maintenance as dependencies grow complex.
- Poor scalability when adding new features.
- Difficulty mapping to real-world entities.

## 2. **How Objects Overcome These Cons**
- Encapsulation ensures data security by combining data and functions.
- Modularity simplifies maintenance and debugging.
- Reusability through inheritance reduces code duplication.
- Real-world mapping makes the design intuitive.
- Scalability allows new features without breaking existing code.

## 3. **Key Principles of OOP**
1. **Encapsulation**: Hides internal details and exposes necessary functionality.
2. **Inheritance**: Allows one class to inherit properties and behaviors from another.
3. **Polymorphism**: Enables objects to behave differently based on their type.
4. **Abstraction**: Focuses on essential details while hiding implementation complexity.

## 4. **Understanding Inheritance**
Inheritance creates a hierarchy where a derived class inherits attributes and behaviors of a base class.

### Types of Inheritance:
- Single: Derived class inherits from one base class.
- Multiple: Class inherits from multiple base classes.
- Multilevel: Class inherits from another derived class.
- Hierarchical: Multiple classes inherit from a single base class.
- Hybrid: Combination of multiple and multilevel inheritance.

## 5. **Polymorphism**
Polymorphism enables different behaviors for the same function depending on the object. It can be:
- Compile-time: Using function or operator overloading.
- Runtime: Using virtual functions and inheritance.

**Function Signature**: Includes function name and parameter types, ensuring consistency when overriding.

## 6. **Encapsulation**
Encapsulation groups data and methods in a class, restricting direct access using access specifiers (`private`, `protected`, `public`). It enhances security and maintains control over class behavior.

## 7. **Abstraction**
Abstraction highlights essential features while concealing implementation details. Achieved through abstract classes or interfaces, it simplifies complex systems and focuses on functionality.

## 8. **Advantages of OOP**
- **Modularity**: Easier to maintain and debug.
- **Reusability**: Classes and methods can be reused across projects.
- **Scalability**: Adapts well to growing project requirements.
- **Real-World Mapping**: Intuitive design aligned with real-world entities.
- **Data Security**: Restricts access to sensitive data.
- **Flexibility**: Extends functionality with minimal changes.
