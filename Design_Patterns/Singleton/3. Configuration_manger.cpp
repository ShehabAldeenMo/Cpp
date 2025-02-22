#include <iostream>
#include <map>
#include <string>
#include <mutex>

class ConfigurationManager
{
private:
    std::map<std::string, std::string> configData;
    static ConfigurationManager *instance;
    static std::mutex mutex_;

    // Private constructor for Singleton
    ConfigurationManager()
    {
        // Simulate loading configurations from a file
        configData["app_name"] = "MyApp";
        configData["version"] = "1.0.0";
    }

public:
    // Delete copy constructor and assignment operator
    ConfigurationManager(const ConfigurationManager &) = delete;
    ConfigurationManager &operator=(const ConfigurationManager &) = delete;

    // Global access point to the instance (Lazy Initialization with Thread-Safety)
    static ConfigurationManager *getInstance()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance == nullptr)
        {
            instance = new ConfigurationManager();
        }
        return instance;
    }

    std::string getConfig(const std::string &key)
    {
        return configData[key];
    }
};

// Initialize static members
ConfigurationManager *ConfigurationManager::instance = nullptr;
std::mutex ConfigurationManager::mutex_;

int main()
{
    // Access the ConfigurationManager Singleton
    ConfigurationManager *config = ConfigurationManager::getInstance();

    std::cout << "App Name: " << config->getConfig("app_name") << std::endl;
    std::cout << "Version: " << config->getConfig("version") << std::endl;

    return 0;
}