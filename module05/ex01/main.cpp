/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:43:45 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 14:15:33 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Form form0("A99", 0, 5);
			printMessage(form0);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

	}

	printMessage("---------------------------------------");

	{
		try
		{
			Bureaucrat mike("Mike", 15);
			Form form("B58", 20, 45);
			printMessage(mike);
			printMessage(form);
			mike.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	printMessage("---------------------------------------");

	{
		try
		{
			Bureaucrat jon("Jon", 21);
			Form form2("C_303", 20, 45);
			printMessage(jon);
			printMessage(form2);
			jon.signForm(form2);
			printMessage(form2);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}