/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:03:21 by arashido          #+#    #+#             */
/*   Updated: 2023/12/13 12:10:54 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &A) : _name(name), _WeaponA(A)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_WeaponA.getType() << std::endl;
}
