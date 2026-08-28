#pragma once
#include <ostream>

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

		void				gradeUp(void);
		void				gradeDown(void);
		Bureaucrat&			operator=(const Bureaucrat& copy);
		const std::string	&getName(void) const;
		int					getGrade(void) const;
	private:
		const std::string	name_;
		int					grade_;
};
std::ostream& operator<<(std::ostream& os, Bureaucrat& b);