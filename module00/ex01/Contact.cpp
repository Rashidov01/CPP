/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:01:50 by arashido          #+#    #+#             */
/*   Updated: 2024/01/19 10:42:32 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""),
	_phoneNumber(""), _darkestSecret("")
{
}

Contact::~Contact(void)
{
	return ;
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
	const std::string &nickname, const std::string &phoneNumber,
	const std::string &darkSecret) : _firstName(firstName), _lastName(lastName),
	_nickName(nickname), _phoneNumber(phoneNumber),
	_darkestSecret(darkSecret){};

std::string validateInput(const std::string &message, bool allowEmpty = false)
{
	std::string input;
	while (true)
	{
		std::cout << message;
		if (!std::getline(std::cin, input) || std::cin.eof())
			exit(1);
		if (allowEmpty || input.length() > 0)
			return (input);
		std::cout << "Input cannot be empty." << std::endl;
	}
}

std::string Contact::getFirstName()
{
	return (_firstName);
}

std::string Contact::getLastName()
{
	return (_lastName);
}

std::string Contact::getNickname()
{
	return (_nickName);
}

std::string Contact::getPhoneNumber()
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (_darkestSecret);
}

void Contact::setFirstName(void)
{
	_firstName = validateInput("First name: ");
}
void Contact::setLastName(void)
{
	_lastName = validateInput("Last name: ");
}

void Contact::setNickName(void)
{
	_nickName = validateInput("Nick name: ");
}

void Contact::setPhoneNumber(void)
{
	_phoneNumber = validateInput("Phone number: ");
}

void Contact::setDarkestSecret(void)
{
	_darkestSecret = validateInput("Darkest secret: ");
}

void Contact::printContact()
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}