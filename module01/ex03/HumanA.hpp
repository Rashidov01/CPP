/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:00:12 by arashido          #+#    #+#             */
/*   Updated: 2023/12/13 12:10:50 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
  private:
	std::string _name;
	Weapon &_WeaponA;

  public:
	HumanA(std::string name, Weapon &A);
	~HumanA();

	void attack();
};

#endif
