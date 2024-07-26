#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;

unsigned long long fibonacci(int n)
{
    if (n <= 1)
        return n;
    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void threadFunction(int n)
{
    unsigned long long result = fibonacci(n);

    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "INdex: " << n << " Result: " << result << std::endl;
}

int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 20; ++i)
    {
        threads.emplace_back(threadFunction, i);
    }

    for (auto &th : threads)
    {
        th.join();
    }

    return 0;
}
