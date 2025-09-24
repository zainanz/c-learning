/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:26:42 by zali              #+#    #+#             */
/*   Updated: 2025/09/24 15:53:07 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(): fname(""), lname(""), nick(""), num(""), secret("") {};

Contact::Contact(std::string fname, std::string lname, std::string nick, std::string num, std::string secret)
	: fname(fname), lname(lname), nick(nick), num(num), secret(secret) {};

void		Contact::set_fname(const std::string fname) { this->fname = fname; }
void		Contact::set_lname(const std::string lname) { this->lname = lname; }
void		Contact::set_nick(const std::string nick) { this->nick = nick; }
void		Contact::set_num(const std::string num) { this->num = num; }
void		Contact::set_secret(const std::string secret) { this->secret = secret; }

std::string	Contact::get_lname() const { return this->lname; }
std::string	Contact::get_fname() const { return this->fname; }
std::string	Contact::get_nick() const { return this->nick; }
std::string	Contact::get_num() const { return this->num; }
std::string	Contact::get_secret() const { return this->secret; }