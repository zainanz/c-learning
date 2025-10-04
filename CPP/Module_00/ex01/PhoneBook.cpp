/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:29:41 by zali              #+#    #+#             */
/*   Updated: 2025/09/24 15:49:52 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {};

int		PhoneBook::get_index(void) const {
	return (this->index);
}

void	PhoneBook::inc_index(void) {
	if (this->index + 1 == MAX_CONTACT)
		this->index = 0;
	else
		this->index++;
}

void	PhoneBook::field_gen(std::string s) const {
	const int	FIELD_SIZE = 10;
	const int	s_size = s.size();
	int			spaces = FIELD_SIZE - s_size; 
	int 		i;
	for (i = 0; spaces - i > 0; i++)
		std::cout << " ";
	for (i = 0;i < s_size; i++)
	{
		if (i == FIELD_SIZE - 1 && s_size > FIELD_SIZE)
			std::cout << ".";
		else
			std::cout << s[i];
	}
	std::cout << "|";
}

void	PhoneBook::show_contact(void) const {
	
	std::cout << "|";
	this->field_gen("Index");
	this->field_gen("First Name");
	this->field_gen("Last Name");
	this->field_gen("Nick");
	std::cout << "\n";
	for (int i = 0;i < MAX_CONTACT; i++)
	{
		std::cout << "|";
    	std::ostringstream oss;
		oss << i + 1;
		this->field_gen(oss.str());
		this->field_gen(this->contacts[i].get_fname());
		this->field_gen(this->contacts[i].get_lname());
		this->field_gen(this->contacts[i].get_nick());
		std::cout << "\n";
	}
}