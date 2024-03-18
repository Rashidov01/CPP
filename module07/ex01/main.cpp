#include "iter.hpp"

int	main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "INT  Array: ";
	::iter(intArray, 5, printElement<int>);
	std::cout << '\n';
	std::cout << "CHAR Array: ";
	::iter(charArray, 5, printElement<char>);
	std::cout << '\n';
}