#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string argv)
{
	this->_div_zero = true;
	if (argv.size() > 3)
	{
		this->fillStack(argv);
		if (_div_zero == false)
		{
			std::cout << "Dividing by zero" << std::endl;
			return ;
		}
		std::cout << this->_rpn_num.top() << std::endl;
	}
}

RPN::RPN(const RPN &object)
{
	*this = object;
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_rpn_stack = rhs._rpn_stack;
		this->_rpn_num = rhs._rpn_num;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::calculate()
{
	char	operation;

	int operand1, operand2;
	operand2 = this->_rpn_num.top();
	this->_rpn_num.pop();
	operand1 = this->_rpn_num.top();
	this->_rpn_num.pop();
	operation = this->_rpn_stack.top();
	this->_rpn_stack.pop();
	if (operation == '/' && operand2 == 0)
		this->_div_zero = false;
	if (operation == '*')
		this->_rpn_num.push(operand1 * operand2);
	else if (operation == '/' && operand2 != 0)
		this->_rpn_num.push(operand1 / operand2);
	else if (operation == '-')
		this->_rpn_num.push(operand1 - operand2);
	else if (operation == '+')
		this->_rpn_num.push(operand1 + operand2);
}

void RPN::fillStack(std::string expr)
{
	int expr_size;

	expr_size = expr.size();
	for (int i = 0; i < expr_size; i++)
	{
		if (expr[i] != ' ')
		{
			if (isdigit(expr[i]) != 0)
				this->_rpn_num.push(expr[i] - '0');
			else
				this->_rpn_stack.push(expr[i]);
			if (this->_rpn_stack.size() == 1 && this->_rpn_num.size() >= 2)
				calculate();
		}
	}
}