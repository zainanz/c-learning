#pragma once
#include "AForm.hpp"

#define GRAD_REQ_SIG 145
#define GRAD_REQ_EXEC 137

class ShrubberyCreationForm: public AForm{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& scf);
		ShrubberyCreationForm(const std::string& target);


		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& scf);
	private:
		std::string	target_;
};