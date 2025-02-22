#include <iostream>
#include <memory>
#include <string>

class Smart_Pointer_b
{
private:
public:
    Smart_Pointer_b();
    ~Smart_Pointer_b();
    void print() {}
};

Smart_Pointer_b::Smart_Pointer_b()
{
    std::cout << "Smart_Pointer_b Created" << std::endl;
}

Smart_Pointer_b::~Smart_Pointer_b()
{
    std::cout << "Smart_Pointer_b Destroyed" << std::endl;
}

int main()
{

    {
        Smart_Pointer_b *x = new Smart_Pointer_b();
        x->print();
    }

    {
        std::unique_ptr<Smart_Pointer_b> b = std::make_unique<Smart_Pointer_b>();
        b->print();
    }
}
