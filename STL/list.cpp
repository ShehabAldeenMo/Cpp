#include <list>
#include <iostream>

using namespace std;

int main()
{
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20); // lst: 10 20

    lst.push_front(10);
    lst.push_front(5); // lst: 5 10 10 20

    lst.clear();
    lst = {1, 2, 3};
    lst.pop_back(); // lst: 1 2

    lst.clear();
    lst = {1, 2, 3};
    lst.pop_front(); // lst: 2 3

    auto it = lst.begin();
    ++it;
    lst.insert(it, 2); // lst: 1 2 3

    lst.clear();
    lst = {1, 2, 3};
    it = lst.begin();
    ++it;
    lst.erase(it); // lst: 1 3

    lst.clear();
    lst = {10, 20, 30};
    std::cout << lst.size(); // Output: 3

    std::cout << std::boolalpha << lst.empty(); // Output: true

    lst.clear();
    lst = {100, 200, 300};
    std::cout << lst.front(); // Output: 100
    std::cout << lst.back();  // Output: 300

    lst.clear();
    lst = {3, 1, 2};
    lst.sort(); // lst: 1 2 3

    lst.clear();
    lst = {1, 2, 3};
    lst.reverse(); // lst: 3 2 1

    lst.clear();
    lst = {1, 1, 2, 2, 3, 3};
    lst.unique(); // lst: 1 2 3

    lst;
    lst.assign(3, 7); // lst: 7 7 7
}