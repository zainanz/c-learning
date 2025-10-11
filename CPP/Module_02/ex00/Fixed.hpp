/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:35:31 by zali              #+#    #+#             */
/*   Updated: 2025/10/08 19:22:43 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		~Fixed(void);
		Fixed	&operator=(const Fixed &cpy);
		int		getRawBits(void)	const;
		void	setRawBits(const int val);
	private:
		int	_value;
		static const int	_frac;
};

#endif