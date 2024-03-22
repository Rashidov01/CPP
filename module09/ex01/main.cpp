#include "RPN.hpp"

bool has_operator(std::string str)
{
    if (str.find('+') == std::string::npos && str.find('/') == std::string::npos
        && str.find('-') == std::string::npos && str.find('*') == std::string::npos)
        return (0);
    return (1);
}

bool is_valid(std::string str)
{
	if (str.find_first_not_of("0123456789+/*- ") == std::string::npos)
		return (true);
	return (false);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (is_valid(argv[1]) && has_operator(argv[1]))
            RPN reverse_polish_notation(argv[1]);
        else
        {
            std::cout << "Invalid Expression:" << std::endl;
            std::cout << "Use numbers and arithemitic operators" << std::endl;
        }
    }
    else
    {
        std::cout << "Error" << std::endl;
        std::cout << "usage: ./RPN <expression>" << std::endl;
    }
}