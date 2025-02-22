# Table of Contents

1. **[Introduction to Design Patterns](#introduction-to-design-patterns)**
   - [What are Design Patterns?](#what-are-design-patterns)
   - [Why Use Design Patterns?](#why-use-design-patterns)
   
2. **[Types of Design Patterns](#types-of-design-patterns)**
   - [Creational Patterns](#creational-patterns)
   - [Structural Patterns](#structural-patterns)
   - [Behavioral Patterns](#behavioral-patterns)

3. **[Creational Design Patterns](#creational-design-patterns)**
   - [Singleton Pattern](#singleton-pattern)
   - [Factory Method Pattern](#factory-method-pattern)
   - [Abstract Factory Pattern](#abstract-factory-pattern)
   - [Builder Pattern](#builder-pattern)
   - [Prototype Pattern](#prototype-pattern)

4. **[Structural Design Patterns](#structural-design-patterns)**
   - [Proxy Pattern](#proxy-pattern)
   - [Adapter Pattern](#adapter-pattern)
   - [Decorator Pattern](#decorator-pattern)
   - [Facade Pattern](#facade-pattern)
   - [Composite Pattern](#composite-pattern)

5. **[Behavioral Design Patterns](#behavioral-design-patterns)**
   - [Observer Pattern](#observer-pattern)
   - [Strategy Pattern](#strategy-pattern)
   - [Command Pattern](#command-pattern)
   - [State Pattern](#state-pattern)
   - [Iterator Pattern](#iterator-pattern)
   - [Template Method Pattern](#template-method-pattern)
   - [Memento Pattern](#memento-pattern)

# Introduction to Design Patterns

## What are Design Patterns?

Design patterns are reusable solutions to common problems that occur within a given context in software design. They represent best practices that have been proven to work and solve specific design issues. Rather than reinventing the wheel every time, developers can apply these tried-and-tested solutions, which help in writing efficient, maintainable, and scalable code.

A design pattern isn't a specific piece of code but rather a description or template for solving a problem that can be used in many different situations. They offer general solutions to commonly occurring problems in object-oriented design.

There are several well-established types of design patterns, each suited to different kinds of issues and scenarios in software development.

## Why Use Design Patterns?

Design patterns offer several advantages:

- **Reusability**: Design patterns provide reusable solutions that can be used across multiple projects, saving time and effort.
- **Maintainability**: They encourage clean, understandable, and maintainable code, which is easier to modify and debug.
- **Scalability**: Design patterns provide a framework for handling changes in the system, making it easier to scale and grow.
- **Communication**: Since design patterns are widely known, they provide a common language for developers to discuss and collaborate on solutions.
- **Best Practices**: Using design patterns encourages best practices, making software development more efficient and reliable.

While design patterns are powerful, it’s important not to use them unnecessarily. Sometimes, applying a pattern to a situation may introduce unnecessary complexity.

---

# Types of Design Patterns

Design patterns can be broadly classified into three categories based on their purpose:

## Creational Patterns

Creational design patterns deal with object creation mechanisms. They abstract the instantiation process to make it more flexible and dynamic. These patterns help in creating objects in a manner suitable to the situation. The key goal is to avoid the complexities of directly using the `new` keyword and ensure that object creation is well-controlled.

Some common examples of creational patterns include:

- **Singleton Pattern**: Ensures that a class has only one instance and provides a global point of access to that instance.
- **Factory Method Pattern**: Defines an interface for creating objects but allows subclasses to alter the type of objects that will be created.
- **Abstract Factory Pattern**: Provides an interface for creating families of related or dependent objects without specifying their concrete classes.
- **Builder Pattern**: Allows for the step-by-step creation of complex objects and separates the construction process from the final object.
- **Prototype Pattern**: Creates new objects by copying an existing object, known as the prototype.

## Structural Patterns

Structural patterns focus on how objects and classes are composed to form larger structures. These patterns deal with object composition and typically simplify the design by identifying simple ways to realize relationships between entities. They help ensure that classes and objects can work together smoothly and efficiently.

Some common examples of structural patterns include:

- **Adapter Pattern**: Allows incompatible interfaces to work together by providing a wrapper that translates one interface into another.
- **Decorator Pattern**: Adds functionality to an object dynamically without altering its structure.
- **Facade Pattern**: Provides a simplified interface to a complex system, hiding its complexity from the user.
- **Composite Pattern**: Composes objects into tree-like structures to represent part-whole hierarchies.
- **Proxy Pattern**: Provides a surrogate or placeholder for another object to control access to it.

## Behavioral Patterns

Behavioral patterns deal with object interaction and responsibility. These patterns focus on communication between objects, what happens when they interact, and how responsibilities are assigned. They define how objects collaborate and fulfill the requirements of the system.

Some common examples of behavioral patterns include:

- **Observer Pattern**: Defines a one-to-many dependency relationship between objects, so that when one object changes state, all its dependents are notified and updated automatically.
- **Strategy Pattern**: Defines a family of algorithms, encapsulates each one, and makes them interchangeable. It allows the algorithm to be selected at runtime.
- **Command Pattern**: Encapsulates a request as an object, allowing users to parameterize clients with queues, requests, and operations.
- **State Pattern**: Allows an object to change its behavior when its internal state changes, making it appear as though the object has changed its class.
- **Iterator Pattern**: Provides a way to access elements of an aggregate object sequentially without exposing its underlying representation.
- **Template Method Pattern**: Defines the skeleton of an algorithm in a method, allowing subclasses to implement specific steps of the algorithm without changing its structure.
- **Memento Pattern**: Allows capturing and externalizing an object's state without violating encapsulation, so the object can be restored to that state later.

Each of these categories of design patterns addresses different aspects of software design, and their application depends on the specific requirements and challenges faced during development.

---

# Creational Design Patterns

Here’s how we can format and explain the Singleton Pattern in a way that a child can understand, along with the flow chart illustrating how to use it.

## 1. What is it?
Imagine you have a toy box, but you only need **one** box to store all your toys. You don’t need more than **one** box, because **one** is enough for everything. The `Singleton Pattern` works the same way. It’s a way to make sure that there is only **one** object of a class in your program. Once you create the object, no matter how many times you try to create it again, it always gives you the same object, like a `single toy box`.

## 2. Why to use?
The Singleton Pattern is useful when you want to **ensure that only one object** is managing a certain resource. For example, you don’t want multiple score objects in a game because it can create confusion, and you only need **one** score that everyone uses.
1. Thread Safety
2. Solve name collisions
3. eager or lazy to initilization
4. Reduce Memory FootPrint

**Benefits:**
- **No duplication**: Ensures you don't create many unnecessary objects.
- **Easy control**: The object is controlled globally, so everyone in the program can access the same object.

## 3. When to use?
Use the Singleton Pattern when:
- You need **one** single instance of a class that is shared across the program.
You want to **control** the access to a shared resource (like a log file, game score, or database connection).
For example, if you're creating a **database connection manager**, you would want only one connection instance used throughout your application. You wouldn’t want multiple connections to the same database running at the same time.
1. Device Managers
2. Configuration Managment
3. Logging Service
4. Thread Pool

## 4. How to use?
To use the Singleton Pattern, follow these steps:
1. **Create a class with a private constructor** to prevent outside objects from creating multiple instances.
2. **Create a static method** (e.g., `getInstance()`) that provides a global point of access to the object.
3. **Use the static method** to get the instance instead of directly creating a new object.

**Flowchart: How to Use Singleton Pattern**
```
+--------------------------------------+
|           Start Program              |
+--------------------------------------+
                |
                v
+--------------------------------------+
| Is there already an instance?       | <-- No --> Create the object
+--------------------------------------+
                |
                v
+--------------------------------------+
| Return the existing instance        |
+--------------------------------------+
                |
                v
+--------------------------------------+
| Use the Singleton instance          |
+--------------------------------------+
```

# Structural Design Patterns
## Proxy Pattern

The **Proxy Pattern** is a structural design pattern that allows you to provide a placeholder or surrogate for another object. This means instead of accessing the real object directly, you access a proxy (a substitute) that controls access to the real object. The proxy can manage things like adding extra logic, controlling access, or performing actions before passing control to the real object.

Let's explain it in simple terms, especially for a 10-year-old:

---

### 1. **What is it?**
Think of a **Proxy** as a **security guard** or **assistant** that controls access to something important. Imagine you want to see a rare and valuable **toy**, but instead of going directly to the toy, you first go through a **security guard** who checks if you are allowed to see it or if you have the right permission. The security guard is like the **proxy**. You don’t directly interact with the toy, but you interact with the proxy first.

### 2. **Why to use?**

The Proxy Pattern is used for a few reasons:

- **Control Access**: A proxy allows you to control access to the real object. For example, you might want to check if someone has permission before allowing them to use a resource.
- **Lazy Initialization**: You might not want to create the real object unless it's absolutely necessary. The proxy can delay the creation of the real object until it’s needed.
- **Security and Logging**: A proxy can also add security checks or logging before allowing access to the real object, like tracking who accesses what and when.

---

### 3. **When to use?**

Use the Proxy Pattern when:

- You want to **control access** to an object (e.g., checking permission before allowing an action).
- You need **lazy initialization**, meaning the real object should only be created when absolutely needed.
- You need **extra functionality**, like logging, monitoring, or authentication, around a real object.
- The real object might be **expensive** to create, so you want to delay its creation until absolutely necessary (for example, a large image or a complex game that takes time to load).

---

### 4. **How to use?**

To implement the Proxy Pattern, you follow these steps:

1. **Create a real object** (the object you want to access indirectly).
2. **Create a proxy class** that acts as a placeholder for the real object.
3. **Add logic in the proxy** to control access to the real object. This can include permission checks, logging, or any other necessary functionality.
4. **Access the real object through the proxy** instead of accessing it directly.

```
+------------------------------------+
|         Start Program              |
+------------------------------------+
                |
                v
+------------------------------------+
| Does user have access?            | <-- No --> Deny access
+------------------------------------+
                |
                v
+------------------------------------+
| Create the Real Object (if needed) |
+------------------------------------+
                |
                v
+------------------------------------+
| Call the Real Object's Method     | <-- Call through Proxy
+------------------------------------+
                |
                v
+------------------------------------+
| End Program                        |
+------------------------------------+
```


# **Behavioral Design Patterns**

## [Observer Pattern](#observer-pattern)

---

### 1. **What is it?**  

The **Observer Pattern** is like a teacher and a group of students. Imagine that the teacher is the "subject" (the object being watched), and the students are the "observers" (the objects interested in the subject's state). 

When the teacher (subject) changes something, like assigning homework, all the students (observers) are immediately notified about the change. Each student can then act on this new information in their own way, for example, by starting their homework.

### Example for a 10-year-old:
- **Teacher**: "I have a new homework assignment for the class."
- **Students**: The students immediately hear the teacher and can start working on their homework.

In programming terms, the subject notifies all registered observers whenever something changes, and each observer can respond accordingly.

---

### 2. **Why to use?**

The **Observer Pattern** is used for a few important reasons:

- **Loose Coupling**: The Observer pattern allows objects to communicate without knowing much about each other. The subject (teacher) doesn't need to know who all the students (observers) are. It just knows to notify them when something happens.
- **Dynamic Communication**: Observers can be added or removed at any time. This allows flexible and dynamic behavior when the system evolves.
- **Efficiency**: Instead of having to ask if something has changed constantly, the observer is automatically notified when a change occurs, making the system more efficient.

---

### 3. **When to use?**

Use the **Observer Pattern** when:
- You want to **notify multiple objects** when something changes in a central object (the subject).
- The subject and observers have a **one-to-many relationship** (one subject with many observers).
- You need to **maintain flexibility** by decoupling objects from each other but still allow communication when needed.
- You have an event-driven system where various components need to be notified when certain events occur.

---

### 4. **How to use?**

To implement the **Observer Pattern**, follow these steps:

1. **Create a Subject**: This is the object being observed (like a teacher).
   - It keeps track of the observers (students).
   - It notifies observers when a change occurs.
   
2. **Create Observers**: These are the objects that want to be notified of changes.
   - They subscribe to the subject to receive updates.
   
3. **Implement Update Mechanism**: When the subject changes (for example, the teacher assigns homework), all observers are notified automatically, and each can act accordingly.

4. **Example Code Implementation:**

```cpp
// Subject (Teacher)
class Subject {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }
    
    void notifyObservers() {
        for (auto observer : observers) {
            observer->update();
        }
    }
};

// Observer (Student)
class Observer {
public:
    virtual void update() = 0;
};

class Student : public Observer {
public:
    void update() override {
        std::cout << "New homework assigned!" << std::endl;
    }
};

// Usage
int main() {
    Subject teacher;
    Student student1, student2;

    teacher.addObserver(&student1);
    teacher.addObserver(&student2);

    teacher.notifyObservers();  // Both students will be notified
}
```