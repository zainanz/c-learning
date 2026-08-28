#include "Form.hpp"
Form::Form(): name_("no_name"), gradeSign_(1), gradeExec_(1), signed_(false){
};

Form::Form(const Form& other): name_(other.name_), gradeSign_(other.gradeSign_), gradeExec_(other.gradeExec_), signed_(other.signed_){
	if (other.gradeSign_ < 1 || other.gradeExec_ < 1) throw Form::GradeTooHighException();
	if (other.gradeExec_ > 150 || other.gradeSign_ > 150) throw Form::GradeTooLowException();
}

Form&	Form::operator=(const Form& other){
	// already safe because other exists!
	if (this == &other) return (*this);
	this->signed_ = other.signed_;
	return (*this);
}

Form::Form(const std::string& name, const int gradesig, const int gradeexec): name_(name), gradeSign_(gradesig), gradeExec_(gradeexec), signed_(false){
	if (gradesig < 1 || gradeexec < 1) throw Form::GradeTooHighException();
	if (gradesig > 150 || gradeexec > 150) throw Form::GradeTooLowException();
}

Form::~Form(){
}

const char*	Form::GradeTooHighException::what() const _GLIBCXX_NOTHROW{
	return "GradeTooHighException: Grade is too high.";
}

const char*	Form::GradeTooLowException::what() const _GLIBCXX_NOTHROW{
	return "GradeTooLowException: Grade is too low.";
}

bool	Form::getSigned() const {
	return this->signed_;
}

const std::string&	Form::getName() const {
	return this->name_;
}

int	Form::getGradeExec() const {
	return this->gradeExec_;
}

int Form::getGradeSign() const {
	return this->gradeSign_;
}

void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() > this->gradeSign_) throw Form::GradeTooLowException();
	this->signed_ = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& other){
	os << "Form Details: {name_: " << other.getName() << ", signed_: " << other.getSigned() << ", gradeSign_: " << other.getGradeSign() << 
	", gradeExec_: " << other.getGradeExec() << "}" << std::endl;
	return os;
}