/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:17:00 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 15:59:12 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
#include  "PrintMessage.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

  protected:
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

	public:
		AForm();
		AForm(std::string name, int _signGrade, int _execGrade);
		AForm(AForm const &object);
		AForm & operator=(AForm const &rhs);
		virtual ~AForm() = 0;
		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(Bureaucrat const &rhs);
		virtual void		execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &COUT, AForm const &rhs);

#endif
