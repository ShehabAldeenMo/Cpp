#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable cv;
std::mutex n;
long balance = 0;

void addMoney(int money)
{
    std::lock_guard<std::mutex> lg(n);
    balance += money;
    std::cout << "Amount Added Current Balance: " << balance << "\n";
    cv.notify_one();
}

void withdrowMoney(int money)
{
    std::unique_lock<std::mutex> ul(n);
    cv.wait(ul, []
            { return (balance != 0) ? true : false; });
    if (balance >= money)
    {
        balance -= money;
        std::cout << "Amount Deducted:" << money << "\n";
    }
    else
    {
        std::cout << "Amount Can't Be Deducted, Current Balance Is Less Than " << money << "\n";
    }
    std::cout << "Current Balance Is: " << balance << "\n";
}

int main()
{
    std::thread t1(withdrowMoney, 500);
    std::thread t2(addMoney, 500);
    t1.join();
    t2.join();
    return 0;
}