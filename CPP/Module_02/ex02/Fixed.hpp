/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:35:31 by zali              #+#    #+#             */
/*   Updated: 2025/10/12 01:51:40 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const float &num);
		Fixed(const int &num);
		Fixed(const Fixed &copy);
		~Fixed(void);
		int				getRawBits(void) const;
		void			setRawBits(int const val);
		float			toFloat(void) const;
		int				toInt(void)	const;
		Fixed			&operator=(Fixed const &cpy);
		float			operator+(Fixed const &sec);
		float			operator-(Fixed const &sec);
		float			operator*(Fixed const &sec);
		float			operator/(Fixed const &sec);
		int				operator==(Fixed const &obj);
		int				operator==(float n);
		int				operator>(Fixed const &obj);
		int				operator>(float n);
		int				operator>=(Fixed const &obj);
		int				operator>=(float n);
		int				operator<(Fixed const &obj);
		int				operator<(float n);
		int				operator<=(Fixed const &obj);
		int				operator<=(float n);
		int				operator!=(Fixed const &obj);
		int				operator!=(float n);
		Fixed			&operator++(void);
		Fixed			operator++(int dummyVal);
		Fixed			&operator--(void);
		Fixed			operator--(int dummyVal);
		static Fixed const	&min(Fixed const &ob1, Fixed const &ob2);
		static Fixed const	&max(Fixed const &ob1, Fixed const &ob2);

	private:
		int	_value;
		static const int	_frac;
};

std::ostream 	&operator<<(std::ostream &output, Fixed const &ob);
float	 		operator+(float n, Fixed const &ob);
float	 		operator-(float n, Fixed const &ob);
float	 		operator*(float n, Fixed const &ob);
float	 		operator/(float n, Fixed const &ob);
int		 		operator==(float n, Fixed const &ob);
int				operator>(float n, Fixed const &ob);
int				operator>=(float n, Fixed const &ob);
int				operator<(float n, Fixed const &ob);
int				operator<=(float n, Fixed const &ob);
int				operator!=(float n, Fixed const &ob);
#endif