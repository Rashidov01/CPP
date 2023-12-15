/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:47:04 by arashido          #+#    #+#             */
/*   Updated: 2023/12/13 10:54:07 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(void) {
	PhoneBook	phoneBook;
	std::string	input;
	Contact		contact;

	while (1) {
		std::cout << "+-------------------------------------------+" << std::endl;
		std::cout << "|        Commands: ADD, SEARCH, EXIT        |" << std::endl;
		std::cout << "+-------------------------------------------+" << std::endl;
		std::cout << "Enter a Command: ";
		if (!std::getline(std::cin, input))
			break ;
		if (input == "EXIT" || input == "exit") {
			break ;
		} else if (input == "ADD" || input == "add") {
			contact.setFirstName();
			contact.setLastName();
			contact.setNickName();
			contact.setPhoneNumber();
			contact.setDarkestSecret();
			phoneBook.addContact(contact);
		} else if (input == "SEARCH" || input == "search") {
			phoneBook.searchContact();
		}
	}
	return (0);
}
