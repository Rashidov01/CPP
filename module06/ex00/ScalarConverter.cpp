#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	*this = obj;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{}
	return (*this);
}

static bool isCharString(const std::string& str) {
  return (str.length() == 1 && std::isprint(str[0])) || (str == "nan" || str == "inff" || str == "-inff");
}

void ScalarConverter::toChar(const std::string& str) {
    char ch = 0;
    if (isCharString(str)) {
        if (str.length() == 1 && std::isprint(str[0])) {
            ch = str[0];
        } else {
            std::cerr << "char: Non displayable" << std::endl;
            return;
        }
    } else {
        try {
            size_t pos;
            long long num = std::stoll(str, &pos);

            if (pos != str.length()) {
                throw std::invalid_argument("Invalid characters in input");
            }

            if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
                throw std::out_of_range("Value out of range for char");
            }

            if (num >= 33 && num <= 126) {
              ch = static_cast<char>(num);
            }
        } catch (const std::exception& e) {
            std::cerr << "char: impossible" << std::endl;
            return;
        }
    }

    if (std::isprint(ch) && !(ch >= '0' && ch <= '9')) {
        std::cout << "char: '" << ch << "'"  << std::endl;
    } else {
        std::cerr << "char: Non displayable" << std::endl;
    }
}

void	ScalarConverter::toInt(std::string str)
{
	int	num = 0;
	try
	{
		if (str.length() == 1 && !isdigit(str[0]))
			num = static_cast<int>(str[0]);
		else
		{
			int	base = 10;
			char *endptr = NULL;
			const long long num2 = std::strtoll(str.c_str(), &endptr, base);
			if (endptr == str.c_str())
				throw std::invalid_argument("no conversion possible");
			if (num2 < std::numeric_limits<int>::min() || num2 > std::numeric_limits<int>::max())
				throw std::out_of_range("out of range");
			num = static_cast<int>(num2);
		}
		std::cout << "int: " << num << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int: impossible" << '\n';
		return ;
	}
}

void	ScalarConverter::toFloat(std::string str)
{
	float num = 0;
	if (str.length() == 1 && !isdigit(str[0]))
		num = static_cast<float>(str[0]);
	else
		num = std::atof(str.c_str());
	if (num - static_cast<int>(num) == 0)
		std::cout << "float: " << num << ".0f" << std::endl;
	else
		std::cout << "float: " << num << "f" << std::endl;
}

void	ScalarConverter::toDouble(std::string str)
{
	double num = 0;
	if (str.length() == 1 && !isdigit(str[0]))
		num = static_cast<double>(str[0]);
	else
		num = std::atof(str.c_str());
	if (num - static_cast<int>(num) == 0)
		std::cout << "double: " << num << ".0" << std::endl;
	else
		std::cout << "double: " << num << std::endl;
}