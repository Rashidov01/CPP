#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int N): _max(N)
{}

Span::Span(Span const &object)
{
	*this = object;
}

Span & Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_max = rhs._max;
		this->_vec = rhs._vec;
	}
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(int num)
{
	if (this->_vec.size() == this->_max)
		throw Span::ContainerMaxException();
	if (num < 0)
		throw std::runtime_error("Number is Negative");
	this->_vec.push_back(num);
}

int	Span::shortestSpan()
{
	int minSpan;

	if (this->_vec.size() < 1)
		throw Span::ContainerEmptyException();
	std::sort(this->_vec.begin(), this->_vec.end());
	minSpan = this->_vec[1] - this->_vec[0];
	for (unsigned int i = 1; i < this->_vec.size() - 1; i++)
	{
		if (this->_vec[i + 1] - this->_vec[i] < minSpan)
			minSpan = this->_vec[i + 1] - this->_vec[i];
	}
	return (minSpan);
}

int Span::longestSpan() {
  if (this->_vec.size() < 1)
      throw Span::ContainerEmptyException();

  int minVal = *std::min_element(this->_vec.begin(), this->_vec.end());
  int maxVal = *std::max_element(this->_vec.begin(), this->_vec.end());

  return maxVal - minVal;
}

void	Span::addMoreNum(int size)
{
	for (int i = 0; i < size; i++)
		this->_vec.insert(this->_vec.begin(), rand() % 100);
}

const char	*Span::ContainerMaxException::what() const throw()
{
	return("Container(Vector) Is Full");
}

const char	*Span::ContainerEmptyException::what() const throw()
{
	return("Container(Vector) Is Empty");
}