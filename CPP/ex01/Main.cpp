/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:26:03 by zali              #+#    #+#             */
/*   Updated: 2025/09/24 17:00:00 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Contact.cpp"
#include "PhoneBook.hpp"
#include "PhoneBook.cpp"

int	reset_invalid(Contact &c)
{
	int invalid = 0;
	if (!c.get_fname().size() || !c.get_lname().size() || !c.get_nick().size() || !c.get_num().size() || !c.get_secret().size())
		invalid = 1;
	if (invalid)
	{
		c.set_fname("");
		c.set_lname("");
		c.set_nick("");
		c.set_num("");
		c.set_secret("");
		return (1);
	}
	return (0);
}

void	get_data(std::string &prompt, PhoneBook &pBook)
{
	Contact &c = pBook.contacts[pBook.get_index()];
	std::cout << "First Name:";
	std::getline(std::cin, prompt);
	c.set_fname(prompt);
	std::cout << "Last Name:";
	std::getline(std::cin, prompt);
	c.set_lname(prompt);
	std::cout << "Nick Name:";
	std::getline(std::cin, prompt);
	c.set_nick(prompt);
	std::cout << "Phone Number:";
	std::getline(std::cin, prompt);
	c.set_num(prompt);
	std::cout << "Secret:";
	std::getline(std::cin, prompt);
	c.set_secret(prompt);
	std::cout << "\x1B[2J\x1B[H" << std::flush;
	std::cout << "CMD: \"ADD\", \"SEARCH\" and \"EXIT\"\n";
	if (reset_invalid(c))
		std::cout << "[ERROR] Field cant be empty.\n";
	else
	{
		std::cout << "[INFO] Phonebook updated.\n";
		pBook.inc_index();
	}
}

void	search_index(PhoneBook &pBook, std::string &prompt)
{
	int val = 0;

	pBook.show_contact();
	std::cout << "Choose an index to see more details.\n[0 to exit.]\n";
	while (1)
	{
		std::cout << "[SEARCH]: "; 
		std::getline(std::cin, prompt);
		std::istringstream iss(prompt);
		iss >> val;
		if (val == 0)
			break ;
		if (val < MAX_CONTACT + 1 && val > 0)
		{
			std::cout << "\x1B[2J\x1B[H" << std::flush;
			pBook.show_contact();
			std::cout << "-------------------------------\n";
			std::cout << "\tContact Info N." << val << "\n";
			val--;
			std::cout << "First Name:\t" << pBook.contacts[val].get_fname() << "\n";
			std::cout << "Last Name:\t" << pBook.contacts[val].get_lname() << "\n";
			std::cout << "Nick:\t\t" << pBook.contacts[val].get_nick() << "\n";
			std::cout << "Phone Number:\t" << pBook.contacts[val].get_num() << "\n";
			std::cout << "Secret:\t\t" << pBook.contacts[val].get_secret() << "\n";
			std::cout << "-------------------------------\n";
			std::cout << "[INFO] Valid Index is \033[33m1-" <<  MAX_CONTACT << "\033[0m or \033[33m0\033[0m to exit." << "\n";
		}
		else
		{
			std::cout << "\x1B[2J\x1B[H" << std::flush;
			pBook.show_contact();
			std::cout << "[ERROR] Invalid index.\n";
			std::cout << "[INFO] Valid Index is \033[33m1-" <<  MAX_CONTACT << "\033[0m or \033[33m0\033[0m to exit." << "\n";
		}
	}
}

int	main(void)
{
	std::string	prompt = "";
	PhoneBook	pBook;

	std::cout << "CMD: \"ADD\", \"SEARCH\" and \"EXIT\"\n";
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
		{
			get_data(prompt, pBook);
			continue ;
		}
		else if (prompt == "SEARCH")
			search_index(pBook, prompt);
		else if (prompt == "EXIT")
			break ;
		std::cout << "\x1B[2J\x1B[H" << std::flush;
		std::cout << "CMD: \"ADD\", \"SEARCH\" and \"EXIT\"\n";
	}
	// Contact c("zainan", "ali", "zali", "920433306", "eats alot");
	// Contact d();
	// c.show();
	return (0);
}