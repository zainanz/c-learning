/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:50:29 by zali              #+#    #+#             */
/*   Updated: 2025/10/12 01:57:03 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac = 8;

Fixed::Fixed(void) : _value(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const float &num) : _value(num * (1 << this->_frac))
{
	// Uncomment to show implicit conversion
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed(const int &num) : _value(num * (1 << this->_frac))
{
	// Uncomment to show implicit conversion
	// std::cout << "Int constructor called\n";
}

Fixed::~Fixed(void)
{
	// Uncomment to show implicit conversion
	// std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy contructor called\n";
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
	// std::cout << "Assignment operator called\n";
	this->_value = copy.getRawBits();	
	return (*this); 
}


// Comparison Operators ------------------------------------------

// == Overloading
int		Fixed::operator==(Fixed const &obj)
{
	return (this->toFloat() == obj.toFloat());
}

int		Fixed::operator==(float n)
{
	return (this->toFloat() == n);
}

int	operator==(float n, Fixed const &ob)
{
	return (ob.toFloat() == n);
}


// > Overloading
int		Fixed::operator>(Fixed const &obj)
{
	return (this->toFloat() > obj.toFloat());
}

int		Fixed::operator>(float n)
{
	return (this->toFloat() > n);
}

int		operator>(float n, Fixed const &obj)
{
	return (n > obj.toFloat());
}

// >= Overloading
int		Fixed::operator>=(Fixed const &obj)
{
	return (this->toFloat() >= obj.toFloat());
}

int		Fixed::operator>=(float n)
{
	return (this->toFloat() >= n);
}

int		operator>=(float n, Fixed const &obj)
{
	return (n >= obj.toFloat());
}

// != Overloading
int		Fixed::operator!=(Fixed const &obj)
{
	return (this->toFloat() != obj.toFloat());
}

int		Fixed::operator!=(float n)
{
	return (this->toFloat() != n);
}

int		operator!=(float n, Fixed const &obj)
{
	return (n != obj.toFloat());
}

// < Overloading
int		Fixed::operator<(Fixed const &obj)
{
	return (this->toFloat() < obj.toFloat());
}

int		Fixed::operator<(float n)
{
	return (this->toFloat() < n);
}

int		operator<(float n, Fixed const &obj)
{
	return (n < obj.toFloat());
}


// <= Overloading
int		Fixed::operator<=(Fixed const &obj)
{
	return (this->toFloat() <= obj.toFloat());
}

int		Fixed::operator<=(float n)
{
	return (this->toFloat() <= n);
}

int		operator<=(float n, Fixed const &obj)
{
	return (n <= obj.toFloat());
}


// Arithmetic Operators --------------------------------------------

// + Overloading
float	Fixed::operator+(const Fixed &sec)
{
	return (this->toFloat() + sec.toFloat());
}

float	operator+(float n, Fixed const &ob)
{
	return (ob.toFloat() + n);
}



// - Overloading 
float	Fixed::operator-(const Fixed &sec)
{
	return (this->toFloat() - sec.toFloat());
}

float	operator-(float n, Fixed const &ob)
{
	return (n - ob.toFloat());
}



// * Overloading
float	Fixed::operator*(const Fixed &sec)
{
	return (this->toFloat() * sec.toFloat());
}

float	operator*(float n, Fixed const &ob)
{
	return (n * ob.toFloat());
}


// / Overloading
float	Fixed::operator/(const Fixed &sec)
{
	return (this->toFloat() / sec.toFloat());
}

float	operator/(float n, Fixed const &ob)
{
	return (n / ob.toFloat());
}



// << Overloading
std::ostream	&operator<<(std::ostream &output, Fixed const &ob)
{
	output << ob.toFloat();
	return (output);
}


// Min Max

Fixed const	&Fixed::min(Fixed const &ob1, Fixed const &ob2)
{
	if (ob1.getRawBits() > ob2.getRawBits())
		return (ob2);
	else
		return (ob1);
}

Fixed const	&Fixed::max(Fixed const &ob1, Fixed const &ob2)
{
	if (ob1.getRawBits() < ob2.getRawBits())
		return (ob2);
	else
		return (ob1);
}

// increments and decrements.. ++/--
Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int dummyVal)
{
	(void) dummyVal;
	Fixed temp(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int dummyVal)
{
	(void) dummyVal;
	Fixed temp(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

// Conversions
float	Fixed::toFloat(void) const
{
	return (float(this->_value) / (1 << this->_frac));
}

int	Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_frac));
}