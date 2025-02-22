#include <iostream>
#include <vector>
#include <algorithm>

// Observer Interface
class IObserver
{
public:
    virtual void update(bool pressed) = 0;
};

// Subject (Button)
class Button
{
    bool pressed;
    std::vector<IObserver *> observers;

public:
    void attach(IObserver *observer)
    {
        observers.push_back(observer);
    }

    void detach(IObserver *observer)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void pressButton()
    {
        pressed = true;
        notify();
    }

    void releaseButton()
    {
        pressed = false;
        notify();
    }

    void notify()
    {
        for (IObserver *observer : observers)
        {
            observer->update(pressed);
        }
    }
};

// Concrete Observer 1 (Light)
class Light : public IObserver
{
public:
    void update(bool pressed) override
    {
        if (pressed)
        {
            std::cout << "Light: Button pressed. Turning on the light.\n";
        }
        else
        {
            std::cout << "Light: Button released. Turning off the light.\n";
        }
    }
};

// Concrete Observer 2 (Motor)
class Motor : public IObserver
{
public:
    void update(bool pressed) override
    {
        if (pressed)
        {
            std::cout << "Motor: Button pressed. Starting the motor.\n";
        }
        else
        {
            std::cout << "Motor: Button released. Stopping the motor.\n";
        }
    }
};

// Concrete Observer 3 (Logger)
class Logger : public IObserver
{
public:
    void update(bool pressed) override
    {
        std::cout << "Logger: Button state changed. Pressed = " << pressed << "\n";
    }
};

// Main
int main()
{
    Button button;
    Light light;
    Motor motor;
    Logger logger;

    button.attach(&light);
    button.attach(&motor);
    button.attach(&logger);

    button.pressButton();
    button.releaseButton();

    return 0;
}