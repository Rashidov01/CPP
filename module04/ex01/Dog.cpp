/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:51:07 by arashido          #+#    #+#             */
/*   Updated: 2024/01/12 18:51:24 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog() : _brain(new Brain()), _type("Dog")
{
	printMessage("Dog default constructor called", 36);
}

Dog::~Dog()
{
	printMessage("Dog destructor called", 31);
}

Dog &Dog::operator=(const Dog &rhs)
{
	printMessage("Dog copy assignment called", 36);
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	printMessage("Dog copy constructor called", 36);
	*this = obj;
}

void Dog::makeSound() const
{
	std::cout << "\033[0;30mDog makes a sound: \033[0m";
	printMessage("BAAAARRRRRKKKK!", 36);
}

std::string Dog::getType() const
{
	printMessage("Dog getter called", 36);
	return (this->_type);
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}
