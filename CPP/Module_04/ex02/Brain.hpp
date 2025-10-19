/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:35:02 by zali              #+#    #+#             */
/*   Updated: 2025/10/19 16:00:17 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
	Brain();
	~Brain();
	Brain(Brain const &copy);
	Brain	&operator=(Brain const &copy);
	void	setIdea(std::string const &idea, int const index);
	std::string &getIdea(int const index);
	private:
		std::string _ideas[100];
	
};

#endif