# **C++ Advanced Concepts**

## **Table of Contents**

1. [Friend Functions](#1-friend-functions)  
2. [Passing Objects to a Function](#2-passing-objects-to-a-function)  

---

## 1. **Friend Functions**

A **friend function** is a unique function in C++ with the following characteristics:  

### Key Features:  
- **Stand-alone Function**: Unlike member functions, a friend function is not part of the class it operates on.  
- **Access to Private and Public Members**: It can access both private and public members of the class it is declared as a friend to.  
- **Encapsulation Violation**: While offering flexibility, friend functions can be seen as violating encapsulation because they bypass the access restrictions of a class.  
- **Declaration Inside the Class**: To make a function a friend, it must be explicitly declared as such inside the class.  
- **Shared Friendship**: A friend function can be declared as a friend for multiple classes, granting it access to their private and protected members.  

### Friendship Between Classes:
- **Classes as Friends**: One class can declare another class as a friend. This allows all member functions of the friend class to access the private and protected members of the declaring class.  
- **How?**: To declare a class as a friend, use the `friend` keyword inside the declaring class. For example, `class A` can declare `class B` as its friend, granting `class B` access to `class A`'s private members.  

---

## 2. **Passing Objects to a Function**

### Common Practices for Passing Objects:
Objects in C++ can be passed to functions in various ways, such as by value, by reference, or by pointer. Each method has its implications, especially when dealing with dynamic memory.

---

### **Bitwise Copy**:
When an object is passed by value to a function, a **bitwise copy** of the object is created. This process involves copying all the bits from the source object to the new copy. However, this method can lead to issues, especially with dynamic memory.

---

### **Dynamic Area Problem**:
**Issue**:  
If the object being passed to a function manages dynamic memory (e.g., through pointers), the copied object will share the same memory as the original object. When the function exits, the copied object is destroyed, leading to the deletion of the shared dynamic memory. This results in undefined behavior when the original object later tries to access the same memory.  

**Example**:  
An object contains a pointer to a dynamically allocated array. When this object is passed by value to a stand-alone function, the copied object is destructed upon exiting the function, deleting the array. The original object is left with a dangling pointer.

![image](https://github.com/user-attachments/assets/13dd9485-06ba-4505-a685-c32fbc9b9015)

- At function termination, The bitwise coping allocation object will call destructor of class and free array address.
- 
---

### **Dynamic Area Problem Solutions**:

1. **Passing by Reference**:  
   Instead of creating a copy, the function operates directly on the original object by passing it by reference. This approach avoids the destruction of any shared dynamic memory. at the end of function will remove the new reference but the object will remain the same.

![image](https://github.com/user-attachments/assets/537eacca-88c2-40a7-bc17-503925067fe2)


2. **Copy Constructor**:  
   A copy constructor is a special constructor used to create a deep copy of an object. It ensures that the dynamic memory is not shared between the original and the copied object, but rather each object manages its own separate memory.

![image](https://github.com/user-attachments/assets/a6947895-ba09-496f-9a9d-9e1e5387408f)

![image](https://github.com/user-attachments/assets/823d7286-6836-49d4-ab82-2a63bb916e10)

Then the steps will be:
![image](https://github.com/user-attachments/assets/2e05096b-4c64-4249-8072-055456936a19)
![image](https://github.com/user-attachments/assets/40839ce2-f6da-493b-a002-1f219afd0602)
![image](https://github.com/user-attachments/assets/a5499382-afbc-4617-8df3-233268dd2653)


---

### **When to Use a Copy Constructor?**

1. **Passing an Object by Value**:  
   When an object is passed by value to a function, the copy constructor is invoked to create a duplicate.  

2. **Creating a New Object from an Existing One**:  
   When a new object is initialized from another object, the copy constructor ensures that a proper copy is made.  

3. **Returning an Object by Value**:  
   When a function returns an object by value, the copy constructor ensures that the returned object is properly constructed.  

