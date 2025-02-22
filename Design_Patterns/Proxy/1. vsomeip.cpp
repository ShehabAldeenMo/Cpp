#include <iostream>

class RealService
{
public:
    void requestData()
    {
        std::cout << "Requesting data from VSomeIP service...\n";
        // Actual communication with VSomeIP happens here
    }
};

class ProxyService
{
private:
    RealService *realService;

public:
    ProxyService() : realService(nullptr) {}

    void requestData()
    {
        if (!realService)
        {
            std::cout << "Initializing RealService...\n";
            realService = new RealService(); // Connect to the real service
        }
        realService->requestData();
    }
};

int main()
{
    ProxyService proxy;
    proxy.requestData(); // Proxy handles communication with VSomeIP service
    return 0;
}