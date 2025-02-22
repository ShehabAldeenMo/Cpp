#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element and std::min_element
#include <utility>   // for std::pair and std::make_pair
#include <array>     // for std::array

// Example: Returning multiple values from a function
template <typename T>
std::pair<T, T> calculateMinMax(const std::vector<T> &data)
{
    auto max = std::max_element(data.begin(), data.end());
    auto min = std::min_element(data.begin(), data.end());
    return std::make_pair(*min, *max); // Replace with actual calculations
}

int main()
{

    // Constructors
    std::pair<int, std::string> myPair(10, "apple"); // Initialization constructor
    std::pair<int, std::string> copiedPair(myPair);  // Copy constructor

    // make_pair()
    auto anotherPair = std::make_pair(3.14, 'c');

    // Member access
    std::cout << "myPair.first: " << myPair.first << std::endl;   // Output: 10
    std::cout << "myPair.second: " << myPair.second << std::endl; // Output: apple

    // swap()
    std::pair<int, std::string> pair1(1, "one");
    std::pair<int, std::string> pair2(2, "two");
    pair1.swap(pair2);

    // Relational operators
    std::pair<int, char> pair3(1, 'a');
    std::pair<int, char> pair4(1, 'b');
    std::pair<int, char> pair5(2, 'a');

    std::cout << (pair3 < pair4) << std::endl; // Output: 1 (true)
    std::cout << (pair3 < pair5) << std::endl; // Output: 1 (true)

    std::vector<double> myv({2, 5, 8, 9, 9, 10});
    std::pair<double, double> MyPair = calculateMinMax(myv);
    std::cout << "min. = " << MyPair.first << " max. = " << MyPair.second << "\n";
}
