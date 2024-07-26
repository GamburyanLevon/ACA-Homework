#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;

unsigned long long factorial(int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

void threadFunction(int n, std::ofstream &outFile)
{
    unsigned long long result = factorial(n);

    std::lock_guard<std::mutex> lock(mtx);
    outFile << "Factorial of " << n << " is " << result << std::endl;
}

int main()
{
    std::vector<std::thread> threads;
    std::ofstream outFile("output.txt");

    if (!outFile.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }

    for (int i = 1; i <= 10; ++i)
    {
        threads.emplace_back(threadFunction, i, std::ref(outFile));
    }

    for (auto &th : threads)
    {
        th.join();
    }

    outFile.close();
    return 0;
}
