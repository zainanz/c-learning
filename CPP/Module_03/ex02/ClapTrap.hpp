/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:39:10 by zali              #+#    #+#             */
/*   Updated: 2026/08/03 02:15:21 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class ClapTrap
{
	public:
		//Canonical Stuff
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(const ClapTrap& copy);
		ClapTrap&	operator=(const ClapTrap& other);
		//Asked in Subject.pdf
		ClapTrap(const std::string &name);
	
		void				attack(std::string const &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		// Setters
		void				setName(std::string const &name);
		void				setEnergy(int n);
		void				setHitpoint(int n);
		void				setDamage(int n);
		// Getters
		const std::string	&getName(void) const;
		int					getEnergy(void) const;
		int					getHitpoint(void) const;
		int					getDamage(void) const;
	private:
		std::string name_;
		int			hitpoint_;
		int			energy_;
		int			damage_;

};