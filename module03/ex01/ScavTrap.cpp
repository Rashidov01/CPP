/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:16:49 by arashido          #+#    #+#             */
/*   Updated: 2024/01/12 18:22:41 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>

static std::string intToString(int number)
{
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

ScavTrap::ScavTrap()
{
	printMessage("ScavTrap default constructor called", 32);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	printMessage("ScavTrap is born!", 90);
	this->_name = name;
	if (this->_name.length())
		this->_name = "NO NAME ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	printMessage("Scavtrap destructor called", 31);
}

ScavTrap::ScavTrap(const ScavTrap &object) : ClapTrap(object)
{
	printMessage("Copy Constructor called", 90);
	*this = object;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	printMessage("ScavTrap copy assigment called", 90);
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	printMessage("ScavTrap attack() is called.", 90);
	if (!this->_hitPoints)
	{
		printMessage("ScavTrap " + this->_name + " has no hit points!", 31);
		return ;
	}
	else if (!this->_energyPoints)
	{
		printMessage("ScavTrap " + this->_name + " has no energy points!", 31);
		return ;
	}
	this->_energyPoints -= 1;
	if (target.length())
		printMessage("ScavTrap " + this->_name + " attacks " + target + ", causing " + intToString(this->_attackDamage) + " points of demage!",
			31);
	else
		printMessage("Target not set", 31);
}

void ScavTrap::guardGate(void)
{
	printMessage("ScavTrap guardGate() called", 90);
	printMessage("ScavTrap " + this->_name + "is now Gate keeper mode.", 90);
}
