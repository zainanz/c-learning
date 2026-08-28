#include "Bureaucrat.hpp"
#include <iostream>
int main(void)
{
	Bureaucrat b("Zainan");
	Bureaucrat a(b);
	Bureaucrat zali;
	zali = b;
	std::cout << "Bureaucrat zali -> " << zali  << std::endl;

	try
	{
		Bureaucrat c("zali", -1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;

	try{
		a.gradeUp();
		a.gradeDown();
		a.gradeDown();
	}
	catch(std::exception& e)
	{
		std::cerr << a << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;

	return 0;
}