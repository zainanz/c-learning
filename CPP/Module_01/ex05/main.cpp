/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 09:08:01 by zali              #+#    #+#             */
/*   Updated: 2025/10/04 12:34:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl karen;

	karen.complain("ERROR");
	std::cout << "\n\n\n\n";
	karen.complain("WARNING");
	std::cout << "\n\n\n\n";
	karen.complain("DEBUG");
	std::cout << "\n\n\n\n";
	karen.complain("INFO");
	std::cout << "\n\n\n\n";
	karen.complain("HAHA!");
}