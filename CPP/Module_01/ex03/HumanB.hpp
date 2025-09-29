/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:20:17 by zali              #+#    #+#             */
/*   Updated: 2025/09/29 16:35:05 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &type);
		void	setWeapon(Weapon &weap);
		void	attack(void);
	private:
		Weapon		*_weapon;
		std::string	_name;
};
#endif