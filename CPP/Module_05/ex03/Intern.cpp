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

static AForm* createForm(FORM_TYPE formtype, const std::string& tname){
	switch (formtype)
	{
		case ROBOT: return (new RobotomyRequestForm(tname));
		case SHRUBBERY: return (new ShrubberyCreationForm(tname));
		case PRESIDENTIAL: return (new PresidentialPardonForm(tname));
		default: NULL;
	}
	return (NULL);
}

AForm*	Intern::makeForm(const std::string& fname, const std::string& tname){
	const int MAX_FORMS = 3;
	const std::string forms[MAX_FORMS] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	AForm*	aptr = NULL;
	for (int i = 0; i < MAX_FORMS; i++){
		if (forms[i] == fname){
			aptr = createForm(static_cast<FORM_TYPE>(i), tname);
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