#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", R_GRAD_REQ_SIG, R_GRAD_REQ_EXEC), target_("Robotomy_Default"){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", R_GRAD_REQ_SIG, R_GRAD_REQ_EXEC), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target_(other.target_){
}
RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this == &other) return (*this);
	this->AForm::operator=(other);
	this->target_ = other.target_;
	return (*this);
}
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	this->AForm::execute(executor);
	if (std::rand() % 2 == 0)
	{
		std::cout << "**Drilling noises** " << this->target_ << " has been robotomized." << std::endl;
	} else {
		throw RobomotizeFailedException();
	}
}

const char* RobotomyRequestForm::RobomotizeFailedException::what() const _GLIBCXX_NOTHROW{
	return "[RobotomizeFailedExeption] Failed to robotomized.";
}