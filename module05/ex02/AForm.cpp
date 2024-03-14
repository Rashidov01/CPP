/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:17:29 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 15:59:45 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("No Name"), _isSigned(false), _signGrade(1), _execGrade(5)
{
	printMessage("AForm Default Constructor called", Color::Green);
}

AForm::AForm(std::string name, int _signGrade, int _execGrade):
	_name(name), _isSigned(false), _signGrade(_signGrade),
	_execGrade(_execGrade)
{
	printMessage("AForm Name Constructor called", Color::Green);
	try
	{
		if (this->_execGrade > 150 || this->_signGrade > 150)
			throw AForm::GradeTooLowException();
		else if (this->_execGrade < 1 || this->_signGrade < 1)
			throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm::AForm(AForm const &object):
	_name(object._name), _isSigned(object._isSigned),
	_signGrade(object._signGrade), _execGrade(object._execGrade)
{
	std::cout << "AForm Copy Constructor called" << '\n';
}

AForm & AForm::operator=(AForm const &rhs)
{
	printMessage("Bureaucrat Copy Assignment Operator = called", Color::Orange);
	if (this != &rhs)
	{
		const_cast<std::string&>(this->_name) = rhs.getName();
		const_cast<int&>(this->_signGrade) = rhs.getSignGrade();
		const_cast<int&>(this->_execGrade) = rhs.getExecGrade();
		this->_isSigned= rhs.getSigned();
	}
	return(*this);
}

std::ostream &operator<<(std::ostream &COUT, AForm const &rhs)
{
	printMessage("Bureaucrat Copy Assignment Operator << called", Color::Orange);
	COUT << "AForm name: " << rhs.getName() << '\n';
	COUT << "Grade to sign: " << rhs.getSignGrade() << '\n';
	COUT << "Grade to execute: " << rhs.getExecGrade() << '\n';
	COUT << "Signed: " << rhs.getSigned() << '\n';
	return (COUT);
}

AForm::~AForm()
{
	printMessage("AForm Destructor called", Color::Red);
}

void	AForm::beSigned(Bureaucrat const &rhs)
{
	if (rhs.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

bool	AForm::getSigned() const
{
	return (this->_isSigned);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

std::string AForm::getName() const
{
	return (this->_name);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade Too Low");

}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade Too High");
}