#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

int RPN::evaluate(const std::string &expression)
{
  std::string token;
  for (size_t i = 0; i < expression.size(); ++i)
  {
    if (isspace(expression[i]))
      continue;
    if (isdigit(expression[i]))
    {
      size_t j = i;
      while (j < expression.size() && isdigit(expression[j]))
        ++j;
      token = expression.substr(i, j - i);
      this->numbers.push(atoi(token.c_str()));
      i = j - 1;
    }
    else if (isOperator(expression[i]))
    {
      if (numbers.size() < 2) {
          std::cerr << "Error: Not enough operands for operator " << std::endl;
          return -1;
      }
      int operand2 = numbers.top();
      numbers.pop();
      int operand1 = numbers.top();
      numbers.pop();
      int result = calculate(operand1, operand2, expression[i]);
      numbers.push(result);
    }
    else
    {
      std::cerr << "Error: Invalid token " << expression[i] << std::endl;
      return -1;
    }
  }
  if (numbers.size() != 1)
  {
    std::cerr << "Error: Invalid expression" << std::endl;
    return -1;
  }
  return numbers.top();
}

bool RPN::isOperator(char c) const
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::calculate(int operand1, int operand2, char op) const
{
  switch (op)
  {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
      if (operand2 == 0) {
          throw std::runtime_error("Error: Division by zero");
      }
      return operand1 / operand2;
    default:
      return 0;
  }
}