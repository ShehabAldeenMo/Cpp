#include <iostream>
#include <map>
#include <algorithm> // for max/min_element

int main()
{
    // Definition and Initialization
    // - Empty map
    std::map<std::string, int> myMap;

    // - Initializer list
    std::map<int, char> gradeMap{{90, 'A'}, {80, 'B'}, {70, 'C'}};

    // Printing Element Value using Key
    std::cout << "Value for key 90: " << gradeMap[90] << std::endl; // Access using key

    // Printing Elements using for-each Loop
    std::cout << "Key-Value pairs:\n";
    for (const auto &pair : gradeMap)
    {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    // Iterators and Access
    // - begin(), end()
    std::cout << "Forward Iteration:\n";
    for (auto it = gradeMap.begin(); it != gradeMap.end(); ++it)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
    }

    // - rbegin(), rend()
    std::cout << "Reverse Iteration:\n";
    for (auto it = gradeMap.rbegin(); it != gradeMap.rend(); ++it)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
    }

    // - cbegin(), cend(), crbegin(), crend() (const iterators)
    std::cout << "Const Forward Iteration:\n";
    for (auto it = gradeMap.cbegin(); it != gradeMap.cend(); ++it)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
        // *it = {100, 'Z'}; // Error: Cannot modify through const_iterator
    }

    // Accessing key and value using iterator
    auto it = gradeMap.begin();
    std::cout << "First key: " << it->first << ", First value: " << it->second << std::endl;

    // Size, Capacity, Max_size
    std::cout << "Size of gradeMap: " << gradeMap.size() << std::endl;

    // Capacity is implementation-dependent, not typically used with map
    std::cout << "Max size gradeMap can theoretically reach: " << gradeMap.max_size() << std::endl;

    // Max and Min Element (using algorithm)
    auto maxIt = std::max_element(gradeMap.begin(), gradeMap.end());
    std::cout << "Max key: " << maxIt->first << std::endl;

    // empty() Check
    if (myMap.empty())
    {
        std::cout << "myMap is empty\n";
    }

    // Inserting Elements
    // - insert()
    myMap.insert(std::make_pair("AHmed", 5));
    myMap.insert({"Mousel", 6});
    myMap.insert(std::pair<std::string, int>("apple", 5));
    myMap.insert({"banana", 3}); // Alternative syntax

    // - emplace()
    //  * emplace constructs the element in-place, potentially more efficient than insert
    myMap.emplace("orange", 7);

    // - emplace_hint()
    //  * emplace_hint provides a hint for insertion position, may improve performance if hint is accurate
    auto hintIt = myMap.lower_bound("banana");
    myMap.emplace_hint(hintIt, "grapefruit", 2);

    // lower_bound and upper_bound
    auto lowerIt = myMap.lower_bound("banana");
    auto upperIt = myMap.upper_bound("banana");
    std::cout << "Lower bound for 'banana': " << lowerIt->first << std::endl;

    // upper_bound points to the element *after* the ones matching the key
    if (upperIt != myMap.end())
    {
        std::cout << "Upper bound for 'banana': " << upperIt->first << std::endl;
    }

    // Erasing Elements
    myMap.erase("apple"); // Erase by key
    myMap.erase(lowerIt); // Erase by iterator

    // swap and clear
    std::map<std::string, int> anotherMap{{"kiwi", 1}};
    myMap.swap(anotherMap); // Swap contents of two maps
    anotherMap.clear();     // Clear all elements

    // key_comp
    auto comp = myMap.key_comp();
    if (comp("apple", "banana"))
    {
        std::cout << "'apple' is less than 'banana'\n";
    }

    // count and equal_range
    std::cout << "Count of 'banana': " << myMap.count("banana") << std::endl;
    auto range = myMap.equal_range("banana");

    // equal_range returns a pair of iterators, [first, second)
    for (auto it = range.first; it != range.second; ++it)
    {
        std::cout << "Key in range: " << it->first << std::endl;
    }

    return 0;
}