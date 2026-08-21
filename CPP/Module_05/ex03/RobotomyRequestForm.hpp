#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

#define R_GRAD_REQ_SIG 72
#define R_GRAD_REQ_EXEC 45

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		class RobomotizeFailedException : public std::exception {
			const char* what() const _GLIBCXX_NOTHROW;
		};

		void	execute(Bureaucrat const & executor) const;
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	private:
		std::string	target_;
};