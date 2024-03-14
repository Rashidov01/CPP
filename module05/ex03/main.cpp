/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:18:22 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 15:19:07 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	{
		std::string formName = "shrubbery creation";
		std::string formTarget = "Gorms";
		if (formName.empty() || formTarget.empty())
		{
				throw std::invalid_argument("Invalid parameters");
		}
		printMessage("---------------------------------------------------------------");
		Intern intern;
		printMessage("---------------------------------------------------------------");
		Bureaucrat bureaucrat("John", 1);
		printMessage("---------------------------------------------------------------");
		AForm *f = intern.makeForm(formName, formTarget);
		printMessage("---------------------------------------------------------------");
		std::cout << *f;
		printMessage("---------------------------------------------------------------");
		bureaucrat.signAForm(*f);
		printMessage("---------------------------------------------------------------");
		std::cout << (*f).getSigned() << std::endl;
		printMessage("---------------------------------------------------------------");
		bureaucrat.executeForm(*f);
		printMessage("---------------------------------------------------------------");
		delete f;
		printMessage("---------------------------------------------------------------");
	}
}