/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:16:13 by zali              #+#    #+#             */
/*   Updated: 2026/08/04 03:38:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a;
	a.whoAmI();
	std::cout << std::endl << std::endl;
	DiamondTrap b(a);
	b.whoAmI();
	return (0);
}