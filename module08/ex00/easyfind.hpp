#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template< typename T>
int	easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Element not found");
	return *it;
}

#endif