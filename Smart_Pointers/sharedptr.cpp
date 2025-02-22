#include <iostream>
#include <memory>  // For std::shared_ptr

class Toy {
public:
    Toy(const std::string& name) : name(name) {
        std::cout << "Creating toy: " << name << std::endl;
    }
    ~Toy() {
        std::cout << "Destroying toy: " << name << std::endl;
    }
    void play() const {
        std::cout << "Playing with " << name << "!" << std::endl;
    }

private:
    std::string name;
};

int main() {
    // Create a shared pointer that owns a Toy object
    std::shared_ptr<Toy> toy1 = std::make_shared<Toy>("Mousel");
    toy1->play();

    {
        // Now toy1 shares ownership with toy2
        std::shared_ptr<Toy> toy2 = toy1;
        toy2->play();
        std::cout << "Number of owners inside the scope: " << toy1.use_count() << std::endl;
    }
    // Use the toy through both pointers
    toy1->play();
    
    // Display how many shared pointers own the object
    std::cout << "Number of owners: " << toy1.use_count() << std::endl;

    // When we go out of this scope, both toy1 and toy2 will be destroyed,
    // but the memory will only be freed when the last owner goes out of scope.

    return 0;
}