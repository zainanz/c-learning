/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:22:56 by zali              #+#    #+#             */
/*   Updated: 2025/09/24 12:58:34 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
class Contact
{
	private:
		std::string	fname;
		std::string	lname;
		std::string	nick;
		std::string	num;
		std::string	secret;
	public:
		Contact();
		Contact(std::string fname, std::string lname, std::string nick, std::string num, std::string secret);

		// void	show(void) const;
		
		// Setters
		void	set_fname(const std::string fname);
		void	set_lname(const std::string lname);
		void	set_nick(const std::string nick);
		void	set_num(const std::string num);
		void	set_secret(const std::string secret);

		// Getters
		std::string	get_fname() const;
		std::string	get_lname() const;
		std::string	get_nick() const;
		std::string	get_num() const;
		std::string	get_secret() const;
};
#endif