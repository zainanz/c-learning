/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:02:07 by zali              #+#    #+#             */
/*   Updated: 2026/08/02 03:09:55 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(const ScavTrap& copy);
		ScavTrap&	operator=(const ScavTrap& other);
		//Asked in Subject.pdf
		ScavTrap(const std::string &name);

		void		guardGate(void);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};