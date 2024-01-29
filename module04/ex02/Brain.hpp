/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:41:55 by arashido          #+#    #+#             */
/*   Updated: 2024/01/12 18:41:56 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <cstdlib>
# include <iostream>
# include <string>

class Brain
{
  public:
	std::string ideas[100];

	Brain();
	Brain(Brain const &Object);
	Brain &operator=(Brain const &rhs);
	~Brain();
	void getIdeas() const;
	void setIdeas(std::string *ideas);
	std::string *getIdeaas();
	void changeIdeas();
};

#endif
