#pragma once

#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	public:
		Form();
		~Form();
		Form(const Form& other);
		Form(const std::string& name, const int gradesig, const int gradeexec);
		Form&	operator=(const Form& other);

		//getters
		bool				getSigned() const;
		const std::string&	getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

		void				beSigned(const Bureaucrat& b);


		class	GradeTooHighException: public std::exception {
			virtual const char* what() const _GLIBCXX_NOTHROW;
		};
		class	GradeTooLowException: public std::exception {
			virtual const char* what() const _GLIBCXX_NOTHROW;
		};
	private:
		const std::string	name_;
		const int			gradeSign_;
		const int			gradeExec_;
		bool				signed_;

};
std::ostream&	operator<<(std::ostream& os, const Form& other);
