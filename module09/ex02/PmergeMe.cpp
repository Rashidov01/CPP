#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const char **av)
{
  for (size_t i = 1; av[i]; i++)
  {
    int num;
    if (std::istringstream(av[i]) >> num && num >= 0)
    {
      this->_vecUnsorted.push_back(num);
      this->_listUnsorted.push_back(num);
    }
    else {
      throw "Error: must be positive number!";
    }
  }
}

PmergeMe::PmergeMe(const PmergeMe &object)
{
    *this = object;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
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
  return *this;
}

PmergeMe::~PmergeMe(){}

// Vector Sorting

void PmergeMe::vectorSort()
{
  clock_t time = clock();

  
}