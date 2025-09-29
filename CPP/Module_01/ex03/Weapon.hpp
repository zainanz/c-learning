/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:30:01 by zali              #+#    #+#             */
/*   Updated: 2025/09/29 16:28:57 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
class Weapon
{
	public:
	Weapon(std::string type);
	const std::string	&getType(void);
	void				setType(std::string type);
	private:
	std::string 		_type;
};
#endif