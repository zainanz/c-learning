/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 00:10:06 by zali              #+#    #+#             */
/*   Updated: 2026/08/01 00:46:32 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed(void): raw_val(0){
	std::cout << "Default constructor called" << std::endl;
} 

Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy Constructor was called." << std::endl;
	*this = copy;
}

Fixed::Fixed(const int val): raw_val(val * (1 << this->frac)){
	std::cout << "Int Constructor called!" << std::endl;
}

Fixed::Fixed(const float val): raw_val(roundf(val * static_cast<float>(1 << this->frac))){
	std::cout << "Float Constructor called!" << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called!" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits() member function was called!" << std::endl;
	return (this->raw_val);
}

void	Fixed::setRawBits(const int val){
	std::cout << "setRawBits() member function was called!" << std::endl;
	this->raw_val = val;
}

Fixed& Fixed::operator=(const Fixed& copy){
	std::cout << "Assignment operator called" << std::endl;
	if (this != &copy) this->raw_val = copy.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const{
	return (this->raw_val / static_cast<float>(1 << this->frac));
}
int	Fixed::toInt(void) const {
	return (this->raw_val >> this->frac);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return (os);
}