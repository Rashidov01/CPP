/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:27:48 by arashido          #+#    #+#             */
/*   Updated: 2024/01/06 16:46:12 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>

class Dog : public Animal
{
  public:
	Dog();
	~Dog();
	Dog &operator=(const Dog &rhs);
	Dog(const Dog &obj);

	void makeSound() const;
	std::string getType() const;
};

#endif