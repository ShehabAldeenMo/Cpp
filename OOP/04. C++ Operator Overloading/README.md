# **C++ Operator Overloading**

## **Table of Contents**

1. [Introduction to Operator Overloading](#1-introduction-to-operator-overloading)  
2. [Why Use Operator Overloading?](#2-why-use-operator-overloading)  
3. [Examples of Operator Overloading](#3-examples-of-operator-overloading)  
   - [Arithmetic Operators](#arithmetic-operators)  
   - [Relational Operators](#relational-operators)  
   - [Assignment Operators](#assignment-operators)  
   - [Stream Insertion and Extraction Operators](#stream-insertion-and-extraction-operators)  

---

## 1. **Introduction to Operator Overloading**

Operator overloading in C++ allows developers to redefine the behavior of standard operators for user-defined types. This feature enables objects of a class to interact using operators just like fundamental data types, improving code readability and intuitiveness.

---

## 2. **Why Use Operator Overloading?**

### Key Benefits:
- **Intuitive Syntax**: Makes custom data types work seamlessly with standard operators, enhancing the natural feel of operations.
- **Improved Code Readability**: Simplifies complex expressions involving objects by using familiar operators.
- **Flexibility in Object Interaction**: Allows user-defined types to integrate into mathematical, relational, or stream-based operations.
- **Abstraction**: Hides implementation details behind intuitive syntax, making the code cleaner and easier to use.

---

## 3. **Examples of Operator Overloading**

### **Arithmetic Operators**
Overloading arithmetic operators (`+`, `-`, `*`, `/`) allows objects to perform mathematical operations.  
**Example**: Overloading `+` to add two `Vector` objects, resulting in a new `Vector` object representing the sum of the two vectors.

---

### **Relational Operators**
Relational operators (`==`, `<`, `>`, `<=`, `>=`, `!=`) can be overloaded to compare objects.  
**Example**: Overloading `==` to compare two `ComplexNumber` objects, checking if their real and imaginary parts are equal.

---

### **Assignment Operators**
Overloading the assignment operator (`=`) enables deep copying for objects managing dynamic memory or other resources.  
**Example**: Overloading `=` to assign the contents of one `Matrix` object to another, ensuring proper handling of dynamic arrays within the object.

---

### **Stream Insertion and Extraction Operators**
Stream operators (`<<`, `>>`) can be overloaded to simplify input and output operations for objects.  
**Example**: Overloading `<<` for a `Point` class to print its coordinates in a user-friendly format like `(x, y)`.

---

Operator overloading enhances the versatility and usability of user-defined types, enabling them to behave more like built-in data types and improving the overall programming experience.
