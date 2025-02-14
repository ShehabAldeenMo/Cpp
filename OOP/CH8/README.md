# C++ Concepts and Examples

## Table of Contents
1. [Object Behavior with Base and Derived Pointers](#object-behavior-with-base-and-derived-pointers) <br/>
   1.1 [Pointer to Derived Object](#pointer-to-derived-object) <br/>
   1.2 [Pointer to Base Object Accessing Derived Object](#pointer-to-base-object-accessing-derived-object) <br/>

2. [Dynamic Binding](#dynamic-binding) <br/>
   2.1 [Using `virtual` Keyword](#using-virtual-keyword) <br/>
   2.2 [V-Table Mechanism](#v-table-mechanism) <br/>
   
3. [Usage of Dynamic Binding](#usage-of-dynamic-binding) <br/>
   3.1 [GeoShape Example with Dynamic Binding](#geoshape-example-with-dynamic-binding) <br/>
   3.2 [Sum Areas Function](#sum-areas-function) <br/>
   3.3 [Abstract Class and Pure Virtual Functions](#abstract-class-and-pure-virtual-functions) <br/>

---

## 1. Object Behavior with Base and Derived Pointers

### 1.1 Pointer to Derived Object
```cpp
Base:
+ m1();

Derived:
+ m1();
+ m2();

int main() {
    Derived obj;
    Derived* ptr;
    obj.m1();          // Derived
    obj.Base::m1();    // Base
    obj.m2();          // Derived

    ptr = &obj;
    ptr->m1();         // Derived
    ptr->Base::m1();   // Base
    ptr->m2();         // Derived
}
```

### 1.2 Pointer to Base Object Accessing Derived Object
```cpp
Derived obj;
Base* ptr;

ptr = &obj;    // Access Base portion only
ptr->m1();     // Calls Base version of m1()
ptr->m2();     // Compiler error: m2() not in Base

```

## 2. Dynamic Binding
### 2.1 Using `virtual` Keyword

```Cpp
Base:
+ virtual m1();
+ m2();

Derived:
+ virtual m1();
+ m2();

Second:
+ m1();
+ m2();

```

### Dynamic Binding Examples

```Cpp
Base *ptr;

Base o1;

Derived o2;

Second o3;
```

```Cpp
// Case 1 
ptr = &O1;
ptr->m1();
ptr->m2();
```

|Case 1|Compile-Time Behavior  | Runtime Behavior        |
|------|-----------------------|-------------------------|
| m1   |       `Base`          | `static Binding Know`   |
| m2   |       `Base`          | `From Compile Time`     |


```Cpp
// Case 2
ptr = &O2;
ptr->m1();
ptr->m2();
```

|Case 2|Compile-Time Behavior  | Runtime Behavior        |
|------|-----------------------|-------------------------|
| m1   |  `Check at Base`      | `Derived-Late Binding`  |
| m2   |  `Check at Base`      | `Base-Static Binding`   |

```Cpp
// Case 3
ptr = &O3;
ptr->m1();
ptr->m2();
```

|Case 3|Compile-Time Behavior  | Runtime Behavior        |
|------|-----------------------|-------------------------|
| m1   |  `Check at Base`      | `Second-Late Binding`   |
| m2   |  `Check at Base`      | `Base-Static Binding`   |


```Cpp
Derived *ptr;

Base o1;

Derived o2;

Second o3;
```

```Cpp
// Case 4
ptr = &O3;
ptr->m1();
ptr->m2();
```

|Case 4|Compile-Time Behavior  | Runtime Behavior        |
|------|-----------------------|-------------------------|
| m1   |  `Check at Derived`   | `Second-Late Binding`   |
| m2   |  `Check at Derived`   |`Derived-Static Binding` |


---

### 2.2 V-Table Mechanism

- Build at the compile time for overriding functions in it.
- Put static Binding in it at the compile time.
- Put dynamic Binding at the run time.
- Load the table at the run time.
- The pointer always refers to the last implemented function for running object in the table.

![image](https://github.com/user-attachments/assets/56b389eb-980c-4a94-9153-3117c6b7fe88)

- That will help us to make standalone functions  

![image](https://github.com/user-attachments/assets/441a219f-e82e-4d8e-986a-a1e39c63ee85)

---

## 3. Usage of Dynamic Binding
### 3.1 GeoShape Example with Dynamic Binding

```Cpp
class GeoShape {
    ... // side implementation
    ... // side implementation
    ... // side implementation
    virtual float calculateArea() 
    { 
        return 0; 
    }
};

GeoShape* p;
Circle c(10);
Rect r(30, 40);
Triangle t(100, 150);
Square s(60);

p = &c; p->calculateArea(); // Circle Area
p = &r; p->calculateArea(); // Rect Area
p = &t; p->calculateArea(); // Triangle Area
p = &s; p->calculateArea(); // Square Area
```

| Pointer Assignment | Called Method               |
|--------------------|-----------------------------|
| `p = &c`           | `Circle::calculateArea()`   |
| `p = &r`           | `Rect::calculateArea()`     |
| `p = &t`           | `Triangle::calculateArea()` |
| `p = &s`           | `Square::calculateArea()`   |


### 3.2 Sum Areas Function

- Add standalone function to sum areas of any three `Geoshapes`.
- helps you to create a general standalone function with fixed implementation but could 
  pass any instances from inherited classes with dynamic binding and make its right purposes
  in caculating area or anything.

```Cpp

float sumAreas(GeoShape* p1, GeoShape* p2, GeoShape* p3) {
    return p1->calculateArea() + p2->calculateArea() + p3->calculateArea();
}

int main() {
    Triangle myT(20, 10);
    Rect myR(2, 5);
    Circle myC(5);

    std::cout << sumAreas(&myT, &myR, &myC) << std::endl;// order of passing not fixed. WoW
}
```

### 3.3 Abstract Class and Pure Virtual Functions

```Cpp
virtual float calculateArea() = 0;
```

+ Can not make object from `Geoshape`. as it's a virtual function.
+ Now Geoshape is abstract class as it contains at least one pure virtual function.
+ Any class can inherit abstract class.
+ when inheritance from abstract the child must implement all the pure virtual functions of his base or it will be converted from concrete class to abstract one.
+ Pure virtual function should be implemented in the leaf of the tree at least one.
