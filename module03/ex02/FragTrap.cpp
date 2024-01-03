/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:08:26 by arashido          #+#    #+#             */
/*   Updated: 2024/01/03 19:29:02 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap()
{
	printMessage("FragTrap Default Construtor is called.", 90);
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	printMessage("FragTrap Name Constructor called", 90);
	this->_name = name;
	if (!this->_name.length())
		this->_name = "NO NAME";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &object) : ClapTrap(object)
{
	printMessage("FragTrap Copy Constructor called", 90);
	*this = object;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	printMessage("FragTrap Copy Assignment Operator called", 90);
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	printMessage("FragTrap Destructor Called", 90);
}

void FragTrap::highFiveGuys()
{
    printMessage("FragTrap " + this->_name + " is asking for HighFive", 90);
}