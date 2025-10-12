/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:03:56 by zali              #+#    #+#             */
/*   Updated: 2025/10/12 02:02:21 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*	 Goals:
		1. Overloading funcs
		2. Understanding Implicit Conversion
*/

int	main(void)
{
	{
		Fixed a(10);
		Fixed b(3);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "\n\n";
		
		std::cout << "-----------Arithmetic Operations-----------" << std::endl;
		std::cout << "Addition" << std::endl;
		std::cout << "a + b + 6 = " << a + b + 6<< std::endl;
		std::cout << "a + 6 = " << a + 6 << std::endl; // Uncomment in cout in CPP to show implicit conversion
		std::cout << "5 + a + b + 6 = " << 5 + a + b + 6 << std::endl;
		std::cout << "5.0 + a + b + 6 = " << 5.0f + a + b + 6 << std::endl;
		std::cout << "\n\n";

		std::cout << "Subtraction" << std::endl;
		std::cout << "a - b - 6 = " << a - b - 6<< std::endl;
		std::cout << "a - 6 = " << a - 6 << std::endl; // Uncomment in cout in CPP to show implicit conversion
		std::cout << "5 - a - b - 6 = " << 5 - a - b - 6 << std::endl;
		std::cout << "5.0 - a - b - 6 = " << 5.0f - a - b - 6 << std::endl;
		std::cout << "\n\n";
		
		std::cout << "Multiplication" << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "a * b * 2 = " << a * b * 2 << std::endl;
		std::cout << "2 * a * b = " << 2 * a * b << std::endl;
		std::cout << "a * 5.0 = " << a * 5.0f << std::endl; // Uncomment cout in CPP to show implicit conversion
		std::cout << "5 * a = " << 5 * a << std::endl;
		std::cout << "\n\n";
		
		std::cout << "Division" << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
		std::cout << "a / b / 2 = " << a / b / 2 << std::endl;
		std::cout << "2 / a / b = " << 2 / a / b << std::endl;
		std::cout << "a / 5.0 = " << a / 5.0f << std::endl; // Uncomment in cout in CPP to show implicit conversion
		std::cout << "5 / a = " << 5 / a << std::endl;
		std::cout << "\n\n";


		std::cout << "-----------Comparison Operators-----------" << std::endl;
		std::cout << "== Operator" << std::endl;
		std::cout << "a == 10 : " << (a == 10.0 ? "true" : "false") << std::endl; // Why implicit doesnt work here?
		std::cout << "50 == a : " << (50 == a ? "true" : "false") << std::endl;
		std::cout << "a == b : " << (a == b ? "true" : "false") << std::endl; // Why implicit doesnt work here?
		std::cout << "\n\n";


		std::cout << "> Operator" << std::endl;
		std::cout << "a > 11.0 : " << (a > 11.0 ? "true" : "false") << std::endl;
		std::cout << "11 > a : " << (11 > a ? "true" : "false") << std::endl;
		std::cout << "a > b : " << (a > b ? "true" : "false") << std::endl;
		std::cout << "b > a : " << (b > a ? "true" : "false") << std::endl;
		std::cout << "\n\n";

		std::cout << ">= Operator" << std::endl;
		std::cout << "a >= 10.0 : " << (a >= 10.0 ? "true" : "false") << std::endl;
		std::cout << "11 >= a : " << (11 >= a ? "true" : "false") << std::endl;
		std::cout << "a >= b : " << (a >= b ? "true" : "false") << std::endl;
		std::cout << "b >= a : " << (b >= a ? "true" : "false") << std::endl;
		std::cout << "\n\n";


		std::cout << "< Operator" << std::endl;
		std::cout << "a < 11.0 : " << (a < 11.0 ? "true" : "false") << std::endl;
		std::cout << "11 < a : " << (11 < a ? "true" : "false") << std::endl;
		std::cout << "a < b : " << (a < b ? "true" : "false") << std::endl;
		std::cout << "b < a : " << (b < a ? "true" : "false") << std::endl;
		std::cout << "\n\n";


		std::cout << "<= Operator" << std::endl;
		std::cout << "a <= 10.0 : " << (a <= 10.0 ? "true" : "false") << std::endl;
		std::cout << "11 <= a : " << (11 <= a ? "true" : "false") << std::endl;
		std::cout << "a <= b : " << (a <= b ? "true" : "false") << std::endl;
		std::cout << "b <= a : " << (b <= a ? "true" : "false") << std::endl;
		std::cout << "\n\n";
		
		
		std::cout << "!= Operator" << std::endl;
		std::cout << "a != 10.0 : " << (a != 10.0 ? "true" : "false") << std::endl;
		std::cout << "11 != a : " << (11 != a ? "true" : "false") << std::endl;
		std::cout << "a != b : " << (a != b ? "true" : "false") << std::endl;
		std::cout << "b != a : " << (b != a ? "true" : "false") << std::endl;
		std::cout << "\n\n";

		std::cout << "-------------STATIC MIN MAX----------\n";
		std::cout << "FIXED::min(a,b) --> " << Fixed::min(a,b) << std::endl;
		std::cout << "FIXED::max(a,b) --> " << Fixed::max(a,b) << std::endl;
		std::cout << "\n\n";

		std::cout << "--------- INCREMENTS / DECREMENTS (++/--)--------------\n";
		std::cout << "a = " << a << std::endl;
		std::cout << "a++; returned " << a++ << "; updated to " << a << std::endl;
		std::cout << "++a; returned " << ++a << "; updated to " << a << std::endl;
		std::cout << "--a; returned " << --a << "; updated to " << a << std::endl;
		std::cout << "a--; returned " << a-- << "; updated to " << a << std::endl;
	}
	{
		std::cout << "----------------- 42 SUBJECT.PDF TEST ---------------------\n";
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	return (0);
}