#include <iostream>
#include <sstream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments. Usage: ./convert <arg>" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    if (input.empty()) {
        std::cerr << "Empty input argument." << std::endl;
        return 1;
    }

    if (input.size() == 1 && std::isalpha(input[0]))  {
        char ch = input[0];
        std::cout << "char: '" << ch << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(ch) << std::endl;
        std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
        return 0;
    }

    if (input.back() == 'f') {
        ScalarConverter::toChar(input);
        ScalarConverter::toInt(input);
        ScalarConverter::toFloat(input);
        ScalarConverter::toDouble(std::to_string(std::stof(input)));
    } else {
        std::istringstream iss(input);
        double value;
        if (!(iss >> value)) {
            std::cerr << "Invalid input value: " << input << ". Unable to convert to double." << std::endl;
            return 1;
        }

        ScalarConverter::toChar(input);
        ScalarConverter::toInt(input);
        ScalarConverter::toFloat(input);
        ScalarConverter::toDouble(input);
    }

    return 0;
}
