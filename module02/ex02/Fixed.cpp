/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:46:04 by arashido          #+#    #+#             */
/*   Updated: 2023/12/30 09:35:08 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
}

Fixed::Fixed(const Fixed &object)
{
	*this = object;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int n) : _fixed(n << _bits)
{
}

Fixed::Fixed(const float n) : _fixed(roundf(n * (1 << _bits)))
{
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

std::ostream &operator<<(std::ostream &COUT, Fixed const &fixed)
{
	COUT << fixed.toFloat();
	return (COUT);
}

float Fixed::toFloat() const
{
	return (((float)this->_fixed) / (1 << this->_bits));
}

int Fixed::toInt() const
{
	return (this->_fixed >> this->_bits);
}

/*********** COMPARISON OPERATOR **********/

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixed > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fixed < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixed >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixed <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixed == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fixed != rhs.getRawBits());
}

/************* ARITHEMETIC OPERATORS ***************/

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

/************* INCREMENT/DECREMENT OPERATORS *************/

Fixed &Fixed::operator++()
{
	this->_fixed = this->_fixed + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_fixed = this->_fixed - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->operator--();
	return (tmp);
}

/************* MIN/MAX OPERATORS **************/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
