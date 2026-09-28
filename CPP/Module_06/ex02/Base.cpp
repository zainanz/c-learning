#include "Base.hpp"
Base::~Base(){
}

Base    *generate(void){
    switch(std::rand() % 3){
        case 1: return new A();
        case 2: return new B();
        default: return new C();
    }
}

void    identify(Base* p){
    Base *ptrs[] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)};
    if (!ptrs[0]) std::cout << "Its A!"<< std::endl;
    else if (!ptrs[1]) std::cout << "Its B!" << std::endl;
    else if (!ptrs[2]) std::cout << "Its C!" << std::endl;
    else std::cout << "Its UNKNOWN!" << std::endl;
}

void    identify(Base& p){
}