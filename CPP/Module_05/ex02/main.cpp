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

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	ShrubberyCreationForm unsignedform("mytree");

	std::cout << "UnsignedForm has been created!" << std::endl;
	std::cout << unsignedform << std::endl;

	std::cout << "b attempted to execute the unsigned form!" << std::endl;
	try {
		unsignedform.execute(b);
	}
	catch (std::exception& e){
		std::cerr << "[Error] " << e.what() << std::endl;
	}

	unsignedform.beSigned(b);
	std::cout << unsignedform.getName() << " has been signed by " << b.getName() << std::endl;
	std::cout << std::endl;
	

	ShrubberyCreationForm signedform(unsignedform);
	std::cout << signedform.getName() << "'s copy has been printed!" << std::endl;

	std::cout << signedform << std::endl;

	for (int i = 0; i < MAX_GRAD ; i++) {
		try {
			b.gradeDown();
		}
		catch (...) {
			break ;
		}
	}
	std::cout << "B's grade set to 150!" << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl;
	std::cout << "B attempted to perform execute" << std::endl;

	try {
		signedform.execute(b);
	}
	catch (std::exception& e)
	{
		std::cerr << "[Error] " << e.what() << std::endl;
	}
	for (int i = 0 ; i < MAX_GRAD; i++) {
		try
		{
			b.gradeUp();
		}
		catch(...)
		{
			break;
		}
	}
	std::cout << "b's grade was set to 1!" << std::endl;
	std::cout << b << std::endl;

	try {
		signedform.execute(b);
	}
	catch (std::exception& e){
		std::cerr << "[Error] " << e.what() << std::endl;
	}
}