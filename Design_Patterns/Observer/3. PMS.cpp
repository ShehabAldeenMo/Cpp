#include <iostream>
#include <vector>
#include <algorithm> // for std::remove

// Observer Interface
class Observer
{
public:
    virtual void onPowerStateChange(std::string state) = 0;
};

// Subject Interface (Notifier Interface)
class Notifier
{
public:
    virtual void setPowerState(std::string state) = 0;
};

// Event Manager Class: should be implemented in observer design pattern
class EventManager
{
private:
    std::vector<Observer *> observers;

public:
    void subscribe(Observer *observer)
    {
        observers.push_back(observer);
        std::cout << "EventManager: Observer subscribed." << std::endl;
    }

    void unsubscribe(Observer *observer)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        std::cout << "EventManager: Observer unsubscribed." << std::endl;
    }

    void notifyAll(std::string state)
    {
        std::cout << "EventManager: Notifying all observers of state change to '" << state << "'." << std::endl;
        for (Observer *observer : observers)
        {
            observer->onPowerStateChange(state);
        }
    }
};

// Power Manager Class (Notifier Implementation)
class PowerManager : public Notifier
{
private:
    std::string powerState;
    EventManager &eventManager;

public:
    PowerManager(EventManager &manager) : eventManager(manager) {}

    void setPowerState(std::string state) override
    {
        powerState = state;
        std::cout << "PowerManager: Power state changed to '" << powerState << "'." << std::endl;
        eventManager.notifyAll(powerState); // Notify observers via EventManager
    }
};

// Storage Observer (Saving Data)
class Storage : public Observer
{
public:
    void onPowerStateChange(std::string state) override
    {
        if (state == "low_power")
        {
            std::cout << "Storage: Saving data to prevent data loss." << std::endl;
        }
    }
};

// Network Observer (Shutting down network interfaces)
class Network : public Observer
{
public:
    void onPowerStateChange(std::string state) override
    {
        if (state == "shutdown")
        {
            std::cout << "Network: Closing network connections." << std::endl;
        }
    }
};

// Main Function
int main()
{
    EventManager eventManager;               // Create an Event Manager instance
    PowerManager powerManager(eventManager); // Pass Event Manager to Power Manager

    Storage storage;
    Network network;

    // Subscribe observers to event notifications
    eventManager.subscribe(&storage);
    eventManager.subscribe(&network);

    // Simulate power state changes
    powerManager.setPowerState("low_power");
    powerManager.setPowerState("shutdown");

    // Unsubscribe an observer (Network) and change power state again
    eventManager.unsubscribe(&network);
    powerManager.setPowerState("normal_power");

    return 0;
}