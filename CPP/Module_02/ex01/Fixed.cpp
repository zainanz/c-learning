/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:50:29 by zali              #+#    #+#             */
/*   Updated: 2025/10/11 01:40:39 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const float &num) : _value(num * (1 << this->_frac))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const int &num) : _value(num * (1 << this->_frac))
{
	std::cout << "Int constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy contructor called\n";
	*this = copy;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const	val)
{
	this->_value = val;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Assignment operator called\n";
	this->_value = copy.getRawBits();	
	return (*this); 
}

std::ostream	&operator<<(std::ostream &output, Fixed const &ob)
{
	output << ob.toFloat();
	return (output);
}

float	Fixed::toFloat(void) const
{
	return (float(this->_value) / (1 << this->_frac));
}

int	Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_frac));
}