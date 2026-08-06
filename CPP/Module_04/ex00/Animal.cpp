#include "Animal.hpp"

Animal::Animal(): type("NO_TYPE"){
	std::cout << "** [Animal] NO_TYPE's strange noise was heard. ** [Default Constructor]" << std::endl;
}
Animal::~Animal(){
	std::cout << "[Animal] " << this->type << " disappeared. [Destructor]" << std::endl;
}

Animal::Animal(const Animal& copy){
	std::cout << "[Animal] " << copy.type << " was cloned. [Copy Constructor]" << std::endl;
	*this = copy;
}

Animal&	Animal::operator=(const Animal& copy){
	if (this == &copy) return (*this);
	std::cout << "[Animal] " << copy.type << " was cloned. [Copy Constructor]" << std::endl;
	this->type = copy.type;
	return (*this);
}
void	Animal::setType(const std::string& type){
	this->type = type;
}
const std::string&	Animal::getType(void) const{
	return (this->type);
}

void	Animal::makeSound(void) const{
	std::cout << "Animal noises!" << std::endl;
}