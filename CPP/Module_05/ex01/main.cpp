#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
int main(void)
{
	std::cout << "============= Bureaucrat Tests =================" << std::endl;
	Bureaucrat b("Zainan", 2);
	try {
		b.gradeUp();
		std::cout << b << std::endl;
		b.gradeUp();
		std::cout << b << std::endl;
		b.gradeUp();
		std::cout << b << std::endl;
		b.gradeUp();
		std::cout << b << std::endl;
	}
	catch (std::exception& e){
		std::cerr << "[Exception] " << e.what() << std::endl; 
	}
	Bureaucrat copy_b(b);
	std::cout << "~~~~~~~~~~~ B ~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << ">> " << b << std::endl;
	std::cout << "~~~~~~~~~~~ Copy B ~~~~~~~~~~~~~~~~~~~" << std::endl;
	#define SIGNREQ 42
	int i;
	for (i = 0; i < SIGNREQ; i++) copy_b.gradeDown();
	for (i = 0; i < __INT_MAX__; i++){
		try {
			b.gradeDown();
		}
		catch (std::exception& e){
			std::cout << "[Exception] Exception Caught Values:\ti='" << i << "' Grade='" << b.getGrade() << "'\n\t\t\t\t\te.what(): " << e.what() << std::endl;
			break ;
		}
	}
	std::cout << copy_b << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "============= Testing Form Constructors =================" << std::endl;
	Form f("Friendship", SIGNREQ, SIGNREQ);
	Form f2(f);
	Form f3;
	std::cout << f << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	try {
		Form ff("NAME", -1, 150);
	}
	catch (std::exception& e){
		std::cout << "[Exception] " << e.what() << std::endl;
	}

	try {
		Form ff("NAME", 2, 170);
	}
	catch (std::exception& e){
		std::cout << "[Exception] " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	std::cout << "============= Bureaucrat::signForm =================" << std::endl;
	copy_b.signForm(f);
	std::cout << f << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "============= Form::beSigned =================" << std::endl;
	for (;i > 0; i--) b.gradeUp();
	f.beSigned(b);
	std::cout << f << std::endl;


	return 0;
}