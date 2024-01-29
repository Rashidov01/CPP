/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:16:57 by arashido          #+#    #+#             */
/*   Updated: 2024/01/29 08:02:09 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat() : _type("Cat")
{
	printMessage("Cat default constructor called", 35);
	try
	{
		this->_brain = new Brain();
	}
	catch (const std::bad_alloc &e)
	{
		std::cout << "Memory allocation failed: " << e.what() << std::endl;
	}
}

Cat::~Cat()
{
	printMessage("Cat destructor called", 31);
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	printMessage("Cat copy constructor called", 35);
	*this = obj;
}

Cat &Cat::operator=(const Cat &rhs)
{
	printMessage("Cat copy assigment called", 35);
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain();
		this->_brain->setIdeas(rhs._brain->getIdeaas());
	}
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

Brain *Cat::getBrain() const
{
	return (this->_brain);
}
