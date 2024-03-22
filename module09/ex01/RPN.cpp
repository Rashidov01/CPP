#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string argv)
{
	this->_devideZero = true;
	if (argv.size() > 3)
	{
		this->fillStack(argv);
		if (_devideZero == false)
		{
			std::cout << "Dividing by zero" << std::endl;
			return ;
		}
		if (_rpnNum.size() != 1)
		{
			std::cout << "Invalid Exprssion" << std::endl;
		}
		else
		{
			std::cout << this->_rpnNum.top() << std::endl;
		}
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
		this->_rpnStack = rhs._rpnStack;
		this->_rpnNum = rhs._rpnNum;
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
	operand2 = this->_rpnNum.top();
	this->_rpnNum.pop();
	operand1 = this->_rpnNum.top();
	this->_rpnNum.pop();
	operation = this->_rpnStack.top();
	this->_rpnStack.pop();
	switch (operation) {
		case '*':
			this->_rpnNum.push(operand1 * operand2);
			break;
		case '/':
			this->_rpnNum.push(operand1 / operand2);
			break;
		case '-':
			this->_rpnNum.push(operand1 - operand2);
			break;
		case '+':
			this->_rpnNum.push(operand1 + operand2);
			break;
		default:
				throw std::runtime_error("Invalid operator encountered");
  }
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
				this->_rpnNum.push(expr[i] - '0');
			else
				this->_rpnStack.push(expr[i]);

			if (this->_rpnStack.size() == 1)
			{
				if (this->_rpnNum.size() < 2)
				{
					std::cerr << "Invalid Expression" << std::endl;
					exit(1);
				}
				calculate();
			}
		}
	}
}