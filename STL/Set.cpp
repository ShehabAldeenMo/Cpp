#include <iostream>
#include <set>

int main()
{
    // Definition and Initialization
    // An empty set of integers
    std::set<int> mySet;

    // Initialize with values (duplicates will be ignored)
    std::set<int> anotherSet{5, 2, 8, 2, 1};

    // Find an element (returns an iterator)
    std::set<int>::iterator it = anotherSet.find(8);
    if (it != anotherSet.end())
    {
        std::cout << "Found 8 in the set\n";
    }

    // Accessing elements (sets don't have direct indexing)
    // First element
    std::cout << "First element: " << *anotherSet.begin() << std::endl;

    // Last element
    std::cout << "Last element: " << *anotherSet.rbegin() << std::endl;

    // Set properties
    std::cout << "Size: " << anotherSet.size() << std::endl;         // Number of elements
    std::cout << "Max size: " << anotherSet.max_size() << std::endl; // Theoretical maximum
    std::cout << "Is empty? " << anotherSet.empty() << std::endl;

    // Iterators
    std::cout << "Elements in order: ";
    for (auto it = anotherSet.begin(); it != anotherSet.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements in reverse order: ";
    for (auto it = anotherSet.rbegin(); it != anotherSet.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Const iterators
    // cbegin(), cend(), crbegin(), crend() work similarly but provide const access

    // Inserting elements
    mySet.insert(3);
    mySet.insert(7);
    mySet.insert(3); // No effect, duplicates are ignored

    // emplace (more efficient for complex types)
    mySet.emplace(6); // Constructs the element in-place

    // emplace_hint (potentially faster if you have a good guess where to insert)
    auto hint = mySet.begin();
    mySet.emplace_hint(hint, 1); // Tries to insert at 'hint', may reposition if needed

    // Erasing elements
    mySet.erase(3); // Erases by value

    it = mySet.find(7);
    if (it != mySet.end())
    {
        mySet.erase(it); // Erases by iterator
    }

    // Other operations
    anotherSet.swap(mySet); // Swaps contents of two sets
    mySet.clear();          // Removes all elements

    // Set comparison (based on the underlying ordering)
    std::cout << "Key comparison function: "
              << anotherSet.key_comp()(2, 5) << std::endl; // 1 if 2 < 5, 0 otherwise

    // Counting elements
    std::cout << "Count of 5: " << anotherSet.count(5) << std::endl;

    // Finding a range of elements equal to a given value
    auto range = anotherSet.equal_range(5);
    std::cout << "Equal range for 5: ";
    for (auto it = range.first; it != range.second; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // How Sets Work
    // 1. Sorting: Elements are automatically sorted according to the provided comparison function
    //    (by default, std::less, which sorts in ascending order).
    // 2. Removing duplicates: Sets use their internal structure (typically a balanced binary search tree)
    //    to efficiently detect and discard duplicate elements during insertion.

    return 0;
}