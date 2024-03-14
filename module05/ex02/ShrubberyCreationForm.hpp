/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:03:41 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 17:03:43 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
	void	write_ascii_tree() const;
	class MyAppropriateExecption : public std::exception
	{
		public:
			const char *what() const throw();
	};
public:
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(ShrubberyCreationForm const &object);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

#endif