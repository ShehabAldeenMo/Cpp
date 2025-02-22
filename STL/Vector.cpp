#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element and std::min_element

int main()
{
    std::vector<int> myVector; // empty Vector

    // unpreferred at all.
    std::cout << "First element: " << myVector[0] << std::endl; // Access the first element
    myVector = {10, 20, 30, 40, 50};

    // unpreferred at all.
    std::vector<int> myv(myVector);
    std::vector<int> myv(5, 100);

    // Accessing elements
    std::cout << "Front element: " << myVector.front() << std::endl;    // Access the first element (10)
    std::cout << "Back element: " << myVector.back() << std::endl;      // Access the last element (50)
    std::cout << "Element at index 2: " << myVector.at(2) << std::endl; // Access element at index 2 (30), with bounds checking (throws exception if out of bounds)

    // begin() vs. front()
    // begin() returns an iterator pointing to the first element.
    // front() returns a reference to the first element.
    std::cout << "First element using reference: " << *myVector.begin() << std::endl;
    std::cout << "First const element using reference: " << *myVector.cbegin() << std::endl;

    // begin() vs. rbegin()
    // begin() returns an iterator pointing to the first element (forward iteration).
    // rbegin() returns a reverse iterator pointing to the last element (backward iteration).
    std::cout << "First reversed element using reference: " << *myVector.rbegin() << std::endl;
    std::cout << "First const reversed element using reference: " << *myVector.crbegin() << std::endl;

    // end() vs. back()
    // end() returns an iterator pointing to one past the last element (used for looping).
    // back() returns a reference to the last element.
    std::cout << "Last element using reference: " << *(myVector.end() - 1) << std::endl; // Need to subtract 1 to get the actual last element

    // Modifying the vector
    myVector.push_back(60); // Add an element at the end
    std::cout << "After push_back: ";
    for (int num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    myVector.pop_back(); // Remove the last element
    std::cout << "After pop_back: ";
    for (int num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // insert() vs. emplace()
    // insert() inserts a copy of an existing object or a newly constructed object into the vector.
    // emplace() constructs an object in-place at the specified position, potentially avoiding unnecessary copies.
    myVector.insert(myVector.begin() + 1, 12); // Insert 12 at index 1
    std::cout << "After insert: ";
    for (int num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    myVector.emplace(myVector.begin(), 8); // Construct an element in-place at the beginning
    std::cout << "After emplace: ";
    for (int num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    myVector.erase(myVector.begin() + 2); // Erase the element at index 2
    std::cout << "After erase: ";
    for (int num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> anotherVector = {5, 15, 25};
    myVector.swap(anotherVector); // Swap the contents of two vectors
    std::cout << "After swap, myVector: ";
    for (int num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Vector Size Operations
    // size() vs. capacity()
    // size() is the actual number of elements in the vector.
    // capacity() is the storage space currently allocated to the vector.
    std::cout << "Size: " << myVector.size() << std::endl;         // Number of elements currently in the vector (3)
    std::cout << "Capacity: " << myVector.capacity() << std::endl; // Total number of elements the vector can hold without reallocating memory (5)
    std::cout << "Max size: " << myVector.max_size() << std::endl; // Maximum number of elements the vector can possibly hold

    // Find max and min elements
    auto maxIterator = std::max_element(myVector.begin(), myVector.end());
    std::cout << "Max element: " << *maxIterator << std::endl;

    auto minIterator = std::min_element(myVector.begin(), myVector.end());
    std::cout << "Min element: " << *minIterator << std::endl;

    std::cout << "Is empty? " << myVector.empty() << std::endl; // Check if the vector is empty (0 for false, 1 for true)

    // Iterators
    std::cout << "Elements in reverse order using rbegin(): ";
    for (auto it = myVector.rbegin(); it != myVector.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // const iterators
    std::cout << "Elements using cbegin(): ";
    for (auto it = myVector.cbegin(); it != myVector.cend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements in reverse order using crbegin(): ";
    for (auto it = myVector.crbegin(); it != myVector.crend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Resizing
    myVector.resize(7); // Resize the vector to hold 7 elements (new elements are initialized to 0)
    std::cout << "After resize: ";
    for (int num : myVector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    myVector.shrink_to_fit(); // Reduce capacity to match the current size
    std::cout << "After shrink_to_fit, capacity: " << myVector.capacity() << std::endl;

    return 0;
}