/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:49:47 by arashido          #+#    #+#             */
/*   Updated: 2024/01/19 21:24:40 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string ft_replace(const std::string &src, const std::string &s1,
	const std::string &s2)
{
	size_t	current_position;

	std::string result;
	current_position = 0;
	while (current_position < src.length())
	{
		if (src.substr(current_position, s1.length()) == s1)
		{
			result += s2;
			current_position += s1.length();
		}
		else
		{
			result += src[current_position];
			current_position++;
		}
	}
	return (result);
}

int	main(void)
{
	std::string src = "hi there today I am gonna check your code";
	std::string s1 = "I am";
	std::string s2 = "you are";
	std::string result = ft_replace(src, s1, s2);
	std::cout << "Result: " << result << std::endl;
}
