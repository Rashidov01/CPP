#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

class RPN
{
  private:
    std::string _rpn;
    std::stack<char> _rpn_stack;
    std::stack<int> _rpn_num;
    bool _div_zero;

    void fillStack(std::string expr);
    void calculate();

  public:
    RPN();
    RPN(std::string argv);
    RPN(const RPN &object);
    RPN &operator=(const RPN &rhs);
    ~RPN();
};

#endif