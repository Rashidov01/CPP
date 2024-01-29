/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <arashido@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:46:17 by arashido          #+#    #+#             */
/*   Updated: 2024/01/29 07:12:38 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	printMessage("-----------------------------------------", 90);
	Animal *animal = new Animal();
	printMessage("-----------------------------------------", 90);
	const Animal *dog = new Dog();
	printMessage("-----------------------------------------", 90);
	const Animal *cat = new Cat();
	printMessage("-----------------------------------------", 90);
	printMessage(dog->getType(), 36);
	printMessage("-----------------------------------------", 90);
	printMessage(cat->getType(), 35);
	printMessage("-----------------------------------------", 90);
	cat->makeSound();
	printMessage("-----------------------------------------", 90);
	dog->makeSound();
	printMessage("-----------------------------------------", 90);
	printMessage("-----------------------------------------", 90);
	printMessage("-----------------------------------------", 90);
	printMessage("-----------------------------------------", 90);
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	printMessage("-----------------------------------------", 90);
	const WrongCat *wrongCat1 = new WrongCat();
	printMessage("-----------------------------------------", 90);
	const WrongCat *wrongCat2 = new WrongCat();
	printMessage("-----------------------------------------", 90);
	std::cout << "\033[0;90mWrong Cat1: \033[0m";
	printMessage(wrongCat1->getType(), 35);
	printMessage("-----------------------------------------", 90);
	std::cout << "\033[0;90mWrong Cat2: \033[0m";
	printMessage(wrongCat2->getType(), 35);
	printMessage("-----------------------------------------", 90);
	wrongCat1->makeSound();
	printMessage("-----------------------------------------", 90);
	wrongCat2->makeSound();
	printMessage("-----------------------------------------", 90);
	wrongAnimal->makeSound();
	printMessage("-----------------------------------------", 90);
	delete animal;
	delete cat;
	delete dog;
	delete wrongAnimal;
	delete wrongCat1;
	delete wrongCat2;
	return (0);
}