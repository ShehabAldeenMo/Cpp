
#include <iostream>
#include <memory>

class Toy
{
public:
    Toy(const std::string &name) : name(name)
    {
        std::cout << name << " created.\n";
    }
    ~Toy()
    {
        std::cout << name << " destroyed.\n";
    }

private:
    std::string name;
};

int main()
{
    // Creating a shared pointer that owns a Toy
    std::shared_ptr<Toy> sharedToy = std::make_shared<Toy>("Action Figure");

    // Creating a weak pointer that observes the shared pointer
    std::weak_ptr<Toy> weakToy = sharedToy;

    // Checking the use count (how many shared pointers are pointing to the object)
    std::cout << "Use count of sharedToy: " << sharedToy.use_count() << "\n"; // Output: 1

    // Accessing the toy through the weak pointer (it needs to be converted to a shared pointer)
    if (std::shared_ptr<Toy> toyPtr = weakToy.lock())
    { // Try to create a shared pointer from the weak pointer
        std::cout << "Toy is still available!\n";
        std::cout << "Use count of sharedToy: " << sharedToy.use_count() << "\n"; // Output: 2
    }
    else
    {
        std::cout << "Toy has been destroyed!\n";
    }

    // Reset the shared pointer, which will destroy the Toy
    sharedToy.reset(); // The Action Figure is destroyed here

    // Checking again if the weak pointer can access the toy
    if (auto toyPtr = weakToy.lock())
    {
        std::cout << "Toy is still available!\n";
    }
    else
    {
        std::cout << "Toy has been destroyed!\n";
    }

    return 0;
}