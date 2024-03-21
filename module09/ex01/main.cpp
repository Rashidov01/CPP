#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
      std::cerr << "Usage: " << av[0] << " <RPN expression>" << '\n';
        return 1;
    }

    RPN calculator;
    try {
        int result = calculator.evaluate(av[1]);
        if (result != -1) {
            std::cout << "Result: " << result << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}