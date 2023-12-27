/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:46:04 by arashido          #+#    #+#             */
/*   Updated: 2023/12/27 17:48:00 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixed(n << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixed(roundf(n * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_fixed = fixed.getRawBits();
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

// ***************** ex01 ***************** //

std::ostream &operator<<(std::ostream &COUT, Fixed const &fixed)
{
	COUT << fixed.toFloat();
	return (COUT);
}

float Fixed::toFloat() const
{
	return (roundf(this->_fixed) / (1 << this->_bits));
}

int Fixed::toInt() const
{
	return (this->_fixed >> this->_bits);
}
