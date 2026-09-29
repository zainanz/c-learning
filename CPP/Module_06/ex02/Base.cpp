#include "Base.hpp"
Base::~Base(){
}

Base    *generate(void){
	// return static_cast<Base *>(new A());
	switch(std::rand() % 3){
        case 1: return static_cast<Base *>(new A());
        case 2: return static_cast<Base *>(new B());
        default: return static_cast<Base *>(new C());
    }
}

void    identify(Base* p){
    if (dynamic_cast<A*>(p)) std::cout << ">>> Type: A *"<< std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << ">>> Type: B *" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << ">>> Type: C *" << std::endl;
    else std::cout << "Its UNKNOWN!" << std::endl;
}

void    identify(Base& p){
    try {
        Base& x = dynamic_cast<A&>(p);
        std::cout << ">>> Type: A&"<< std::endl;
    } catch (...){}
    try {
        Base& x = dynamic_cast<B&>(p);
        std::cout << ">>> Type: B&"<< std::endl;
    } catch (...){}
    try {
        Base& x = dynamic_cast<C&>(p);
        std::cout << ">>> Type: C&"<< std::endl;
    } catch (...){}
}