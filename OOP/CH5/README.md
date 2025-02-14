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

![image](https://github.com/user-attachments/assets/85dde3ae-e8ed-4e23-897a-355ae00f6683)
![image](https://github.com/user-attachments/assets/c89ef9f6-933d-4d13-bde2-b7ef94fe9b01)
![image](https://github.com/user-attachments/assets/17c1adbd-0010-4d7b-bcd2-0c03f1d89f5d)
![image](https://github.com/user-attachments/assets/77352da4-0c18-42b5-b147-4670e02e290f)

   
- **Files and Browsers**:
  - Files with links to platforms like YouTube or Facebook. Deleting the file does not mean deleting the browser.

---

## **3. Aggregation**

**Aggregation** is a specialized form of association where one class has a **soft ownership** relationship with another. Key characteristics include:
![image](https://github.com/user-attachments/assets/1c0cb757-30b4-425b-8eb0-d97c1af4415a)

- One of classes have its own lifecycle and can exist independently.
- Aggregation implies a "whole-part" relationship where the part can still function independently of the whole.
![image](https://github.com/user-attachments/assets/affc4d4b-e4a0-4fe6-8531-f627add2d76f)


### Examples:
- **Lecture Room and Tables**:
  - A lecture room contains tables, but removing a few tables does not mean the lecture room deletion.

![image](https://github.com/user-attachments/assets/850305e0-9e12-43f6-98f6-99e9b8869aca)

- **Employees and Company**:
  - A company has many employees, but employees can be created and replaced during runtime.

![image](https://github.com/user-attachments/assets/fb9b16b9-c863-45fc-8187-b791f1259cf5)

**Summary**:
- Part class can operate independently (e.g., employees without the company).
- Container class's is not meaning anything without this part but could be acceptable with few of these parts.

**Notes**:
- In aggregation parts classes appears in pointers in **Private Variables** and in constructor. If they appear in methods only will be regarded as association.
- aggregation is association with owned variables into private sections.

---

## **4. Composition**

**Composition** is a stronger form of aggregation where the lifetime of one class is tightly bound to the other. Key characteristics include:

![image](https://github.com/user-attachments/assets/dcb8ab29-56f7-40e9-b094-5587b0305dbb)


- **Dependency**: When the parent object is created, the part is created. When the parent is destroyed, the part is destroyed.
- It implies a **whole-part relationship** with strict ownership.

### Examples:
- **Home and Rooms**:
  - A home cannot exist without its rooms, and deleting the home deletes the rooms.

![image](https://github.com/user-attachments/assets/f168ac86-1f62-4d9f-ab3b-79091a4b8e15)
![image](https://github.com/user-attachments/assets/81b1954e-fd40-4e6f-bf52-3f14d6f2adce)
![image](https://github.com/user-attachments/assets/3c7c7205-3471-4b5c-b000-b305afc21228)
![image](https://github.com/user-attachments/assets/bf7b4162-c077-4d1f-8907-4ef89f71cc48)

As shown in the previous, we construct Homw first without calling any object from rooms. 
  
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
