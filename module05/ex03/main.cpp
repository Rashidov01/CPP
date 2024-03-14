/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:41:45 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 15:06:08 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		printMessage("-----------------------------------------------------------");
		Bureaucrat B("john", 39);
		printMessage("-----------------------------------------------------------");
		ShrubberyCreationForm A("target");
		printMessage("-----------------------------------------------------------");
		B.signAForm(A);
		printMessage("-----------------------------------------------------------");
		B.executeForm(A);
		printMessage("-----------------------------------------------------------");
	}
	{
		printMessage("-----------------------------------------------------------");
		Bureaucrat B("john", 19);
		printMessage("-----------------------------------------------------------");
		RobotomyRequestForm A("target");
		printMessage("-----------------------------------------------------------");
		B.signAForm(A);
		printMessage("-----------------------------------------------------------");
		B.executeForm(A);
		printMessage("-----------------------------------------------------------");
	}
	{
		printMessage("-----------------------------------------------------------");
		Bureaucrat B("john",3);
		printMessage("-----------------------------------------------------------");
		PresidentialPardonForm A("target");
		printMessage("-----------------------------------------------------------");
		B.signAForm(A);
		printMessage("-----------------------------------------------------------");
		B.executeForm(A);
		printMessage("-----------------------------------------------------------");
	}
}