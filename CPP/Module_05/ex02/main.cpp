#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	ShrubberyCreationForm a;
	Bureaucrat b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	#define MAX_GRAD 50
	for (int i = 0; i < 50; i++) b.gradeUp();
	ShrubberyCreationForm zb("Important Form");
	std::cout << zb << std::endl << b << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try {
		zb.beSigned(b);
		std::cout << zb.getName() << " was signed by " << b.getName() << std::endl;
		std::cout << zb << std::endl;
	}
	catch(std::exception& e){
		std::cerr << "[Error] " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm ca = zb;
	std::cout << ca << std::endl;
}