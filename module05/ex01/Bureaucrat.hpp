/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:43:42 by arashido          #+#    #+#             */
/*   Updated: 2024/03/10 17:35:24 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define BLUE    "\033[34m"

#include <iostream>
#include <string>
#include "PrintMessage.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat
{
  private:
    const std::string _name;
    int _grade;

    class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
    void validateGrade(int grade) const;
  public:
    Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &object);
		Bureaucrat & operator=(Bureaucrat const &rhs);
		~Bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		void		gradeIncrement();
		void		gradeDecrement();
		void		signForm(Form &form);
};

std::ostream &operator<<(std::ostream &COUT, Bureaucrat const &rhs);

#endif