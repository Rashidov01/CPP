#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
public:
  MutantStack() {}
  MutantStack(const MutantStack& object) : std::stack<T>(object) {}

  MutantStack& operator=(const MutantStack& rhs) {
    if (this != &rhs)
        this->c = rhs.c;
    return *this;
  }

  ~MutantStack() {}

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
};

#endif
