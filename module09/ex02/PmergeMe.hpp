#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <sstream>
# include <string>
# include <vector>

class PmergeMe
{
  private:
    // vector
    std::vector<int> _vecUnsorted;
    std::vector<std::pair<int, int> > _vecPaired;
    std::vector<int> _vecSorted;

    // list
    std::list<int> _listSorted;
    std::list<int> _listUnsorted;
    std::list<std::pair<int, int> > _listPaired;

    // sorting time
    double _vecSortTime;
    double _listSortTime;

  public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &object);
    PmergeMe(const char **av);
    PmergeMe &operator=(const PmergeMe &rhs);

    // sorting functions
    void vectorSort();
    void listSort();
    void routine();
};

#endif