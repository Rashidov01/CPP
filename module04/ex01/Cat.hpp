/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:17:28 by arashido          #+#    #+#             */
/*   Updated: 2024/01/12 18:51:07 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public Animal
{
  private:
	Brain *_brain;

  protected:
	std::string _type;

  public:
	Cat();
	~Cat();
	Cat(const Cat &obj);
	Cat &operator=(const Cat &rhs);

	void makeSound() const;
	std::string getType() const;
	Brain *getBrain() const;
};

#endif
