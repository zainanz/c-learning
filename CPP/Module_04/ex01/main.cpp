/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:09:14 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 09:08:40 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int main(void)
{
	const Animal* c = new Cat();
	delete c;

	Dog d;
	Dog d2(d);

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Dog dog = *((Dog *)(j));
	delete j;
	delete i;

	std::cout << std::endl << std::endl;
	std::cout << "======== ADD IDEAS : DOG===========" << std::endl;
	dog.addIdea("I am a dog!");
	dog.addIdea("I am a not a cat!");
	std::cout << "======== ADD IDEAS END : DOG===========" << std::endl;
	std::cout << std::endl << std::endl;

	Dog k = dog;
	k.setIdea("hello?", 0);
	std::cout << std::endl << std::endl;
	std::cout << "======== GET IDEAS : DOG ===========" << std::endl;
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << dog.getIdea(1) << std::endl;
	std::cout << "======== GET IDEAS END : DOG ===========" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "======== GET IDEAS : K ===========" << std::endl;
	std::cout << k.getIdea(0) << std::endl;
	std::cout << k.getIdea(1) << std::endl;
	std::cout << "======== GET IDEAS END : K ===========" << std::endl;
	std::cout << std::endl << std::endl;
	
	return 0;
}