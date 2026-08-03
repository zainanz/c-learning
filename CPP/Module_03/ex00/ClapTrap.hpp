/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:39:10 by zali              #+#    #+#             */
/*   Updated: 2025/10/13 18:41:35 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
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
		const std::string	&getName(void)	const;
		int					getEnergy(void);
		int					getHitpoint(void);
		int					getDamage(void);
	private:
		std::string name_;
		int			hitpoint_;
		int			energy_;
		int			damage_;

};

#endif