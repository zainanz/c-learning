#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("NO_TYPE"){
	std::cout << "** [WrongAnimal] NO_TYPE's strange noise was heard. ** [Default Constructor]" << std::endl;
}
WrongAnimal::~WrongAnimal(){
	std::cout << "[WrongAnimal] " << this->type << " disappeared. [Destructor]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
	std::cout << "[WrongAnimal] " << copy.type << " was cloned. [Copy Constructor]" << std::endl;
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy){
	if (this == &copy) return (*this);
	std::cout << "[WrongAnimal] " << copy.type << " was cloned. [Copy Constructor]" << std::endl;
	this->type = copy.type;
	return (*this);
}
void	WrongAnimal::setType(const std::string& type){
	this->type = type;
}
const std::string&	WrongAnimal::getType(void) const{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal noises!" << std::endl;
}