#include "Base.hpp"
Base::~Base(){
}

Base    *generate(void){
	switch(std::rand() % 3){
        case 1: return static_cast<Base *>(new A());
        case 2: return static_cast<Base *>(new B());
        default: return static_cast<Base *>(new C());
    }
}

void    identify(Base* p){
	if (!p) std::cout << "ptr is NULL" << std::endl;
    else if (dynamic_cast<A*>(p)) std::cout << ">>> Type: A *"<< std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << ">>> Type: B *" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << ">>> Type: C *" << std::endl;
    else std::cout << "Its UNKNOWN!" << std::endl;
}

void    identify(Base& p){
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << ">>> Type: A&"<< std::endl;
		return ;
    } catch (...){}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << ">>> Type: B&"<< std::endl;
		return ;
    } catch (...){}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << ">>> Type: C&"<< std::endl;
		return ;
    } catch (...){}
    std::cout << ">>> Type: Unknown&"<< std::endl;
}