/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 23:59:27 by zali              #+#    #+#             */
/*   Updated: 2026/08/01 00:47:15 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
    public:
        Fixed(void);
        Fixed(const Fixed& copy);
        ~Fixed();

        Fixed&	operator=(const Fixed& copy);
		int		getRawBits(void) const;
		void	setRawBits(const int val);

    private:
        static const int	frac;
        int					raw_val;
};