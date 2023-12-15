/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:12:10 by arashido          #+#    #+#             */
/*   Updated: 2023/12/13 12:26:08 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
  private:
	Weapon *_WeaponB;
	std::string _name;

  public:
	HumanB(std::string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon &B);
};

#endif
