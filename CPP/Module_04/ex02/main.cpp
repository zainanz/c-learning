/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 05:09:14 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 10:19:06 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int main(void)
{
	    // PREVIOUS  EXERCISE
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
	std::cout << std::endl << std::endl;
	{
		Dog tmp = k;
	}
	std::cout << k.getIdea(0) << std::endl;
	std::cout << std::endl << std::endl;

	// Main thing asked in Subject.pdf
	#define MAX_ANIMALS 100
	const Animal*	aptr[MAX_ANIMALS];
	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		if (i % 2)
			aptr[i] = new Dog();
		else
			aptr[i] = new Cat();

	}
	for (int i = 0; i < MAX_ANIMALS; i++){
		delete aptr[i];
	}
	#undef MAX_ANIMALS

	
	return 0;
}