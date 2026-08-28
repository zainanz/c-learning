#include "Intern.hpp"
Intern::Intern(){
}
Intern::~Intern(){

}
Intern::Intern(const Intern& copy){
	*this = copy;
}
Intern&	Intern::operator=(const Intern& other){
	if (this == &other) return (*this);
	return (*this);
}

static AForm*	createRobotomy(const std::string& tname){
	return (new RobotomyRequestForm(tname));
}
static AForm*	createShrubbery(const std::string& tname){
	return (new ShrubberyCreationForm(tname));
}
static AForm*	createPresidential(const std::string& tname){
	return (new PresidentialPardonForm(tname));
}

AForm*	Intern::makeForm(const std::string& fname, const std::string& tname){
	const int MAX_FORMS = 3;
	AForm * (*funcs[MAX_FORMS])(const std::string& ) = {createRobotomy, createShrubbery, createPresidential};
	const std::string forms[MAX_FORMS] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	AForm*	aptr = NULL;
	for (int i = 0; i < MAX_FORMS; i++){
		if (forms[i] == fname){
			aptr = (funcs[i])(tname);
			std::cout << "Intern creates " << forms[i]  << "."  << std::endl;
			break ;
		}
	}
	if (!aptr) throw InvalidFormException();
	return (aptr);
}

const char*	Intern::InvalidFormException::what() const _GLIBCXX_NOTHROW{
	return "[InvalidFormException] Invalid Form";
}