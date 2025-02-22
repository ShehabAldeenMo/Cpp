#include <iostream>

class RealFileSystem
{
public:
    RealFileSystem()
    {
        // Simulate heavy initialization
        std::cout << "Loading file system...\n";
    }

    void readFile()
    {
        std::cout << "Reading file from file system...\n";
    }
};

class FileSystemProxy
{
private:
    RealFileSystem *realFileSystem;

public:
    FileSystemProxy() : realFileSystem(nullptr) {}

    void readFile()
    {
        if (!realFileSystem)
        {
            std::cout << "Initializing file system on-demand...\n";
            realFileSystem = new RealFileSystem(); // Delayed initialization
        }
        realFileSystem->readFile();
    }
};

int main()
{
    FileSystemProxy proxy;
    proxy.readFile(); // File system is loaded only when necessary
    return 0;
}