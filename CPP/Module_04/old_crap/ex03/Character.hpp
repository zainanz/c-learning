/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:00:54 by zali              #+#    #+#             */
/*   Updated: 2025/10/19 14:53:09 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP
# define MAX_MAT 4

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{

	private:
		std::string _name;
		AMateria	*Mats[MAX_MAT];
	public:
		Character(std::string const &name);
		Character(Character const &copy);
		~Character();
		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif