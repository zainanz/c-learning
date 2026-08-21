#pragma once
#include "AForm.hpp"
#include <ostream>
#include <fstream>

#define S_GRAD_REQ_SIG 145
#define S_GRAD_REQ_EXEC 137

class ShrubberyCreationForm: public AForm{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& scf);
		ShrubberyCreationForm(const std::string& target);
		
		void					execute(Bureaucrat const & executor) const;
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& scf);
	private:
		std::string	target_;
};