/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 01:52:05 by zali              #+#    #+#             */
/*   Updated: 2026/08/03 02:59:58 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(const FragTrap& other);
		FragTrap(const std::string& name);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap(void);

		void	highFivesGuys(void);
};