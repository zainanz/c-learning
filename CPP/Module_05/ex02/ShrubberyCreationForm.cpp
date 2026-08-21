#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", S_GRAD_REQ_SIG, S_GRAD_REQ_EXEC), target_("Shrubbery_Default_Form"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", S_GRAD_REQ_SIG, S_GRAD_REQ_EXEC), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target_(other.target_){
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this == &other) return (*this);
	this->AForm::operator=(other);
	this->target_ = other.target_;
	return (*this);
}
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	this->AForm::execute(executor);
	std::string		fname = this->target_ + "_shrubbery";
	std::ofstream	out(fname.c_str());
	out << "            .        +          .      .          ." << std::endl;
	out << "     .            _        .                    ." << std::endl;
	out << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	out << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	out << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
	out << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
	out << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
	out << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
	out << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
	out << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
	out << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
	out << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
	out << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
	out << "                    \\::.  :\\/:'  /              +" << std::endl;
	out << "   .                 `.:.  /:'  }      ." << std::endl;
	out << "           .           ):_(:;   \\           ." << std::endl;
	out << "                      /:. _/ ,  |" << std::endl;
	out << "                   . (|::.     ,`                  ." << std::endl;
	out << "     .                |::.    {\\" << std::endl;
	out << "                      |::.\\  \\ `." << std::endl;
	out << "                      |:::(\\    |" << std::endl;
	out << "              O       |:::/{ }  |                  (o" << std::endl;
	out << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
	out << "          ~~~w/w~\"~~,\\` `:/,-(~\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
	out.close();

	std::cout << this->getName() << " successfully executed the form. [" << this->target_ + "_shrubbery]" << std::endl;
}