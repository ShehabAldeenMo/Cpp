# **C++ Programming Concepts**

## **Table of Contents**
1. [Default Arguments](#1-default-arguments)  
2. [Overloading Functions - Polymorphism](#2-overloading-functions---polymorphism)  
3. [Signatures](#3-signatures)  
4. [Ambiguity Error](#4-ambiguity-error)  
5. [Constructor](#5-constructor)  
6. [Destructor](#6-destructor)  
7. [Constructor Without Any Code Body](#7-constructor-without-any-code-body)  
8. [Default Constructor](#8-default-constructor)  
9. [Static Attributes](#9-static-attributes)  
10. [Static Functions](#10-static-functions)  

---

## 1. **Default Arguments**
Default arguments allow functions to be called with fewer arguments than they are defined with by providing default values for some parameters. This reduces the need for multiple overloaded functions and improves code readability.

---

## 2. **Overloading Functions - Polymorphism**
Function overloading enables multiple functions with the same name but different parameter lists. This is a form of **compile-time polymorphism**, allowing the same function name to perform different tasks based on the arguments passed.

---

## 3. **Signatures**
A **function signature** is the combination of a function's name and its parameter types (number, type, and order). It is used to uniquely identify a function in C++, especially when overloading.

---

## 4. **Ambiguity Error**
An ambiguity error occurs when the compiler cannot decide which function to call due to overlapping or conflicting function signatures. This often happens with overloaded functions when their parameter lists are too similar.

---

## 5. **Constructor**
A **constructor** is a special member function automatically called when an object is created. Its purpose is to initialize the object. Constructors have the same name as the class and do not return any value.

---

## 6. **Destructor**
A **destructor** is a special member function automatically called when an object goes out of scope or is explicitly deleted. Its purpose is to release resources, clean up memory, or perform other cleanup tasks. Destructors have the same name as the class preceded by a tilde (`~`).

---

## 7. **Constructor Without Any Code Body**
Even if a constructor has no explicit code body, it still exists and is executed. It performs default initialization tasks, such as setting up the object’s memory.

---

## 8. **Default Constructor**
A **default constructor** is a constructor that takes no arguments. If no constructors are explicitly defined in a class, the compiler generates a default constructor automatically. If any constructor is explicitly defined, the default constructor is not provided automatically.

---

## 9. **Static Attributes**
Static attributes (or static member variables) are shared among all instances of a class. They belong to the class itself, not to any individual object. Static attributes are declared with the `static` keyword and are initialized outside the class definition.

---

## 10. **Static Functions**
Static functions are member functions that do not operate on specific instances of a class. They can access static attributes but cannot access non-static attributes or call non-static functions. Static functions are called using the class name instead of an object.

---

This document provides a concise overview of the listed concepts in C++ for better understanding and reference.
