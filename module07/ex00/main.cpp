#include "whatever.hpp"

int main()
{
    int a = 1;
    int b = 2;

    std::cout << "Before swap: " << "a: " << a << " " << "b: " << b << '\n';
    ::swap(a, b);
    std::cout << "After swap : " << "a: " << a << " " << "b: " << b << '\n';
    std::cout << "-----------------------" << '\n';
    std::cout << "min(a, b)" << min(a, b) << '\n';
    std::cout << "max(a, b)" << max(a, b) << '\n';
}