#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template< typename T>
int	easyfind(T &container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("Element not found");
	return *it;
}

#endif