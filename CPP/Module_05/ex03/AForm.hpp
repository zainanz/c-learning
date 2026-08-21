#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	public:
		AForm();
		virtual ~AForm() = 0; // Forcing it to be an abstract class
		AForm(const AForm& other);
		AForm(const std::string& name, const int gradesig, const int gradeexec);
		AForm&	operator=(const AForm& other);

		//getters
		bool				getSigned() const;
		const std::string&	getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

		void				beSigned(const Bureaucrat& b);
		virtual void		execute(Bureaucrat const & executor) const = 0;


		class	GradeTooHighException: public std::exception {
			virtual const char* what() const _GLIBCXX_NOTHROW;
		};
		class	GradeTooLowException: public std::exception {
			virtual const char* what() const _GLIBCXX_NOTHROW;
		};
		class FormNotSignedException: public std::exception {
			virtual const char*	what() const _GLIBCXX_NOTHROW;
		};
	private:
		const std::string	name_;
		const int			gradeSign_;
		const int			gradeExec_;
		bool				signed_;

};
std::ostream&	operator<<(std::ostream& os, const AForm& other);
