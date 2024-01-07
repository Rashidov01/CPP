/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:05:23 by arashido          #+#    #+#             */
/*   Updated: 2024/01/07 12:42:27 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	printWrongMessage("WrongCat default constructor called", 35);
}

WrongCat::~WrongCat()
{
	printWrongMessage("WrongCat destructor called", 31);
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	printWrongMessage("WrongCat operator overloading called", 35);
	*this = obj;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	printWrongMessage("WrongCat copy assigment called", 35);
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	printWrongMessage("Wrong cate MakeSound() called", 90);
}

std::string WrongCat::getType() const
{
	printWrongMessage("WrongCat getter called", 35);
	return (this->_type);
}
