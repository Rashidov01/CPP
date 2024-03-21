#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>

class PmergeMe {
  private:
    // vector
    std::vector<int> _vecUnsorted;
    std::vector<std::pair<int, int> > _vecPaired;
    std::vector<int> _vecSorted;

    //list
    std::list<int> _listSorted;
    std::list<int> _listUnsorted;
     std::vector<std::pair<int, int> > _listPaired;

    double _vecSortTime;
    double _listSortTime;
  public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &object);
    PmergeMe(const char **av);
    PmergeMe &operator=(const PmergeMe &rhs);

    // Sorting Functions
    void vectorSort();
};

#endif