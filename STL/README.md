# Standard Template Library (STL) Documentation

## Table of Contents

1. [Introduction to STL](#introduction-to-stl)
   - What is STL?
   - Types of STL Components
     - Containers
     - Iterators
     - Algorithms
     - Functors

2. [STL vs. Standard Library](#stl-vs-standard-library)
   - Key Differences
   - Advantages of STL

3. [Sequence Containers](#sequence-containers)
   - `std::vector`
   - `std::deque`
   - `std::list`
   - `std::forward_list`

4. [Utility Components](#utility-components)
   - Pairs
   - Tuples

5. [Associative Containers](#associative-containers)
   - Associative Set
     - `std::set`
     - `std::multiset`
   - Associative Map
     - `std::map`
     - `std::multimap`
   - Unordered Associative Containers
     - `std::unordered_set`
     - `std::unordered_map`
     - `std::unordered_multiset`
     - `std::unordered_multimap`

6. [STL Algorithms](#stl-algorithms)
   - Non-Modifying Algorithms
   - Modifying Algorithms
   - Sorting and Searching
   - Numeric Algorithms

7. [Functors and Lambda Expressions](#functors-and-lambda-expressions)
   - Function Objects in STL
   - Custom Functors
   - Lambda Expressions

8. [Specialized Containers](#specialized-containers)
   - `std::stack`
   - `std::queue`
   - `std::priority_queue`
---

# Introduction to STL

## What is STL?

The **Standard Template Library (STL)** is a powerful library in C++ that provides a collection of generic classes and functions. It allows developers to work with data structures, algorithms, and iterators efficiently. STL is a fundamental part of C++ and is designed to provide a seamless way to handle collections of data and perform operations like searching, sorting, and manipulation.

### Key Features of STL:
- **Generic**: Works with any data type using templates.
- **Reusable**: Reduces code duplication.
- **Efficient**: Implements optimized algorithms and data structures.
- **Standardized**: Ensures consistency across platforms.

---

## Types of STL Components

STL is broadly categorized into four main components:

### 1. Containers
Containers are data structures that store collections of elements. They can be broadly classified into three types:
- **Simple Containers**
    - `pair`
    - `tuple`
- **Sequence Containers**: Maintain the order of elements.
  - `std::vector`
  - `std::deque`
  - `std::list`
  - `std::forward_list`
- **Associative Containers**: Automatically sort elements and provide fast search.
  - `std::set`
  - `std::map`
  - `std::multiset`
  - `std::multimap`
- **Unordered Associative Containers**: Provide average constant-time complexity for search and insert operations.
  - `std::unordered_set`
  - `std::unordered_map`
  - `std::unordered_multiset`
  - `std::unordered_multimap`
- **Container Adapters**: Simplify specific use cases.
  - `std::stack`
  - `std::queue`
  - `std::priority_queue`

### 2. Iterators
Iterators are used to traverse elements in containers. They act as a bridge between algorithms and containers.

Types of Iterators:
- **Input Iterator**: Read-only access to a sequence of elements.
- **Output Iterator**: Write access to a sequence of elements.
- **Forward Iterator**: Read/write access; can traverse forward.
- **Bidirectional Iterator**: Can traverse forward and backward.
- **Random Access Iterator**: Provides access to any element in constant time.

Iterator Adapters:
- `std::reverse_iterator`
- `std::back_insert_iterator`, `std::front_insert_iterator`

### 3. Algorithms
STL provides a rich set of algorithms to perform operations on containers. These algorithms are implemented as template functions.

Categories of Algorithms:
- **Non-Modifying Algorithms**: Work on elements without changing them.
  - Examples: `std::for_each`, `std::count`, `std::find`
- **Modifying Algorithms**: Modify the elements.
  - Examples: `std::copy`, `std::replace`, `std::fill`
- **Sorting and Searching Algorithms**: Efficiently sort and search data.
  - Examples: `std::sort`, `std::binary_search`
- **Numeric Algorithms**: Perform numeric computations.
  - Examples: `std::accumulate`, `std::inner_product`

### 4. Functors
Functors, or function objects, are objects that can be called as functions. They are often used with algorithms to customize behavior.

- **Built-in Functors**:
  - `std::plus`, `std::minus`, `std::multiplies`, `std::divides`
  - `std::greater`, `std::less`
- **Custom Functors**:
  - User-defined functors for specific tasks.
  
Functors provide a way to encapsulate functions and state within objects, making them versatile for use with STL algorithms.

---

# STL vs. Standard Library

## Key Differences

While the **Standard Library** in C++ includes a broad range of functionalities such as I/O streams, file handling, and string manipulation, the **Standard Template Library (STL)** focuses specifically on providing generic and efficient solutions for data structures and algorithms.

| **Aspect**            | **Standard Library**                                        | **STL**                                               |
|-----------------------|-------------------------------------------------------------|-------------------------------------------------------|
| **Focus**             | General utilities like I/O, strings, math, and time         | Data structures, algorithms, and iterators            |
| **Components**        | Streams (`cin`, `cout`), `std::string`, `cmath`, etc.       | Containers, Iterators, Algorithms, Functors           |
| **Generic Programming** | Limited use of templates                                   | Heavy use of templates                                |
| **Efficiency**        | Not always optimized for performance                        | Provides optimized algorithms and data structures     |
| **Usage**             | Ideal for system-level and utility operations               | Ideal for data handling and algorithm-based problems  |

---

## Advantages of STL

The **Standard Template Library** offers several advantages that make it an essential tool for C++ developers:

### 1. **Generic Programming**
   - STL leverages templates, allowing developers to write code independent of data types. This reduces redundancy and increases code reusability.

### 2. **Rich Collection of Data Structures**
   - Provides a variety of containers (like `vector`, `set`, `map`) to handle different types of data efficiently.

### 3. **Built-in Algorithms**
   - Offers pre-defined algorithms for common operations such as sorting, searching, and transformations, reducing the need for custom implementation.

### 4. **Performance**
   - The algorithms and containers in STL are highly optimized for performance, ensuring faster execution times for standard operations.

### 5. **Consistency and Interoperability**
   - STL provides a uniform interface for its components, ensuring compatibility and ease of use between containers, iterators, and algorithms.

### 6. **Cross-Platform Compatibility**
   - Since STL is part of the C++ standard, it ensures consistent behavior across different platforms and compilers.

### 7. **Reduced Development Time**
   - With STL, developers can quickly implement solutions using robust and tested components, minimizing the time spent on debugging and optimizing custom implementations.

---

# Sequence Containers
- `list`, `forward_list` and `deque` will be discussed soon.
## `std::vector`

### 1. Vector Definition & Initialization

`std::vector` is a dynamic array provided by the C++ Standard Template Library (STL). Unlike traditional arrays, `std::vector` can dynamically resize itself, making it a powerful tool for managing collections of elements.

**Key Characteristics of `std::vector`:**
- Dynamic resizing: Grows automatically when new elements are added beyond its capacity.
- Continuous memory allocation: Guarantees that elements are stored in contiguous memory locations, enabling efficient random access.
- Flexibility: Allows inserting, deleting, and accessing elements through its member functions.

**Syntax for Declaration:**
```cpp
std::vector<T> vec;
```
Here, `T` is the type of elements stored in the vector.

**Examples of Initialization:**
- Default Initialization:
```Cpp
std::vector<int> vec1;
```

- Initialization with Size and Default Value:
```Cpp
std::vector<int> vec2(5);       // Creates a vector of size 5 with default value 0 for integers
std::vector<int> vec3(5, 10);   // Creates a vector of size 5 with all elements initialized to 10
```

-Initialization from an Array:
```Cpp
int arr[] = {1, 2, 3, 4, 5};
std::vector<int> vec4(arr, arr + 5);
```

- Using `std::initializer_list` :
```Cpp
std::vector<int> vec5 = {1, 2, 3, 4, 5};
```

- using copy constructor:
```Cpp
std::vector<int> vec6(vec5);
```

### 2. Functions of std::vector
`std::vector` provides a wide range of member functions for managing and accessing elements. Below are the most commonly used ones:

**Capacity Functions:**
- `size()`: Returns the number of elements in the vector.
```Cpp
std::cout << vec.size();
```

- `capacity()`: Returns the size of the allocated storage, which is always greater than or equal to the vector size.
```Cpp
std::cout << vec.capacity();
```

- Difference Between `size()` and `capacity()` in `std::vector` example.
**Example Code:**

```cpp
std::vector<std::string> vec;

// Initial State
std::cout << "Initial size: " << vec.size() << "\n";
std::cout << "Initial capacity: " << vec.capacity() << "\n\n";

// Adding elements
vec.push_back("Shehab");
vec.push_back("Aldeen");
vec.push_back("Mohammed");

std::cout << "After adding 3 elements:\n";
std::cout << "Size: " << vec.size() << "\n";
std::cout << "Capacity: " << vec.capacity() << "\n\n";

// Adding more elements to exceed current capacity
vec.push_back("Abdallah");
vec.push_back("Taha");

std::cout << "After adding 2 more elements:\n";
std::cout << "Size: " << vec.size() << "\n";
std::cout << "Capacity: " << vec.capacity() << "\n\n";
```

```Output will be 
Initial size: 0
Initial capacity: 0

After adding 3 elements:
Size: 3
Capacity: 4

After adding 2 more elements:
Size: 5
Capacity: 8
```

- `max_size()` function in `std::vector` returns the maximum number of elements that the vector can theoretically hold, depending on the system's memory limitations and the element type.
```cpp
std::cout << "Max size of this vector: " << vec.max_size() << std::endl;
```

- `empty()`: Checks whether the vector is empty.
```Cpp
if (vec.empty()) { std::cout << "Vector is empty"; }
```

- `resize(n)`: Resizes the vector to contain `n` elements. If `n` is smaller, the vector is truncated; if larger, the new elements are default-initialized.
```Cpp
vec.resize(10);
```

- `reserve(n)`: The `reserve()` function in `std::vector` is used to pre-allocate memory for at least a specified number of elements. It ensures that the vector doesn't reallocate memory when the number of elements increases, up to the reserved capacity.

```Cpp
std::vector<std::string> vec;

std::cout << "Initial size: " << vec.size() << "\n";
std::cout << "Initial capacity: " << vec.capacity() << "\n\n";

// Reserve space for 5 elements
vec.reserve(5);

std::cout << "After reserving space for 5 elements:\n";
std::cout << "Size: " << vec.size() << "\n";
std::cout << "Capacity: " << vec.capacity() << "\n\n";

// Add elements to the vector
vec.push_back("Element 1");
vec.push_back("Element 2");
vec.push_back("Element 3");

std::cout << "After adding 3 elements:\n";
std::cout << "Size: " << vec.size() << "\n";
std::cout << "Capacity: " << vec.capacity() << "\n\n";
```

```Output
Initial size: 0
Initial capacity: 0

After reserving space for 5 elements:
Size: 0
Capacity: 5

After adding 3 elements:
Size: 3
Capacity: 5
```

**Modifiers:**
- `push_back(val)`: Adds an element `val` to the end of the vector.
```Cpp
vec.push_back(10);
```

- `pop_back()`: Removes the last element of the vector.
```Cpp
vec.pop_back();
```

- `insert(pos, val)`: Inserts val at position pos. pos is an `iterator`
```Cpp
vec.insert(vec.begin() + 1, 20);
```

- `erase(pos)`: Removes the element at the specified `iterator` position.
```Cpp
vec.erase(vec.begin() + 2);
vec.erase(vec.begin() + 2, vec.begin() + 5); // erase from 2 to 5
```

- `clear()`: Removes all elements, reducing the size of the vector to 0.
```Cpp
vec.clear();
```

- `emplace(pos, val)`: Constructs an element in place at position pos.
```Cpp
vec.emplace(vec.begin(), 30);
```

- `swap(other_vector)`: Exchanges the contents of two vectors.
```Cpp
std::vector<int> vec2 = {10, 20};
vec.swap(vec2);
```

**Element Access:**
- `at(pos)`: Returns a reference to the element at position `pos` with bounds checking.

```cpp
std::cout << vec.at(2);
```

- `operator[]`: Returns a reference to the element at position `pos` *without* bounds checking.

```cpp
std::cout << vec[2];
```
- `front()`: Returns a reference to the first element.
```cpp
std::cout << vec.front();
```

- `back()`: Returns a reference to the last element.

```cpp
std::cout << vec.back();
```

- `data()`: Returns a pointer to the underlying array serving as element storage.

```cpp
int* ptr = vec.data();
```

**Iterators:**
- `begin()`, `end()`: Returns iterators to the beginning and the end of the vector.

```cpp
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " "; // will print values in our vector from begging to end
}
```

- `rbegin()`, `rend()`: Returns reverse iterators.

```cpp
for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    std::cout << *it << " "; // will print values in our vector from end to begging
}
```

- `cbegin()` function returns a constant iterator to the beginning of the container. This iterator allows you to read the elements of the container but prevents modifying them. 

- `cend()`: Returns a constant iterator that points just past the last element of the container, used to mark the end of the range for iteration. 

- You can only access the elements for reading, not modification, through the iterator returned.
```Cpp
std::vector<std::string> vec = {"apple", "banana", "cherry"};

// Using cbegin() to get a constant iterator
std::vector<std::string>::const_iterator it = vec.cbegin();
```

- The range-based `for` loop in C++ simplifies iterating over containers, such as `std::vector`, and allows you to access each element directly without using explicit iterators.

```Cpp
std::vector<std::string> vec = {"apple", "banana", "cherry"};

// Using range-based for loop to access elements of the vector
std::cout << "Elements in the vector (using range-based for loop):\n";
for (const auto& element : vec) {
    std::cout << element << std::endl;
}
```

# Utility Components

The Standard Template Library (STL) provides several utility components that can be used to work with pairs and tuples. These utility components are especially useful when dealing with data structures like maps and sets, where key-value pairs are common. In this section, we will discuss pairs and provide examples for their usage. A future update will address tuples.

## Pairs

A pair is a simple container that holds two values. The values can be of any type, and they are stored together in the pair. Pairs are often used in associative containers like `std::map` and `std::unordered_map`, where each element is a key-value pair.

**Declaration**
To declare a pair, you can use the `std::pair` template. You specify the types of the two elements it will store.

**Example:**

```cpp
#include <iostream>
#include <utility>

int main() {
    // Declare a pair of int and string
    std::pair<int, std::string> myPair(1, "Apple");

    std::cout << "First: " << myPair.first << ", Second: " << myPair.second << std::endl;
    return 0;
}
```

**Initialization**
A `pair` can be initialized in several ways. The most common method is using the `constructor` that takes two values and could use `std::make_pair`

```Cpp
std::pair<int, std::string> myPair = std::make_pair(1, "Apple");

auto anotherpair =  = std::make_pair(1, "Apple");

std::pair<int, std::string> myPair(10, "Banana");
```

**Member Access**
- You can access the two elements of a pair using the `first` and `second` members.
```Cpp
std::cout << "First: " << myPair.first << ", Second: " << myPair.second << std::endl;
```

**Swap**
- The `swap()` function swaps the values of two pairs. This is a useful feature when you need to exchange the values of two pairs.
```Cpp
std::pair<int, std::string> pair1(10, "Apple");
std::pair<int, std::string> pair2(20, "Banana");

// Swapping the pairs
pair1.swap(pair2);
```

**Nested Pair**
You can also create nested pairs, where one or both elements of a pair are themselves pairs. This is useful when you need to represent more complex relationships between data.
```Cpp
// Creating a pair of pairs
std::pair<std::pair<int, int>, std::string> nestedPair(std::make_pair(1, 2), "Coordinates");

std::cout << "First: (" << nestedPair.first.first << ", " << nestedPair.first.second << "), Second: "<< nestedPair.second << std::endl;
```

## Tuples (Will be Updated Soon)

# Associative Containers

## `std::set`

### Definition:
`std::set` is an ordered associative container that stores unique elements. The elements are stored in sorted order, and duplicates are not allowed. couldn't be in direct access.

### Properties:
- **Unique Elements**: Stores only unique elements (duplicates are not allowed).
- **Ordered**: Elements are automatically sorted by the key.
- **Direct Access**: couldn't be in direct access.
- **Logarithmic Time Complexity**: Insertions, deletions, and lookups all have logarithmic time complexity (O(log n)).

### Declaration & Initialization:
You can declare and initialize a `std::set` like this:

```cpp
#include <set>

// Declare an empty set of integers
std::set<int> mySet;

// Declare and initialize a set with values
std::set<int> mySet = {10, 20, 30, 10}; // Duplicate '10' will be ignored
```

## Why indexing is prohibited?
Indexing is prohibited in `std::set` because it is implemented as a balanced binary tree (typically a Red-Black tree), where elements are ordered but not necessarily stored contiguously in memory. Therefore, elements cannot be accessed directly using an index like in arrays or vectors. Instead, iterators are used to traverse through the elements.

## Operations:

- **Insert**: Adds an element to the set. Duplicate elements are ignored since sets do not allow duplicates.
```cpp
std::set<int> mySet;
mySet.insert(10);  // Inserts 10
mySet.insert(10);  // Will not insert as 10 already exists
```

- **Insert with two arguments**: You can insert an element with a hint (iterator) to optimize the insertion position.

```cpp
std::set<int> mySet;
auto it = mySet.insert(mySet.begin(), 20); // Insert 20 at the beginning
```

- **Find**: Searches for an element in the set. Returns an iterator to the element if found, or an iterator to end() if not found.

```cpp
auto it = mySet.find(20);
if (it != mySet.end()) {
    std::cout << "Found: " << *it << std::endl;
}
```

- **Erase**: Removes an element from the set.
```cpp
mySet.erase(10);  // Removes the element 10
```

- **Size**: Returns the number of elements in the set.
```cpp
std::cout << "Size: " << mySet.size() << std::endl;
```

- **Empty**: Checks if the set is empty.
```cpp
if (mySet.empty()) {
    std::cout << "Set is empty!" << std::endl;
}
```

- **Capacity**: A std::set does not provide direct access to the capacity (like in vectors), but it does have a method to find the maximum possible number of elements.

- **Max_size**: Returns the maximum number of elements the set can hold.

```cpp
std::cout << "Max size: " << mySet.max_size() << std::endl;
```

- **Emplace**: Inserts a new element into the set in-place, avoiding a copy or move of the element.
```cpp
mySet.emplace(30);  // Inserts 30 without copying
```

- **Emplace_hint**: Inserts an element with a hint to the location to optimize performance. complexity may equals O(1).
```cpp
mySet.emplace_hint(mySet.begin(), 40);
```

- **Swap**: Swaps the contents of two sets.
```cpp
std::set<int> anotherSet;
mySet.swap(anotherSet);
```

- **Clear**: Removes all elements from the set.
```cpp
mySet.clear();  // Removes all elements
```

- **key_comp**: Returns a comparison function used for ordering the keys. The function is typically used to compare two elements of the set.

```cpp
auto comp = mySet.key_comp();
std::cout << "Comparing 10 and 20: " << comp(10, 20) << std::endl;
```

- `key_comp` returns a function object that implements a comparison operator (operator()). For example, if you want to check if 10 is less than 20, the comparison function will return true.

- **Count**: Returns the number of occurrences of a specific element. Since std::set contains unique elements, this will always return either 0 or 1.
```cpp
int count = mySet.count(10);  // Returns 1 if 10 exists, 0 otherwise
```

- **Equal_range**: Returns a pair of iterators that represent the range of elements equal to the specified value. For `std::set`, the range will contain at most one element, as duplicates are not allowed.
```cpp
auto range = mySet.equal_range(20);
std::cout << "Lower bound: " << *range.first << ", Upper bound: " << *range.second << std::endl;
```

- **Iterators**: Iterators are used to traverse through the set. A set supports bidirectional iteration, which means you can move both forward and backward through the set.

```cpp
for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    std::cout << *it << std::endl;
}
```

- You can also use a reverse iterator for traversing the set in reverse order:
```cpp
for (auto rit = mySet.rbegin(); rit != mySet.rend(); ++rit) {
    std::cout << *rit << std::endl;
}
```

## `std::map`

### Definition:
`std::map` is an ordered associative container that stores unique key-value pairs. The keys are stored in sorted order, and each key is associated with a value. Duplicates are not allowed for keys, but different keys can have the same values. Direct access by key is not allowed; instead, you use iterators to access elements.

### Properties:
- **Unique Keys**: Stores only unique keys (duplicates are not allowed for keys).
- **Ordered**: The keys are automatically sorted based on a comparison function (default is `operator<`).
- **Key-Value Pair**: Each element is a key-value pair, where the key is unique and is associated with a value.
- **Logarithmic Time Complexity**: Insertions, deletions, and lookups all have logarithmic time complexity (O(log n)).
- **Bidirectional Iterators**: You can iterate through the `std::map` from both directions using bidirectional iterators.

### Declaration & Initialization:
You can declare and initialize a `std::map` like this:

```cpp
#include <map>

// Declare an empty map with integer keys and string values
std::map<int, std::string> myMap;

// Declare and initialize a map with values
std::map<int, std::string> myMap = {{1, "One"}, {2, "Two"}, {3, "Three"}};

// Or use the insert method for initialization
std::map<int, std::string> myMap;
myMap.insert({4, "Four"});
myMap.insert({5, "Five"});
```

### Why indexing is prohibited?
Indexing is prohibited in `std::map` because it is implemented as a balanced binary tree (typically a Red-Black tree), and the elements are stored as key-value pairs where the key is used to maintain the order of the map. The keys are unique, and the elements are not stored contiguously in memory, making direct indexing inefficient. Instead, iterators or the `find` method are used to access the elements.

### Operations:

- **Insert**: Adds a key-value pair to the map. If the key already exists, the insert operation does nothing.

```cpp
std::map<int, std::string> myMap;
myMap.insert({10, "Ten"});  // Inserts the pair (10, "Ten")
myMap.insert({10, "Ten"});  // Will not insert as 10 already exists
```

- **Insert with two arguments**: You can insert a key-value pair with a hint (iterator) to optimize the insertion position.

```cpp
std::map<int, std::string> myMap;
auto it = myMap.insert(myMap.begin(), {20, "Twenty"});
```

- **Find**: Searches for a key in the map. Returns an iterator to the key-value pair if found, or an iterator to end() if not found.

```cpp
auto it = myMap.find(20);
if (it != myMap.end()) {
    std::cout << "Found: " << it->first << " -> " << it->second << std::endl;
}
```

- **Erase**: Removes a key-value pair from the map by key.
```cpp
myMap.erase(10);  // Removes the pair with key 10
```

- **Size**: Returns the number of key-value pairs in the map.
```cpp
std::cout << "Size: " << myMap.size() << std::endl;
```

- **Empty**: Checks if the map is empty.
```cpp
if (myMap.empty()) {
    std::cout << "Map is empty!" << std::endl;
}
```

- **Capacity**: A **std::map** does not provide direct access to the capacity (like in vectors), but it does have a method to find the maximum possible number of elements.

- **Max_size**: Returns the maximum number of elements the map can hold.
```cpp
std::cout << "Max size: " << myMap.max_size() << std::endl;
```

- **Emplace**: Inserts a key-value pair into the map in-place, avoiding a copy or move of the elements.
```cpp
myMap.emplace(30, "Thirty");  // Inserts the pair (30, "Thirty") without copying
```

- **Emplace_hint**: Inserts a key-value pair with a hint to the location to optimize performance.
```cpp
myMap.emplace_hint(myMap.begin(), 40, "Forty");
```

- **Swap**: Swaps the contents of two maps.
```cpp
std::map<int, std::string> anotherMap;
myMap.swap(anotherMap);
```

- **Clear**: Removes all key-value pairs from the map.
```cpp
myMap.clear();  // Removes all key-value pairs
```

- **key_comp**: Returns a comparison function used for ordering the keys. The function is typically used to compare two keys of the map.
```cpp
auto comp = myMap.key_comp();
std::cout << "Comparing 10 and 20: " << comp(10, 20) << std::endl;
```

- **key_comp** returns a function object that implements a comparison operator (operator()). For example, if you want to check if 10 is less than 20, the comparison function will return true.

- **Count**: Returns the number of occurrences of a specific key. Since std::map contains unique keys, this will always return either 0 or 1.
```cpp
int count = myMap.count(10);  // Returns 1 if 10 exists, 0 otherwise
```

- **Equal_range**: Returns a pair of iterators that represent the range of elements with the specified key. For std::map, the range will contain at most one element, as keys are unique.
```cpp
auto range = myMap.equal_range(20);
std::cout << "Lower bound: " << range.first->first << ", Upper bound: " << range.second->first << std::endl;
```

- **Iterators**: Iterators are used to traverse through the map. A map supports bidirectional iteration, which means you can move both forward and backward through the map.
```cpp
for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout << it->first << " -> " << it->second << std::endl;
}

- You can also use a reverse iterator for traversing the map in reverse order:

```cpp
for (auto rit = myMap.rbegin(); rit != myMap.rend(); ++rit) {
    std::cout << rit->first << " -> " << rit->second << std::endl;
}
```

# STL Algorithms

## Non-Modifying Algorithms
Non-modifying algorithms perform operations on elements without modifying their contents. These algorithms are primarily used for testing, searching, or querying information from containers.

Some common non-modifying algorithms are:
- **`std::find`**: Finds the first occurrence of a value in a container.
- **`std::count`**: Counts the occurrences of a value in a container.
- **`std::search`**: Finds a sequence within another sequence.
- **`std::equal`**: Compares two ranges to check if they are equal.

### Example:
```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> myVec = {1, 2, 3, 4, 5};

auto it = std::find(myVec.begin(), myVec.end(), 3); // Finds 3
if (it != myVec.end()) {
    std::cout << "Element found: " << *it << std::endl;
} else {
    std::cout << "Element not found" << std::endl;
}
```

- **std::count:** Counts the occurrences of a value in a container.
```cpp
int main() {
    std::vector<int> myVec = {1, 2, 3, 4, 2, 2, 5};

    // Count how many times '2' appears in the vector
    int count = std::count(myVec.begin(), myVec.end(), 2);

    std::cout << "The value '2' appears " << count << " times." << std::endl; // Output: The value '2' appears 3 times.

    return 0;
}
```
- **std::search**: Finds a sequence within another sequence.

```cpp
int main() {
    std::vector<int> myVec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> subVec = {4, 5, 6};

    // Search for the subsequence (subVec) in myVec
    auto it = std::search(myVec.begin(), myVec.end(), subVec.begin(), subVec.end());

    if (it != myVec.end()) {
        std::cout << "Subsequence found starting at position: " << std::distance(myVec.begin(), it) << std::endl; // Output: Subsequence found starting at position: 3
    } else {
        std::cout << "Subsequence not found" << std::endl;
    }

    return 0;
}

- **std::equal**: Compares two ranges to check if they are equal.
```cpp
int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    // Compare the two vectors for equality
    if (std::equal(vec1.begin(), vec1.end(), vec2.begin())) {
        std::cout << "The two ranges are equal." << std::endl; // Output: The two ranges are equal.
    } else {
        std::cout << "The two ranges are not equal." << std::endl;
    }

    return 0;
}
```

## Modifying Algorithms
- Modifying algorithms change the elements of the container. They can alter the contents by adding, removing, or replacing elements.

Some common modifying algorithms are:
   - `std::fill`: Assigns a value to all elements in a range.
   - `std::replace`: Replaces all occurrences of a value with another.
   - `std::remove`: Removes all occurrences of a value from the container (does not resize the container).

- `std::fill`: Assigns a value to all elements in a range.
- Example:
```cpp
std::vector<int> myVec = {1, 2, 3, 4, 5};

std::fill(myVec.begin(), myVec.end(), 0); // Fills vector with zeros

for (int num : myVec) {
    std::cout << num << " "; // Output: 0 0 0 0 0
}
```
- `std::replace`: Replaces all occurrences of a value with another.
```Cpp
std::vector<int> myVec = {1, 2, 3, 4, 5};

// Replace all occurrences of '3' with '9'
std::replace(myVec.begin(), myVec.end(), 3, 9);

for (int num : myVec) {
    std::cout << num << " "; // Output: 1 2 9 4 5
}
```
- `std::remove`: Removes all occurrences of a value from the container (does not resize the container).

```Cpp
std::vector<int> myVec = {1, 2, 3, 4, 5, 3, 6};

// Remove all occurrences of '3'
auto newEnd = std::remove(myVec.begin(), myVec.end(), 3);

// Erase the "removed" elements from the container (resize it)
myVec.erase(newEnd, myVec.end());

for (int num : myVec) {
    std::cout << num << " "; // Output: 1 2 4 5 6
}
```

## Sorting and Searching
These algorithms are used to sort the elements in a container and search for specific values.

Sorting Algorithms:
   - `std::sort`: Sorts the elements in ascending order (default) or in descending order (with a custom comparator).
   - `std::partial_sort`: Sorts a part of the container.
Searching Algorithms:
   - `std::binary_search`: Checks if a value is present in a sorted container.
   - `std::lower_bound`: Finds the first position where a value could be inserted to maintain sorted order.
   - `std::upper_bound`: Finds the first position where a value is greater than a specified value.


Example:
```cpp
std::vector<int> myVec = {5, 3, 8, 1, 2};

std::sort(myVec.begin(), myVec.end()); // Sorts the vector in ascending order

for (int num : myVec) {
    std::cout << num << " "; // Output: 1 2 3 5 8
}
```
- `std::binary_search`: Checks if a value is present in a sorted container.
```cpp
std::vector<int> myVec = {1, 2, 3, 4, 5, 6, 7};

// Check if '4' is present in the sorted vector
bool found = std::binary_search(myVec.begin(), myVec.end(), 4);

if (found) {
    std::cout << "4 is present in the vector." << std::endl;
} else {
    std::cout << "4 is not present in the vector." << std::endl;
}
```

- `std::lower_bound`: Finds the first position where a value could be inserted to maintain sorted order.
```Cpp
std::vector<int> myVec = {1, 3, 5, 7, 9};

// Find the first position where '6' could be inserted
auto it = std::lower_bound(myVec.begin(), myVec.end(), 6);

std::cout << "The first position where '6' could be inserted: " << (it - myVec.begin()) << std::endl; // Output: 3 (position of 7)
```

- `std::upper_bound`: Finds the first position where a value is greater than a specified value.
```Cpp
std::vector<int> myVec = {1, 3, 5, 7, 9};

// Find the first position where a value greater than '6' could be inserted
auto it = std::upper_bound(myVec.begin(), myVec.end(), 6);

std::cout << "The first position where a value greater than '6' can be inserted: " << (it - myVec.begin()) << std::endl; // Output: 3 (position of 7)
```

## Numeric Algorithms
Numeric algorithms provide operations to perform numeric computations on ranges of elements.

Some common numeric algorithms are:
   - `std::accumulate`: Calculates the sum of all elements in a container.
   - `std::inner_product`: Computes the inner product of two ranges.
   - `std::iota`: Fills a range with sequentially increasing values.

- `std::accumulate`: Calculates the sum of all elements in a container.   
Example:
```cpp
#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>

std::vector<int> myVec = {1, 2, 3, 4, 5};

int sum = std::accumulate(myVec.begin(), myVec.end(), 0); // Sums the elements
std::cout << "Sum: " << sum << std::endl; // Output: Sum: 15
```
