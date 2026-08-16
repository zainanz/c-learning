#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(): name_("[no-name]"), grade_(150){
}

Bureaucrat::Bureaucrat(const std::string& name): name_(name), grade_(150){
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name){
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	this->grade_ = grade;
}

const std::string	&Bureaucrat::getName(void) const{
	return this->name_;
}


const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "GradeTooLowException: Cannot be lower than 150!\n";
}
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "GradeTooHighException: Cannot be higher than 1!\n";
}

int	Bureaucrat::getGrade(void) const{
	return this->grade_;
}

Bureaucrat::~Bureaucrat(){
}

void	Bureaucrat::gradeUp(){
	if (this->grade_ == 1) throw Bureaucrat::GradeTooHighException();
	this->grade_--;
}

void	Bureaucrat::gradeDown(){
	if (this->grade_ == 150) throw Bureaucrat::GradeTooLowException();
	this->grade_++;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy){
	*this = copy;
}
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy){
	if (this == &copy) return (*this);
	this->name_ = copy.name_;
	this->grade_ = copy.grade_;
	return (*this);
}
std::ostream&	operator<<(std::ostream& os, Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}