#pragma once

#include "AForm.hpp"
#include <iostream>

#define P_GRAD_REQ_SIG 25
#define P_GRAD_REQ_EXEC 5

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		class RobomotizeFailedException : public std::exception {
			const char* what() const _GLIBCXX_NOTHROW;
		};

		void	execute(Bureaucrat const & executor) const;
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	private:
		std::string	target_;
};