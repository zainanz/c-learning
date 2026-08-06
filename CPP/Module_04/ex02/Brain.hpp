/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 07:24:13 by zali              #+#    #+#             */
/*   Updated: 2026/08/06 08:42:41 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#include <iostream>
#define MAX_IDEAS 100

class Brain{
	public:
		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain&	operator=(const Brain& copy);
		void	addIdea(const std::string& idea);	
		std::string ideas[MAX_IDEAS]; 
		int			ideaIDX;
};