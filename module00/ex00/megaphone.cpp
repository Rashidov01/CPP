/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:35:59 by arashido          #+#    #+#             */
/*   Updated: 2023/12/13 18:02:58 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; ++i)
	{
		std::string word = av[i];
		for (size_t j = 0; j < word.length(); ++j)
		{
			if (std::islower(word[j]))
				word[j] = std::toupper(word[j]);
		}
		std::cout << word;
	}
	std::cout << std::endl;
	return (0);
}