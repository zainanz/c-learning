/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:18:33 by zali              #+#    #+#             */
/*   Updated: 2025/09/24 15:17:31 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP
# define MAX_CONTACT 5
# include "Contact.hpp" 
# include <sstream>

class PhoneBook
{
	public:
		Contact	contacts[MAX_CONTACT];
		PhoneBook();
		int		get_index(void) const;
		void	inc_index(void);
		void	show_contact(void) const;
		
	private:
		void	field_gen(std::string s) const;
		int		index;
};

#endif