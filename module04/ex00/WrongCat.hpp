/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:05:57 by arashido          #+#    #+#             */
/*   Updated: 2024/01/07 12:06:29 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &obj);
	WrongCat &operator=(WrongCat const &rhs);

	void makeSound() const;
	std::string getType() const;
};

#endif