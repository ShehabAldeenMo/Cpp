#include <iostream>

class RealGPIO
{
public:
    void togglePin(int pinNumber)
    {
        std::cout << "Toggling GPIO pin " << pinNumber << "\n";
        // Code to access and toggle GPIO on the embedded system
    }
};

class GPIOProxy
{
private:
    RealGPIO realGPIO;
    bool isAuthorized;

public:
    GPIOProxy(bool authorized) : isAuthorized(authorized) {}

    void togglePin(int pinNumber)
    {
        if (isAuthorized)
        {
            realGPIO.togglePin(pinNumber);
        }
        else
        {
            std::cout << "Unauthorized access to GPIO pin " << pinNumber << "\n";
        }
    }
};

int main()
{

    GPIOProxy proxy(true); // Change this to 'false' to test unauthorized access
    proxy.togglePin(17);   // Example GPIO pin
    return 0;
}