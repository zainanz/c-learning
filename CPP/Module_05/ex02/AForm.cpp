#include "AForm.hpp"

AForm::AForm(): name_("no_name"), gradeSign_(1), gradeExec_(1), signed_(false){
};

AForm::AForm(const AForm& other): name_(other.name_), gradeSign_(other.gradeSign_), gradeExec_(other.gradeExec_), signed_(other.signed_){
	if (other.gradeSign_ < 1 || other.gradeExec_ < 1) throw AForm::GradeTooHighException();
	if (other.gradeExec_ > 150 || other.gradeSign_ > 150) throw AForm::GradeTooLowException();
}

AForm&	AForm::operator=(const AForm& other){
	// already safe because other exists!
	if (this == &other) return (*this);
	this->signed_ = other.signed_;
	return (*this);
}

AForm::AForm(const std::string& name, const int gradesig, const int gradeexec): name_(name), gradeSign_(gradesig), gradeExec_(gradeexec), signed_(false){
	if (gradesig < 1 || gradeexec < 1) throw AForm::GradeTooHighException();
	if (gradesig > 150 || gradeexec > 150) throw AForm::GradeTooLowException();
}

AForm::~AForm(){
}

const char*	AForm::GradeTooHighException::what() const _GLIBCXX_NOTHROW{
	return "GradeTooLowException: Grade is too high.";
}

const char*	AForm::GradeTooLowException::what() const _GLIBCXX_NOTHROW{
	return "GradeTooHigherException: Grade is too low.";
}

bool	AForm::getSigned() const {
	return this->signed_;
}

const std::string&	AForm::getName() const {
	return this->name_;
}

int	AForm::getGradeExec() const {
	return this->gradeExec_;
}

int AForm::getGradeSign() const {
	return this->gradeSign_;
}

void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() > this->gradeSign_) throw AForm::GradeTooLowException();
	this->signed_ = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& other){
	os << "AForm Details: {name_: " << other.getName() << ", signed_: " << other.getSigned() << ", gradeSign_: " << other.getGradeSign() << 
	", gradeExec_: " << other.getGradeExec() << "}";
	return os;
}