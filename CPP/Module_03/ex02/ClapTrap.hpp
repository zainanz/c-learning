/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:39:10 by zali              #+#    #+#             */
/*   Updated: 2025/10/13 17:54:59 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap	const &copy);
		ClapTrap(void);
		~ClapTrap(void);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		// Setters
		void		setName(std::string const &name);
		void		setEnergy(int n);
		void		setHitpoint(int n);
		void		setDamage(int n);
		// Getters
		std::string	&getName(void);
		int			getEnergy(void);
		int			getHitpoint(void);
		int			getDamage(void);
		ClapTrap	&operator=(ClapTrap const &copy);
	private:
		std::string _name;
		int			_hitpoint;
		int			_energy;
		int			_damage;

};

#endif