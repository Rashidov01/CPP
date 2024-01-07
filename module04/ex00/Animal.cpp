/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:53:36 by arashido          #+#    #+#             */
/*   Updated: 2024/01/07 11:10:17 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal")
{
	printMessage("Animal default constructor called", 32);
}

Animal::Animal(std::string type) : _type(type)
{
	printMessage("Animal name constructor called", 32);
}

Animal::~Animal(void)
{
	printMessage("Animal default destructor called", 31);
}

Animal::Animal(const Animal &object)
{
	printMessage("Animal copy constructor called", 32);
	*this = object;
}

Animal &Animal::operator=(const Animal &rhs)
{
	printMessage("Animal copy assigment called", 32);
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void Animal::makeSound() const
{
	printMessage("Animal makeSound called", 32);
}

std::string Animal::getType() const
{
	printMessage("Animal getter called", 32);
	return (this->_type);	
}

void	printMessage(const std::string &message, int colorCode)
{
	std::string colorStart = "\033[0;";
	std::string colorEnd = "\033[0m";
	// COLORS: 31red; 32green; 33yellow; 34blue; 35meganta; 36cyan; 37white
	std::cout << colorStart << colorCode << "m" << message << colorEnd << std::endl;
}