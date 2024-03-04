/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:43:45 by arashido          #+#    #+#             */
/*   Updated: 2024/03/04 19:56:23 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bureaucrat_1("Test1", 3);
	printMessage( "-------------------------------------------------");
	Bureaucrat bureaucrat_2("Test2", 75);
	printMessage( "-------------------------------------------------");
	std::cout << bureaucrat_1 << std::endl;
	printMessage( "-------------------------------------------------");
	std::cout << bureaucrat_2 << std::endl;
	printMessage( "-------------------------------------------------");
	Form form_1("1. Form", 5, 10);
	printMessage( "-------------------------------------------------");
	std::cout << form_1 << std::endl;
	printMessage( "-------------------------------------------------");
	printMessage( "-------------------------------------------------");
	try {
		Form form_2("1. Form", 8996, 10);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	printMessage( "-------------------------------------------------");
	try {
		bureaucrat_1.signForm(form_1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	printMessage( "-------------------------------------------------");
	printMessage(form_1);
	printMessage( "-------------------------------------------------");
	try {
		bureaucrat_2.signForm(form_1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	printMessage( "-------------------------------------------------");
	printMessage(form_1);
	return 0;
}