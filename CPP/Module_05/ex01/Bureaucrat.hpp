#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		class GradeTooHighException: public std::exception {
			virtual const char* what() const _GLIBCXX_NOTHROW;
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const _GLIBCXX_NOTHROW;
		};

		void				signForm(Form& f);
		void				gradeUp(void);
		void				gradeDown(void);
		Bureaucrat&			operator=(const Bureaucrat& copy);
		const std::string	&getName(void) const;
		int					getGrade(void) const;
	private:
		std::string name_;
		int			grade_;
};
std::ostream& operator<<(std::ostream& os, Bureaucrat& b);