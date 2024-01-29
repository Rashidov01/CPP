/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:26:07 by arashido          #+#    #+#             */
/*   Updated: 2024/01/29 07:15:51 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal *i = new Dog();
    const Animal *j = new Cat();
    delete j;
    delete i;

	printMessage("---------------------------------------------", 90);
	printMessage("---------------------------------------------", 90);

    int size = 10;
    Animal *animals[size];
    for (int index = 0; index < size; index++)
    {
        if (index % 2 == 0)
            animals[index] = new Dog();
        else
            animals[index] = new Cat();
    }
	printMessage("---------------------------------------------", 90);
	printMessage("---------------------------------------------", 90);

    for (int index = size - 1; index >= 0; index--)
	{
        delete animals[index];
	}

	printMessage("---------------------------------------------", 90);
	printMessage("---------------------------------------------", 90);

    Dog tmp;
    {
        Dog basic = tmp;
    }
	return 0;
}
