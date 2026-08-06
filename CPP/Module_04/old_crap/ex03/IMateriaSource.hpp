/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:38:24 by zali              #+#    #+#             */
/*   Updated: 2025/10/19 13:28:50 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIALSOURCE_HPP
# define IMATERIASOURCE_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp" 
# include <iostream>
class IMateriaSource
{
	public:
		virtual	~IMateriaSource();
		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};
#endif