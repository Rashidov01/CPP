/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:43:45 by arashido          #+#    #+#             */
/*   Updated: 2024/03/03 18:51:45 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Bob", 5);
	std::cout << b << std::endl;
	b.gradeIncrement();
	std::cout << b << std::endl;
	b.gradeDecrement();
	std::cout << b << std::endl;
	Bureaucrat be("Nass", -8);
	std::cout << be << std::endl;
	return 0;
}
