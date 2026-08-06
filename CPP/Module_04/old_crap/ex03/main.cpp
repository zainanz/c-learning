/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:22:28 by zali              #+#    #+#             */
/*   Updated: 2025/10/19 15:29:21 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main(void)
{
	{
		IMateriaSource* src = new MateriaSource();
		AMateria *ptr = new Cure();
		src->learnMateria(ptr);
		delete ptr;
		ptr = new Ice();
		src->learnMateria(ptr);
		delete ptr;
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;
		
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "\n\n\n\n";
	{
		ICharacter *zainan = new Character("zainan");
		// ICharacter *zainanclone = new Character(*zainan); -> Doesnt work because zainan is Character class
		AMateria *MatArr[10];
		AMateria *matPtr;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
				matPtr = new Cure();
			else
				matPtr = new Ice();
			zainan->equip(matPtr);
			MatArr[i] = matPtr;
		}
		for (int i = 0; i < 10;i++)
		{
			zainan->use(i, *zainan);
			zainan->unequip(i);
			delete MatArr[i];
		}
		delete zainan;
	}
	std::cout << "\n\n\n\n";
	{
		Character *zainan = new Character("zainan"); 
		std::cout << zainan->getName() <<  " started a new a Materia Factory.\n";
		MateriaSource *factory = new MateriaSource();
		AMateria *icePtr = new Ice();
		AMateria *curePtr = new Cure(); 
		std::cout << zainan->getName() <<  "'s factory learned from the prototype of 'Ice' and 'Cure'.\n";
		for (int i = 0; i < 20 ; i++)
		{
			if (i % 2)
				factory->learnMateria(icePtr);
			else
				factory->learnMateria(curePtr);
		}	
		delete icePtr;
		delete curePtr;
		for (int i = 0  ; i < 30 ; i++)
		{
			icePtr = factory->createMateria("ice");
			if (icePtr)
				std::cout << "Just created a new 'Ice' Materia\n";
			curePtr = factory->createMateria("cure");
			if (curePtr)
				std::cout << "Just created a new 'Cure' Materia\n";
			delete icePtr;
			delete curePtr;
		}
		AMateria *matPtr = factory->createMateria("Iron");
		if (!matPtr)
			std::cout << "failed to create 'Iron', never studied the prototype.\n";
		std::cout << zainan->getName() <<  "'s factory produced a lot of 'Ice' and 'Cure' Materia.\n";
		delete zainan;
		delete factory;
		std::cout << "Cleared and Removed.\n";
	}
}