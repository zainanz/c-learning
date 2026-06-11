/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:55:13 by zali              #+#    #+#             */
/*   Updated: 2025/09/28 20:21:23 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void rename(std::string &prev_name, std::string newname){
	prev_name = newname;
	std::cout << "Value\t\t- String REF:\t\t" << &prev_name << "\n";
}
void rename_ptr(std::string *name, std::string newname){
	*name = newname;
	std::cout << "Memory Address\t- String PTR:\t\t" << name << "\n";
}

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "/* Memory Address*/\n";
	std::cout << "Memory Address\t- String Variable:\t" << &string << "\n";
	std::cout << "Memory Address\t- String PTR:\t\t" << stringPTR << "\n";
	std::cout << "Memory Address\t- String REF:\t\t" << &stringREF << "\n";

	std::cout << "\n/* Value */\n";
	/* Value */
	std::cout << "Value\t\t- String Variable:\t" << string << "\n";
	std::cout << "Value\t\t- String PTR:\t\t" << *stringPTR << "\n";
	std::cout << "Value\t\t- String REF:\t\t" << stringREF << "\n";


	// Ref Function
	std::cout << "\n\n>>> STRING= " << stringREF << std::endl; 
	rename(stringREF, "paul");
	std::cout << ">>> AFTER= " << stringREF << std::endl;

	std::cout << "\n\n>>> STRING= " << *stringPTR << std::endl; 
	rename_ptr(stringPTR, "john");
	std::cout << ">>> AFTER= " << *stringPTR << std::endl;

	return (0);
}
