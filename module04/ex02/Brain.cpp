/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:41:05 by arashido          #+#    #+#             */
/*   Updated: 2024/01/12 19:11:07 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
	std::string idea[10] = {"idea1", "idea2","idea3","idea4","idea5","idea6", "idea7","idea8","idea9","idea10"};
	for(int i = 0; i < 10; i++)
		this->ideas[i] = idea[rand() % 10];
	for(int i = 0; i < 10; i++)
		std::cout << ideas[i] << std::endl;
}


Brain::Brain(Brain const &Object)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = Object;
}

Brain & Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
	{
		for(int i = 0; i < 10; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::getIdeas() const
{
	for(int i = 0; i < 10; i++)
		std::cout << ideas[i] << std::endl;
}

void	Brain::setIdeas(std::string *ideas)
{
	for (int i = 0; i < 10; i++)
		this->ideas[i] = ideas[i];
}

void	Brain::changeIdeas() {
	for (int i = 0; i < 10; i++)
		this->ideas[i] = "Another ideas";
}

std::string	*Brain::getIdeaas() {
	return this->ideas;
}
