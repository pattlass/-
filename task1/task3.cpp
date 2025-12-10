#include <iostream>
#include <vector>
#include <chrono>


int main()
{
    setlocale(LC_ALL, "");

    std::cout << "=== Задание 3: профилирование ===" << std::endl;

    const int iterations = 1'000'000;  // 1 000 000 итераций

    std::vector<int> data;
    data.reserve(iterations); // заранее выделяем память

    auto start = std::chrono::high_resolution_clock::now();

    long long sum = 0;
    for (int i = 0; i < iterations; ++i)
    {
        data.push_back(i);  // потребляет память
        sum += i;           // нагружает CPU
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Сумма = " << sum << std::endl;
    std::cout << "Время выполнения = " << ms << " мс" << std::endl;

    std::cout << "Нажмите Enter для выхода..." << std::endl;
    std::cin.get();

    return 0;
}	
