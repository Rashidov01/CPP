#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <cctype>
#include <stdbool.h>

class RPN {
  private:
    std::stack<int> numbers;
  public:
    RPN();
    ~RPN();
    int evaluate(const std::string &expression);
    bool isOperator(char c) const;
    int calculate(int operand1, int operand2, char op) const;
};

#endif