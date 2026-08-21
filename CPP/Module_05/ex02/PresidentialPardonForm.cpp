#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", P_GRAD_REQ_SIG, P_GRAD_REQ_EXEC), target_("Presidential_Default"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", P_GRAD_REQ_SIG, P_GRAD_REQ_EXEC), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target_(other.target_){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this == &other) return (*this);
	this->AForm::operator=(other);
	this->target_ = other.target_;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	this->AForm::execute(executor);
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char* PresidentialPardonForm::RobomotizeFailedException::what() const _GLIBCXX_NOTHROW{
	return "[RobotomizeFailedExeption] Failed to robotomized.";
}