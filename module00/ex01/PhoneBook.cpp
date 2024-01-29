/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:43:25 by arashido          #+#    #+#             */
/*   Updated: 2024/01/19 15:15:25 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0), _maxIndex(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::addContact(Contact contact)
{
	this->_contacts[this->_index] = contact;
	std::cout << "Contact added successfully!" << std::endl << std::endl;
	this->_index++;
	this->_maxIndex++;
	if (this->_index == 8)
		this->_index = 0;
	if (this->_maxIndex > 8)
		this->_maxIndex = 8;
}

void PhoneBook::printContacts(void)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < this->_maxIndex; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		if (this->_contacts[i].getFirstName().length() > 10)
			std::cout << this->_contacts[i].getFirstName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contacts[i].getFirstName();
		std::cout << "|";
		if (this->_contacts[i].getLastName().length() > 10)
			std::cout << this->_contacts[i].getLastName().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contacts[i].getLastName();
		std::cout << "|";
		if (this->_contacts[i].getNickname().length() > 10)
			std::cout << this->_contacts[i].getNickname().substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contacts[i].getNickname();
		std::cout << "|" << std::endl;
		std::cout << "+----------+----------+----------+----------+" << std::endl;
	}
}

void PhoneBook::searchContact(void)
{
	std::string index;

	PhoneBook::printContacts();
	std::cout << "Enter the index of the contact you want to view: ";
	if (!std::getline(std::cin, index))
		return ;
	while (1)
	{
		if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
		{
			if (index[0] - '0' <= this->_maxIndex)
			{
				this->_contacts[index[0] - '1'].printContact();
				break ;
			}
			else
			{
				std::cout << "Contact does not exist!" << std::endl << std::endl;
				break ;
			}
		}
		else
		{
			std::cout << "Invalid index!" << std::endl << std::endl;
			break ;
		}
	}
}