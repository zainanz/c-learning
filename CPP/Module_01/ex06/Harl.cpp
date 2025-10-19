/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:56:11 by zali              #+#    #+#             */
/*   Updated: 2025/10/04 12:35:02 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
Harl::Harl(void){};
void	Harl::debug(void) {
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
		"ketchup burger. I really do!\n";
}

void	Harl::warning(void){
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for"
		"years, whereas you started working here just last month.\n";
}

void	Harl::info(void){
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put"
		"enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::error(void){
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level){
	void	(Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++){
		if (levels[i] == level)
		{
			(this->*func[i])();
			if (i + 1 < 4)
				level = levels[i + 1];
		}
	}
}