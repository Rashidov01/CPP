#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
  private:
	int _fixed;
	static const int _bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &object);
	~Fixed();
	Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif