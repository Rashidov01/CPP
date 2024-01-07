/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:04:49 by arashido          #+#    #+#             */
/*   Updated: 2024/01/07 12:33:03 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	printWrongMessage("WrongAnimal default constructor called", 32);
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	printWrongMessage("WrongAnimal name constructor called", 32);
}

WrongAnimal::~WrongAnimal(void)
{
	printWrongMessage("WrongAnimal default destructor called", 31);
}

WrongAnimal::WrongAnimal(const WrongAnimal &object)
{
	printWrongMessage("WrongAnimal copy constructor called", 32);
	*this = object;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	printWrongMessage("WrongAnimal copy assigment called", 32);
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	printWrongMessage("WrongAnimal makeSound called", 32);
}

std::string WrongAnimal::getType() const
{
	printWrongMessage("WrongAnimal getter called", 32);
	return (this->_type);
}

void	printWrongMessage(const std::string &message, int colorCode)
{
	std::string colorStart = "\033[0;";
	std::string colorEnd = "\033[0m";
	// COLORS: 31red; 32green; 33yellow; 34blue; 35meganta; 36cyan; 37white
	std::cout << colorStart << colorCode << "m" << message << colorEnd << std::endl;
}