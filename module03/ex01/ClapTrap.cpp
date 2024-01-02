/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:17:27 by arashido          #+#    #+#             */
/*   Updated: 2024/01/02 20:11:01 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>

static std::string intToString(int number)
{
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

void	printMessage(const std::string &message, int colorCode)
{
	std::string colorStart = "\033[0;";
	std::string colorEnd = "\033[0m";
	// COLORS: 31red; 32green; 33yellow; 34blue; 35meganta; 36cyan; 37white
	std::cout << colorStart << colorCode << "m" << message << colorEnd << std::endl;
}

ClapTrap::ClapTrap(void)
{
	printMessage("Default constructor called");
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	printMessage("ClapTrap " + _name + " is born!", 32);
}

ClapTrap::~ClapTrap(void)
{
	printMessage("ClapTrap destructor called", 31);
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	printMessage("ClapTrap copy constructor called");
}

ClapTrap &ClapTrap::operator=(const ClapTrap &object)
{
	printMessage("ClapTrap Copy Assignment Operator called");
	if (this != &object)
	{
		this->_name = object._name;
		this->_hitPoints = object._hitPoints;
		this->_energyPoints = object._energyPoints;
		this->_attackDamage = object._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (_energyPoints <= 0)
		printMessage("ClapTrap" + _name + " is out of energy", 90);
	printMessage("ClapTrap " + _name + " attacks " + target + ", causing " + intToString(_attackDamage) + " points of demage!", 90);
	_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (int(amount) < 0)
	{
		printMessage("Invalid value entered", 31);
		return ;
	}
	if (this->_hitPoints < amount)
	{
		this->_hitPoints = 0;
		printMessage("ClapTrap " + this->_name + " takeDemage()", 90);
		printMessage("ClapTrap " + this->_name + " has " + intToString(this->_hitPoints) + " point left!", 31);
		return ;
	}
	printMessage("ClapTrap " + this->_name + " takes " + intToString(amount) + " demage!", 93);
	_hitPoints -= int(amount);
	printMessage("ClapTrap " + this->_name + " " + intToString(_hitPoints) + " Hitpoints left.", 36);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
		printMessage("ClapTrap " + _name + " is out of energy!", 90);
	printMessage("ClapTrap " + _name + " repairs itself for " + intToString(amount) + " hit points!", 32);
	_energyPoints -= 1;
	_hitPoints += int(amount);
	printMessage("ClapTrap now has " + intToString(this->_hitPoints) + " hit points!", 36);
	printMessage("ClapTrap now has " + intToString(this->_energyPoints) + " energy points!", 36);
}
