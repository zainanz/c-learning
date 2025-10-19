/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:49:25 by zali              #+#    #+#             */
/*   Updated: 2025/10/18 22:15:19 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

/* 
	Virtual and Override
*/

int	main(void)
{
	// Leak Check
	{
		int	totalAnimals = 15;
		Animal *Animals[totalAnimals];
		for (int i = 0; i < totalAnimals; i++)
		{
			if (i % 2)
				Animals[i] = new Dog();
			else
				Animals[i] = new Cat();
		}
		std::cout << "--------------------------------------\n";
		Animals[3]->getBrain().setIdea("Hungry, fooood.\n", 0);
		Animals[3]->getBrain().setIdea("Woooof, fooood.\n", 1);
		std::cout << Animals[3]->getBrain().getIdea(0);
		std::cout << Animals[3]->getBrain().getIdea(1);
		std::cout << "--------------------------------------\n";
		for (int i = 0; i < totalAnimals; i++)
			delete Animals[i];
	}
		std::cout << "\n\n\n\n";
	{
		Dog dogA = Dog();
		std::cout << " ---------- COPY TEST ---------\n";
		dogA.getBrain().setIdea("Want to play ball..", 0);
		dogA.getBrain().setIdea("I am hungryyyyyyyy..", 1);
		Dog dogB = Dog(dogA);
		std::cout << "dogA: " << dogA.getBrain().getIdea(0) << "\n";
		std::cout << "dogA: " << dogA.getBrain().getIdea(1) << "\n";
		dogB.getBrain().setIdea("Helllooooo!", 2);
		std::cout << "dogB: " << dogB.getBrain().getIdea(0) << "\n";
		std::cout << "dogB: " << dogB.getBrain().getIdea(1) << "\n";
		std::cout << "dogB: " << dogB.getBrain().getIdea(2) << "\n";
		dogA = dogB;
		std::cout << "dogA: " << dogA.getBrain().getIdea(0) << "\n";
		std::cout << "dogA: " << dogA.getBrain().getIdea(1) << "\n";
		std::cout << "dogA: " << dogA.getBrain().getIdea(2) << "\n";
		std::cout << "dogA: " << &dogA << ", dogA Brain: " << &dogA.getBrain() << ", dogA type: "  << &dogA.getType() << "\n";
		std::cout << "dogB: " << &dogB << ", dogB Brain: " << &dogB.getBrain() << ", dogB type: "  << &dogB.getType() << "\n";
		std::cout << " ----------            ---------\n";
		
	}
		std::cout << "\n\n\n\n";
	{
		Dog catA = Dog();
		std::cout << " ---------- COPY TEST ---------\n";
		catA.getBrain().setIdea("Want to play ball..", 0);
		catA.getBrain().setIdea("I am hungryyyyyyyy..", 1);
		Dog catB = Dog(catA);
		std::cout << "catA: " << catA.getBrain().getIdea(0) << "\n";
		std::cout << "catA: " << catA.getBrain().getIdea(1) << "\n";
		catB.getBrain().setIdea("Helllooooo!", 2);
		std::cout << "catB: " << catB.getBrain().getIdea(0) << "\n";
		std::cout << "catB: " << catB.getBrain().getIdea(1) << "\n";
		std::cout << "catB: " << catB.getBrain().getIdea(2) << "\n";
		catA = catB;
		std::cout << "catA: " << catA.getBrain().getIdea(0) << "\n";
		std::cout << "catA: " << catA.getBrain().getIdea(1) << "\n";
		std::cout << "catA: " << catA.getBrain().getIdea(2) << "\n";
		std::cout << "catA: " << &catA << ", catA Brain: " << &catA.getBrain() << ", catA type: "  << &catA.getType() << "\n";
		std::cout << "catB: " << &catB << ", catB Brain: " << &catB.getBrain() << ", catB type: "  << &catB.getType() << "\n";
		std::cout << " ----------            ---------\n";
		
	}
		std::cout << "\n\n\n\n";
	return (0);
}