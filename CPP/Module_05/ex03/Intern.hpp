#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum FORM_TYPE{
	ROBOT,
	SHRUBBERY,
	PRESIDENTIAL
};

class Intern{
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& other);

		AForm*	makeForm(const std::string& fname, const std::string& tname);

		class InvalidFormException: public std::exception {
			const char* what() const _GLIBCXX_NOTHROW;
		};
};