/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:43:45 by arashido          #+#    #+#             */
/*   Updated: 2024/03/14 16:05:20 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Bob", 5);
	// std::cout << b.getGrade() << '\n';
	std::cout << b << std::endl;
	b.gradeIncrement();
	// std::cout << b.getGrade() << '\n';
	std::cout << b << std::endl;
	b.gradeDecrement();
	// std::cout << b.getGrade() << '\n';
	b.gradeDecrement();
	// std::cout << b.getGrade() << '\n';
	std::cout << b << std::endl;
	Bureaucrat be("Nass", -8);
	std::cout << be << std::endl;
	return 0;
}
