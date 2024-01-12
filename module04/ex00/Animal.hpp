/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:49:24 by arashido          #+#    #+#             */
/*   Updated: 2024/01/10 17:01:02 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(std::string name);
	Animal(const Animal &);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();

	virtual void makeSound() const;
	virtual std::string getType() const;
};
	void printMessage(const std::string &message, int colorCode);

#endif
