#include "PmergeMe.hpp"

int main(int ac, char const *av[])
{
    if (ac < 2)
        return(1);
    PmergeMe sort(av);
    sort.vectorSort();
    sort.listSort();
    sort.output();
    return 0;
}