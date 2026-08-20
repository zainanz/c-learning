#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", GRAD_REQ_SIG, GRAD_REQ_EXEC), target_("Shrubbery_Default_Form"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", GRAD_REQ_SIG, GRAD_REQ_EXEC), target_(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target_("tree"){
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this == &other) return (*this);
	this->AForm::operator=(other);
	this->target_ = other.target_;
	return (*this);
}
