# **Object Allocation and Class Relationships in C++**

## **Table of Contents**
1. [Object Allocation: Static vs. Dynamic](#1-object-allocation-static-vs-dynamic)  
2. [Association](#2-association)  
3. [Aggregation](#3-aggregation)  
4. [Composition](#4-composition)  

---

# **Object Allocation and Class Relationships in C++**

## **1. Object Allocation: Static vs. Dynamic**

Objects in C++ can be allocated either **statically** or **dynamically**, depending on the desired lifetime and memory management:

- **Static Allocation**:
  - Objects are created and managed like normal variables in C-style code.
  - Each object automatically calls its constructor during allocation.
  - Lifetime is tied to the scope in which the object is declared.

- **Dynamic Allocation**:
  - Objects are allocated in the **heap memory** using pointers.
  - Allocation can be for a **single object** or an **array of objects**.
  - Requires explicit deallocation to free memory and avoid leaks.

---

## **2. Association**

**Association** represents a loose relationship between two classes, where one class interacts with another without owning it. Key characteristics include:

- It is a simple connection between two classes, such as passing one class object as a parameter to a function in another class.
- Each class has its own **independent lifecycle**.
- Classes can be created or deleted without affecting each other.

### Examples:
- **Seminar Class and Courses Class**:
  - A seminar class may reference a course, but deleting the course does not affect the seminar.
- **Files and Browsers**:
  - Files with links to platforms like YouTube or Facebook. Deleting the file does not mean deleting the browser.

---

## **3. Aggregation**

**Aggregation** is a specialized form of association where one class has a **soft ownership** relationship with another. Key characteristics include:

- Both classes have their own lifecycle and can exist independently.
- Aggregation implies a "whole-part" relationship where the part can still function independently of the whole.

### Examples:
- **Lecture Room and Tables**:
  - A lecture room contains tables, but removing a few tables does not mean the lecture room ceases to exist.
- **Employees and Company**:
  - A company has many employees, but employees can be created and replaced during runtime. 
  - An instance of the employee class is often defined in the company class, yet they remain independent entities.

**Summary**:
- Part class can operate independently (e.g., employees without the company).
- Container class's is not meaning anything without this part but could be acceptable with few of these parts.

**Notes**:
- In aggregation parts classes appears in pointers in privte variables and in constructor. If they appear in method will be regarded as association. 

---

## **4. Composition**

**Composition** is a stronger form of aggregation where the lifetime of one class is tightly bound to the other. Key characteristics include:

- **Dependency**: When the parent object is created, the part is created. When the parent is destroyed, the part is destroyed.
- It implies a **whole-part relationship** with strict ownership.

### Examples:
- **Room and Walls**:
  - A room cannot exist without its walls, and deleting the room deletes the walls.
- **Car and Engine**:
  - A car inherently includes an engine, and both are tightly coupled.
- **Folder and Files**:
  - Deleting a folder also deletes all the files contained within it.

**Note**: 
- All compositions are aggregations, but not all aggregations are compositions.

## **5. Constructor and Destructor Call Order**

In the context of **relationships** like composition and aggregation, the order in which constructors and destructors are called is crucial:

- **Constructor Call Order**:
  - The **parts** of a class are constructed **before** the container.
  - Example: If a car has an engine, the engine’s constructor is called before the car's constructor.

- **Destructor Call Order**:
  - The **container** is destructed **before** the parts.
  - Example: When a car is deleted, the car's destructor is called before the engine's destructor.

This ensures proper initialization and cleanup of resources in tightly coupled relationships.

---
