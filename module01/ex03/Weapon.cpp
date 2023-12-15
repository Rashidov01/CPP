/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:35:54 by arashido          #+#    #+#             */
/*   Updated: 2023/12/13 11:59:37 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}

const std::string &Weapon::getType()
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
