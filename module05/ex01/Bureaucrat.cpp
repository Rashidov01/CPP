/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:43:40 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 16:24:34 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("No Name"), _grade(0)
{
  printMessage("Bureaucrat Default Constructor called", Color::Green);
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    printMessage("Bureaucrat Name Constructor called", Color::Green);
    try
    {
        this->_grade = grade;
        validateGrade(grade);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &object)
{
	printMessage("Bureaucrat Copy Constructor called", Color::Green);
	*this = object;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	printMessage("Bureaucrat Copy Assignment Operator = called", Color::Orange);
	if (this != &rhs)
	{
		const_cast<std::string&>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &COUT, Bureaucrat const &rhs)
{
	printMessage("Bureaucrat Copy Assignment Operator << called", Color::Orange);
	try
	{
		if (rhs.getGrade() >= 151)
			throw std::exception();
		else if (rhs.getGrade() <= 0)
			throw std::exception();
		COUT << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << '\n';
	}

	catch(const std::exception& e)
	{
		std::cerr << "Grade Not In Range" << '\n';
	}
	return (COUT);
}

Bureaucrat::~Bureaucrat()
{
	printMessage("Bureaucrat Destructor called", Color::Red);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::validateGrade(int grade) const {
    if (grade >= 151)
        throw Bureaucrat::GradeTooLowException();
    else if (grade <= 0)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::gradeIncrement() {
    try {
        validateGrade(this->_grade - 1);
        this->_grade--;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::gradeDecrement() {
    try {
        validateGrade(this->_grade + 1);;
        this->_grade++;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade Too Low");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade Too High");
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		printMessage(this->_name + " signed " + form.getName(), Color::Blue);
	}
	catch(const std::exception& e)
	{
		std::cerr << BLUE << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}