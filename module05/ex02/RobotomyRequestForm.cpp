/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:42:54 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 15:05:06 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 72, 45), _target(_target)
{
	printMessage("RobotomyRequestForm Default Constructor called", Color::Green);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &object): AForm(object), _target(object.getTarget())
{
	printMessage("RobotomyRequestForm Copy Constructor called", Color::Green);
	*this = object;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	printMessage("RobotomyRequestForm Copy Assignment Operator called", Color::Orange);
	if (this != &rhs)
		AForm::operator=(rhs);
	return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	printMessage("RobotomyRequestForm Destructor called", Color::Red);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getExecGrade())
			{
				srand(time(NULL));
				if (rand() % 2)
				{
					printMessage("Drr....... Drr.......");
					printMessage(this->_target + " has been robotomized successfully", Color::Green);
				}
				else
					printMessage("robotomy failed!", Color::Red);
			}
			else
				throw std::out_of_range("Bureaucrat Grade Not Enough");
		}
		else
			throw std::out_of_range("Bureaucrat Form not signed");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}