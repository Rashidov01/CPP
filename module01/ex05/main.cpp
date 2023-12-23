/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:12:49 by arashido          #+#    #+#             */
/*   Updated: 2023/12/23 19:16:54 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl Person;

	Person.complain("DEBUG");
	Person.complain("INFO");
	Person.complain("WARNING");
	Person.complain("ERROR");
}