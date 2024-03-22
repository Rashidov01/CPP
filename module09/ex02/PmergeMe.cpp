#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const char **av)
{
	int num;

	for (size_t i = 1; av[i]; i++)
	{
		if (std::istringstream(av[i]) >> num && num >= 0)
		{
			this->_listUnsorted.push_back(num);
			this->_vecUnsorted.push_back(num);
		}
		else
		{
			throw "Error: must be positive number!";
		}
	}
}

PmergeMe::PmergeMe(const PmergeMe &object)
{
	*this = object;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_listSorted = src._listSorted;
		_listPaired = src._listPaired;
		_listUnsorted = src._listUnsorted;
		_vecSorted = src._vecSorted;
		_vecPaired = src._vecPaired;
		_vecUnsorted = src._vecUnsorted;
		_vecSortTime = src._vecSortTime;
		_listSortTime = src._listSortTime;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

// Vector Sorting

void PmergeMe::vectorSort()
{
	clock_t	time;

	time = clock();
	for (size_t i = 0; i < this->_listUnsorted.size(); i++)
	{
		if (i == 0 && this->_vecUnsorted.size() % 2)
		{
			this->_vecPaired.push_back(std::make_pair(-1, this->_vecUnsorted[i]));
		}
		else
		{
			this->_vecPaired.push_back(std::make_pair(this->_vecUnsorted[i], this->_vecUnsorted[i + 1]));
			i++;
		}
	}
	for (std::vector<std::pair<int,int> >::iterator it = _vecPaired.begin(); it != _vecPaired.end(); it++)
	{
		if ((*it).first > (*it).second)
			std::swap((*it).first, (*it).second);
	}
	for (std::vector<std::pair<int, int> >::iterator it = _vecPaired.begin() + 1; it != _vecPaired.end(); it++)
	{
		std::vector<std::pair<int, int> >::iterator current = it;
		std::vector<std::pair<int, int> >::iterator prev = it - 1;
		while ((*current).first < (*prev).first)
		{
			std::swap((*current), (*prev));
			if (prev != _vecPaired.begin())
			{
				current = prev;
				prev = current - 1;
			}
		}
	}
	for (std::vector<std::pair<int,int> >::iterator it = _vecPaired.begin(); it != _vecPaired.end(); it++)
	{
		if (it->first != -1)
			this->_vecSorted.push_back(it->first);
	}
	for (std::vector<std::pair<int,int> >::iterator it = _vecPaired.begin(); it != _vecPaired.end(); it++)
	{
		std::vector<int>::iterator itSort;
		itSort = std::lower_bound(_vecSorted.begin(), _vecSorted.end(), it->second);
		this->_vecSorted.insert(itSort, it->second);
	}
	this->_vecSortTime = static_cast<double>((clock() - time) * 100.0 / CLOCKS_PER_SEC);
}

// List Sort
void PmergeMe::listSort()
{
	clock_t time = clock();

	for (std::list<int>::iterator it = this->_listUnsorted.begin(); it != this->_listUnsorted.end(); it++)
	{
		if (this->_listUnsorted.size() % 2 && it == this->_listUnsorted.begin())
		{
			this->_listPaired.push_back(std::make_pair(-1, *it));
		}
		else
		{
			std::list<int>::iterator next = it;
			next++;
			this->_listPaired.push_back(std::make_pair(*it, *next));
			it++;
		}
	}
	for (std::list<std::pair<int,int> >::iterator it = this->_listPaired.begin(); it != this->_listPaired.end(); it++)
	{
		if (it->first > it->second)
		{
			std::swap(it->first, it->second);
		}
	}
	for (std::list<std::pair<int,int> >::iterator it = std::next(this->_listPaired.begin()); it != this->_listPaired.end(); it++)
	{
		std::list<std::pair<int, int> >::iterator current = it;
		std::list<std::pair<int, int> >::iterator prev = std::prev(it);
		;

		while (current->first < prev->first)
		{
			std::swap(*current, *prev);
			if (prev != this->_listPaired.begin())
			{
				current = prev;
				prev = std::prev(current);
			}
		}
	}
	for (std::list<std::pair<int,int> >::iterator it = this->_listPaired.begin(); it != this->_listPaired.end(); it++)
	{
		if (it->first != -1)
			this->_listSorted.push_back(it->first);
	}
	for (std::list<std::pair<int,int> >::iterator it = this->_listPaired.begin(); it != this->_listPaired.end(); it++)
	{
		std::list<int>::iterator itSort = std::lower_bound(this->_listSorted.begin(),
			this->_listSorted.end(), it->second);
		this->_listSorted.insert(itSort, it->second);
	}

	clock_t end = clock();

	this->_listSortTime = static_cast<double>((end - time) * 100.0 / CLOCKS_PER_SEC);
}

void PmergeMe::routine()
{
  std::cout << "Before Sorting : ";
  for(std::vector<int>::iterator it = this->_vecUnsorted.begin(); it !=_vecUnsorted.end(); it++)
      std::cout << *it << " ";
  std::cout << '\n';
  std::cout << "After Sorting  : ";
  for(std::vector<int>::iterator it = this->_vecSorted.begin(); it !=_vecSorted.end(); it++)
      std::cout << *it << " ";
  std::cout << '\n';
  std::cout << "Time to process a range of " << this->_vecUnsorted.size() << " elements with std::vector : " << this->_vecSortTime << " us" << '\n';
  std::cout << "Time to process a range of " << this->_listUnsorted.size() << " elements with std::list   : " << this->_listSortTime << " us" << '\n';
}