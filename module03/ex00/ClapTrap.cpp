/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:25:19 by arashido          #+#    #+#             */
/*   Updated: 2024/01/02 15:29:30 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	printMessage(const std::string &message, int colorCode)
{
	std::string colorStart = "\033[0;";
	std::string colorEnd = "\033[0m";
	// 31:red; 32:green; 33:yellow; 34:blue; 35:meganta; 36:cyan; 37:white
	std::cout << colorStart << colorCode << "m" << message << colorEnd << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	printMessage("ClapTrap " + _name + " is born!", 32);
}

ClapTrap::~ClapTrap(void)
{
	printMessage("ClapTrap now has " + std::to_string(this->_energyPoints) + " Energy points!", 35);
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
	this->_name = object._name;
	this->_hitPoints = object._hitPoints;
	this->_energyPoints = object._energyPoints;
	this->_attackDamage = object._attackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (_energyPoints <= 0)
		printMessage("ClapTrap" + _name + " is out of energy", 90);
	printMessage("ClapTrap " + _name + " attacks " + target + ", causing " + std::to_string(_attackDamage) + " points of demage!", 90);
	_energyPoints += 1;
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
		printMessage("ClapTrap " + this->_name + " has " + std::to_string(this->_hitPoints) + " point left!", 31);
		return ;
	}
	printMessage("ClapTrap " + this->_name + " takes " + std::to_string(amount) + " demage!", 93);
	_hitPoints -= int(amount);
	printMessage("ClapTrap " + this->_name + " " + std::to_string(_hitPoints) + " Hitpoints left.", 36);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
		printMessage("ClapTrap " + _name + " is out of energy!", 90);
	printMessage("ClapTrap " + _name + " repairs itself for " + std::to_string(amount) + " hit points!", 32);
	_energyPoints += 1;
	_hitPoints += amount;
	printMessage("ClapTrap now has " + std::to_string(this->_hitPoints) + " hit points!", 32);
}
