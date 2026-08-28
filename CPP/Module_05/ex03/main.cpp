#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{	
	Intern zali;
	Bureaucrat z("Zainan", 1);

	std::cout << " ============= Shrubbery ============" << std::endl;
	AForm* form1 = zali.makeForm("shrubbery creation", "priv");
	form1->beSigned(z);
	form1->execute(z);
	z.signForm(*form1);
	z.executeForm(*form1);

	std::cout << " ============= Presidential ============" << std::endl;
	AForm* form2 = zali.makeForm("presidential pardon", "pres_priv");
	form2->beSigned(z);
	form2->execute(z);
	z.signForm(*form2);
	z.executeForm(*form2);

	std::cout << " ============= Robotomy ============" << std::endl;
	AForm* form3 = zali.makeForm("robotomy request", "pres_priv");
	form3->beSigned(z);
	try {
		form3->execute(z);
	}
	catch (std::exception& e){
		std::cerr << "[**Exception] " << e.what() << std::endl;
	}
	z.signForm(*form3);
	z.executeForm(*form3);

	std::cout << " ============= Invalid ============" << std::endl;
	try {
		zali.makeForm("hello world", "hi");
	}
	catch (std::exception& e){
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	delete form1;
	delete form2;
	delete form3;
	return 0;
}