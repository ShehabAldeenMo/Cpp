#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

class MyPrinter
{
private:
    std::string str;

    int char_count;
    int thread_count;
    int next_char;
    int allowed_thread;

    std::vector<std::thread> threads;
    std::vector<std::thread::id> thread_ids;
    std::mutex mutex_lock;
    std::condition_variable cv;

public:
    MyPrinter(std::string s, int c_count, int t_count)
    {
        str = s;
        char_count = c_count;
        thread_count = t_count;
        next_char = 0;
        allowed_thread = 0;
    }

    int getCurrentThreadId(const std::thread::id id)
    {
        int thread_id = 0;
        for (auto e : thread_ids)
        {
            if (e == id)
            {
                return thread_id;
            }
            thread_id++;
        }
        return -1;
    }

    void run()
    {
        for (int i = 0; i < thread_count; i++)
        {
            std::thread t(&MyPrinter::print_thread, this);
            std::cout << "Thread " << t.get_id() << " is: " << i << "\n";
            thread_ids.push_back(t.get_id());
            threads.push_back(move(t));
        }

        for (int i = 0; i < thread_count; i++)
        {
            threads.at(i).join();
        }
    }

    void waitforallthreadsinit()
    {
        while (1)
        {
            if (thread_count == thread_ids.size())
                return;
        }
    }

    void print_thread()
    {
        while (1)
        {
            waitforallthreadsinit();
            std::unique_lock<std::mutex> lock(mutex_lock);
            cv.wait(lock, [this]
                    { return std::this_thread::get_id() == thread_ids[allowed_thread]; });
            print_chars();
            allowed_thread++;
            if (allowed_thread == thread_count)
            {
                allowed_thread = 0;
            }
            if (next_char >= str.length())
            {
                next_char -= str.length();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            lock.unlock();
            cv.notify_all();
        }
    }

    void print_chars()
    {
        std::cout << "ThreadId " << getCurrentThreadId(std::this_thread::get_id()) << ":";
        int printcount = 0;
        for (int i = next_char; i < str.length() && printcount < char_count; i++)
        {
            std::cout << str[i];
            printcount++;
        }

        if (printcount < char_count)
        {
            for (int i = 0; i < char_count - printcount; i++)
            {
                std::cout << str[i];
            }
        }
        next_char += char_count;
        std::cout << "\n";
    }
};

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Please provide 3 arguments ---> string  char_count thead_count\n";
        exit(EXIT_FAILURE);
    }
    std::string s = argv[1];
    int char_count = atoi(argv[2]);
    int thread_count = atoi(argv[3]);

    MyPrinter p(s, char_count, thread_count);
    p.run();
    return 0;
}