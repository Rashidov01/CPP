/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:16:25 by arashido          #+#    #+#             */
/*   Updated: 2024/01/10 16:59:01 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>

class Cat : public Animal
{
  public:
	Cat();
	~Cat();
	Cat(const Cat &obj);
	Cat &operator=(const Cat &rhs);

	void makeSound() const;
	std::string getType() const;
};

#endif