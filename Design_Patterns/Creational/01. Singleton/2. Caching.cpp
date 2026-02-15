#include <iostream>
#include <unordered_map>
#include <string>

class Cache
{
private:
    std::unordered_map<std::string, std::string> cacheData;
    static Cache *instance;

    // Private constructor for Singleton
    Cache() {}

public:
    // Delete copy constructor and assignment operator
    Cache(const Cache &) = delete;
    Cache &operator=(const Cache &) = delete;

    // Global access point to the instance (Lazy Initialization)
    static Cache *getInstance()
    {
        // What if two instances access this line twice in the same time from two different threads ?
        // Will lead to make two allocation instance and violate singleton concept of design pattern
        // solved into 4-Advanced-Cpp/Design_Patterns/Singleton/Configuration_manger.cpp
        if (instance == nullptr)
        {
            instance = new Cache();
        }
        return instance;
    }

    void storeData(const std::string &key, const std::string &value)
    {
        cacheData[key] = value;
    }

    std::string getData(const std::string &key)
    {
        if (cacheData.find(key) != cacheData.end())
        {
            return cacheData[key];
        }
        return "Data not found";
    }
};

// Initialize static member. Lazy Initialization (pointer)
// not created excepts with first call
Cache *Cache::instance = nullptr;

int main()
{
    // Access the Cache Singleton
    // Why this operation is acceptable although you are delete assign operation ?
    // Because you aren't make object from this class. you are just make pointer assign operation
    // so there's no problem
    Cache *cache = Cache::getInstance();

    cache->storeData("user1", "Alice");
    cache->storeData("user2", "Bob");

    std::cout << "User1: " << cache->getData("user1") << std::endl;
    std::cout << "User2: " << cache->getData("user2") << std::endl;

    return 0;
}