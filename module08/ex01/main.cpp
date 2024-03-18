#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest span : " << sp.shortestSpan() << '\n';
		std::cout << "longest span  : " << sp.longestSpan() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp.addMoreNum(100);
		std::cout << "shortest span : " << sp.shortestSpan() << '\n';
		std::cout << "longest span  : " << sp.longestSpan() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}