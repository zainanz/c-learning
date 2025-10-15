/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:00:22 by zali              #+#    #+#             */
/*   Updated: 2025/10/13 20:56:06 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP 
# define FRAGTRAP_HPP 

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap 
{
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &copy);
		~FragTrap(void);
		FragTrap	&operator=(FragTrap const &copy);
		void		highFivesGuys(void);
};
#endif