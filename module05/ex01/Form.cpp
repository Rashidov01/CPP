/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:17:29 by arashido          #+#    #+#             */
/*   Updated: 2024/03/04 19:33:41 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("No Name"), _isSigned(false), _signGrade(1), _execGrade(5)
{
	printMessage("Form Default Constructor called", Color::Green);
}

Form::Form(std::string name, int _signGrade, int _execGrade):
	_name(name), _isSigned(false), _signGrade(_signGrade),
	_execGrade(_execGrade)
{
	printMessage("Form Name Constructor called", Color::Green);
	try
	{
		if (this->_execGrade > 150 || this->_signGrade > 150)
			throw Form::GradeTooLowException();
		else if (this->_execGrade < 1 || this->_signGrade < 1)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Form::Form(Form const &object):
	_name(object._name), _isSigned(object._isSigned),
	_signGrade(object._signGrade), _execGrade(object._execGrade)
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form & Form::operator=(Form const &rhs)
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

std::ostream &operator<<(std::ostream &out, Form const &rhs)
{
	printMessage("Bureaucrat Copy Assignment Operator << called", Color::Orange);
	out << "Form name: " << rhs.getName() << std::endl;
	out << "Grade to sign: " << rhs.getSignGrade() << std::endl;
	out << "Grade to execute: " << rhs.getExecGrade() << std::endl;
	out << "Signed: " << rhs.getSigned() << std::endl;
	return (out);
}

Form::~Form()
{
	printMessage("Form Destructor called", Color::Red);
}

void	Form::beSigned(Bureaucrat const &rhs)
{
	if (rhs.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

bool	Form::getSigned() const
{
	return (this->_isSigned);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

std::string Form::getName() const
{
	return (this->_name);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade Too Low");
}