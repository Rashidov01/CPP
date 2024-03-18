#include "easyfind.hpp"
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers;
    for(int i = 1; i <= 5; i++)
      numbers.push_back(i);

    try {
        std::cout << easyfind(numbers, 3) << std::endl;
        std::cout << easyfind(numbers, 11) << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
