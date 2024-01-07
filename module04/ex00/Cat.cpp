/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:33:12 by arashido          #+#    #+#             */
/*   Updated: 2024/01/07 12:42:48 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat")
{
	printMessage("Cat default constructor called", 35);
}

Cat::~Cat()
{
	printMessage("Cat destructor called", 31);
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	printMessage("Cat operator overloading called", 35);
	*this = obj;
}

Cat &Cat::operator=(Cat const &rhs)
{
	printMessage("Cat copy assigment called", 35);
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "\033[0;30mCat makes a sound: \033[0m";
	printMessage("MEEEEOOOOWWWWW!", 35);
}

std::string Cat::getType() const
{
	printMessage("Cat getter called", 35);
	return (this->_type);
}
