#include <iostream>
#include <fstream>
#include <string>

class Logger
{
private:
    // Private constructor to prevent multiple instances
    Logger()
    {
        logFile.open("log.txt", std::ios::app);
        if (!logFile.is_open())
        {
            std::cerr << "Failed to open log file!" << std::endl;
        }
    }

    ~Logger()
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
    }

    // Eagerly creating the single instance
    static Logger instance;

    std::ofstream logFile;

public:
    Logger(const Logger &) = delete;            // delete copy constructor
    Logger &operator=(const Logger &) = delete; // delete assign operator overload

    // Global point of access to the instance
    static Logger &getInstance()
    {
        return instance;
    }

    void logMessage(const std::string &message)
    {
        if (logFile.is_open())
        {
            logFile << message << std::endl;
        }
        else
        {
            std::cerr << "Log file is not open!" << std::endl;
        }
    }
};

// Define and instantiate the Singleton instance (Eager Initialization)
Logger Logger::instance;

int main()
{
    // Using the Singleton instance for logging
    Logger::getInstance().logMessage("Application started.");
    Logger::getInstance().logMessage("Logging some important data.");

    return 0;
}