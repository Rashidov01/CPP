#include "Array.hpp"

int	main(void)
{
	Array<int> arr1(5);
	for (unsigned int i = 0; i < arr1.size(); ++i)
	{
		arr1[i] = i + 1;
	}

	Array<int> arr2 = arr1;

    try {
        arr1[6] = 100;
        std::cout << "index accepted!!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(1);
    }

	std::cout << "arr1 elements:";
	for (unsigned int i = 0; i < arr1.size(); ++i)
	{
		std::cout << " " << arr1[i];
	}

	std::cout << std::endl;

	std::cout << "arr2 elements:";
	for (unsigned int i = 0; i < arr2.size(); ++i)
	{
		std::cout << " " << arr2[i];
	}

	std::cout << std::endl;

	return (0);
}