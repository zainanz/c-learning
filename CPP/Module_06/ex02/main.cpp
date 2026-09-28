#include "Base.hpp"
#include <iostream>

int main(void){
	std::srand(time(NULL));
	Base *x = generate();
	identify(x);
    return 0;
}