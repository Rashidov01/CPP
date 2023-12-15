/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:43:40 by arashido          #+#    #+#             */
/*   Updated: 2023/12/06 15:43:42 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact		_contacts[8];
		int			_index;
		int			_maxIndex;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		addContact(Contact contact);
		void		searchContact(void);
		void		printContacts(void);
};

#endif