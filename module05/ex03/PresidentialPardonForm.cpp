/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:42:13 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 15:03:14 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentialPardonForm", 25, 5), _target(_target)
{
	printMessage("PresidentialPardonForm Default Constructor called", Color::Green);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &object): AForm(object), _target(object.getTarget())
{
	printMessage("PresidentialPardonForm Copy Constructor called", Color::Green);
	*this = object;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	printMessage("PresidentialPardonForm Copy Assignment Operator called", Color::Orange);
	if (this != &rhs)
		AForm::operator=(rhs);
	return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	printMessage("PresidentialPardonForm Destructor called", Color::Red);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getExecGrade())
			{
				printMessage(this->getTarget() + " has been pardoned by Zaphod Beeblebrox");
			}
			else
				throw std::out_of_range("Bureaucrat Grade Not enough");
		}
		else
			throw std::out_of_range("Bureaucrat Form not signed");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}