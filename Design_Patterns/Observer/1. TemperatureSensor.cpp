#include <iostream>
#include <vector>
#include <algorithm>

// Observer Interface
class IObserver
{
public:
    virtual void update(float temperature) = 0;
};

// Subject (Temperature Sensor)
class TemperatureSensor
{
    float temperature;
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

    void setTemperature(float temp)
    {
        temperature = temp;
        notify();
    }

    void notify()
    {
        for (IObserver *observer : observers)
        {
            observer->update(temperature);
        }
    }
};

// Concrete Observer 1 (Fan)
class Fan : public IObserver
{
public:
    void update(float temperature)
    {
        if (temperature > 30.0f)
        {
            std::cout << "Fan: Temperature is high! Turning on the fan.\n";
        }
        else
        {
            std::cout << "Fan: Temperature is normal. Fan is off.\n";
        }
    }
};

// Concrete Observer 2 (Alarm)
class Alarm : public IObserver
{
public:
    void update(float temperature) override
    {
        if (temperature > 40.0f)
        {
            std::cout << "Alarm: Critical temperature! Triggering alarm!\n";
        }
        else
        {
            std::cout << "Alarm: Temperature is safe.\n";
        }
    }
};

// Concrete Observer 3 (Display)
class Display : public IObserver
{
public:
    void update(float temperature) override
    {
        std::cout << "Display: Current Temperature is " << temperature << " degrees.\n";
    }
};

// Main
int main()
{
    TemperatureSensor sensor;
    Fan fan;
    Alarm alarm;
    Display display;

    sensor.attach(&fan);
    sensor.attach(&alarm);
    sensor.attach(&display);

    sensor.setTemperature(25.0f);
    sensor.setTemperature(35.0f);
    sensor.setTemperature(45.0f);

    return 0;
}