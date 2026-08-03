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
#include <cmath>

class Fixed {
    public:
        Fixed(void);
        Fixed(const Fixed& copy);
		Fixed(const float val);
		Fixed(const int val);
        ~Fixed();

        Fixed&	operator=(const Fixed& copy);

		//Arithmetics
		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator/(const Fixed& other);
		Fixed	operator*(const Fixed& other);

		// Pre-Increment, Post-Increment, Pre-Decrement, Post-Decrement
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		// Comparison Operator
		bool	operator!=(const Fixed& other);
		bool	operator==(const Fixed& other);
		bool	operator>=(const Fixed& other);
		bool	operator<=(const Fixed& other);
		bool	operator>(const Fixed& other);
		bool	operator<(const Fixed& other);
	
		int		getRawBits(void) const;
		void	setRawBits(const int val);
		float	toFloat(void) const;
		int		toInt(void) const;

		const static Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&	min(Fixed& f1, Fixed& f2);
		const static Fixed&	max(const Fixed& f1, const Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
	
    private:
        static const int	frac;
        int					raw_val;
};
std::ostream&	operator<<(std::ostream& os, const Fixed& f);