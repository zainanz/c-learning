/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:48:28 by zali              #+#    #+#             */
/*   Updated: 2025/10/19 13:52:20 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP

# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		AMateria	*clone() const;
		void		use(ICharacter &target);
		std::string	getType() const;
};
#endif